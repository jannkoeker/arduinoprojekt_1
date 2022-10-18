#include <IRremote.h>
#include <Array.h>
#include "devices.h"
#include "IR.h"

using Password = Array<int, 4>;

Password buffer;
Password password;

bool alarmIsActive = false;
long startTime= 0;
bool initialize=true;
long initPhaseMS = 10000;
long deactivateTimeout = 0;

int mapKeycodes(unsigned long code) {
  switch (code) {
    case KEY_POWER:
      return -1;
    case KEY_FUNC_STOP:
      return -2;
    case KEY_VOL_ADD:
      return -3;
    case KEY_FAST_BACK:
      return -4;
    case KEY_PAUSE:
      return -5;
    case KEY_FAST_FORWARD:
      return -6;
    case KEY_DOWN:
      return -7;
    case KEY_VOL_DE:
      return -8;
    case KEY_UP:
      return -9;
    case KEY_EQ:
      return -10;
    case KEY_ST_REPT:
      return -11;
    case KEY_0:
      return 0;
    case KEY_1:
      return 1;
    case KEY_2:
      return 2;
    case KEY_3:
      return 3;
    case KEY_4:
      return 4;
    case KEY_5:
      return 5;
    case KEY_6:
      return 6;
    case KEY_7:
      return 7;
    case KEY_8:
      return 8;
    case KEY_9:
      return 9;
  }
}

void setAlarmActive(bool active) {
  alarmIsActive = active;
  Dev::lcd.clear();
  buffer.clear();
  startTime = millis();
  if (active) {
    Dev::lcd.print("Activated");
    Serial.println("Activated");
  } else {
    Dev::lcd.print("Deactivated");
    Serial.println("Deactivated");
  }
}

void setAlarmDuration(){
  long duration = 0;
  for(int i = 0 ; i< buffer.size(); i++){
    duration *= 10;
    duration += buffer[i];
  }
  buffer.clear();
  Dev::lcd.clear();
  Dev::lcd.print("Set Timeout to");
  Dev::lcd.setCursor(0,1);
  Dev::lcd.print(duration);
  Dev::lcd.print(" hours");
  Serial.print("Set Timeout to ");
  Serial.print(duration);
  Serial.println(" hours");

  duration *= 3600000; // ms pro h
  deactivateTimeout = duration;
}

bool passwordIsValid(const Password& value) {
  if (value.size() < 4) {
    return false;
  }
  for (int i = 0; i < buffer.size(); i++) {
    Serial.print(value[i]);
    Serial.print(" = ");
    Serial.println(password[i]);
    if (value[i] != password[i]) {
      return false;
    }
  }
  return true;
}

void handleCommand(unsigned long keycode) {
  switch (keycode) {
    case -1:
      {  //Power Button
        if (!alarmIsActive) {
          setAlarmActive(true);
          break;
        }
        if (passwordIsValid(buffer)) {
          setAlarmActive(false);
        } else if (!buffer.empty()) {
          Dev::lcd.clear();
          Serial.println("Inv Password after power");
          Dev::lcd.print("Invalid Password");
        }
        break;
      }
    case -2:
      {  // Func/Stop Button
        Dev::lcd.clear();
        if (!alarmIsActive) {
          if (buffer.full()) {
            Dev::lcd.print("Password set");
            password = buffer;
          } else {
            Serial.println("Inv Password after set");
            Dev::lcd.print("Invalid Password");
          }
        } else {
          Dev::lcd.print("Not allowed");
        }
        break;
      }
    case -11:
    {
      setAlarmDuration();
      break;
    }
    default:
      Dev::lcd.setCursor(0, 1);
      Dev::lcd.print("                  ");
      buffer.clear();
      break;
  }
  buffer.clear();
}

void setup() {
  password.push_back(1);
  password.push_back(2);
  password.push_back(3);
  password.push_back(4);
  Serial.begin(115200);
  IrReceiver.begin(RECEIVER, ENABLE_LED_FEEDBACK);  // onboard LED blinks with received IR signal
  Dev::lcd.begin(16, 2);
  Dev::lcd.clear();
  setAlarmActive(false);
  deactivateTimeout = 0;
  initialize = true; 
}

void loop() {
  long time = millis();
  if(initialize && time > startTime+initPhaseMS){
    initialize = false;
    setAlarmDuration();
    setAlarmActive(true);
  }
  if(deactivateTimeout > 0 && time > startTime+deactivateTimeout){
    setAlarmActive(false);
  }
  do {
    Dev::lcd.setCursor(buffer.size(), 1);
    if (IrReceiver.decode()) {
      unsigned long keycode = IrReceiver.decodedIRData.command;
      
      if ((IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT))  // ignore repeat code
      {
        IrReceiver.resume();
        break;
      }
      IrReceiver.resume();
      int key = mapKeycodes(keycode);
      Serial.println(key);

      if (key >= 0 && !buffer.full()) {
        buffer.push_back(key);
        Dev::lcd.print(key);
      } else if (key < 0) {
        handleCommand(key);
      } else {
        Dev::lcd.setCursor(0, 1);
        Dev::lcd.print("                  ");
        buffer.clear();
      }
    }
  } while (false);

  if (alarmIsActive) {
    long a = Dev::sr04.Distance();
    if (a < 80) {
      tone(3, NOTE_C4, 100);
      delay(constrain(60 * a,100,1000));
    }
  }
}