#ifndef DEVICES_H
#define DEVICES_H

#include <LiquidCrystal_74HC595.h>
#include <IRremote.hpp>
#include <SPI.h>
#include <MFRC522.h>
#include "pitches.h"
#include <SR04.h>

#define TRIG_PIN 5
#define ECHO_PIN 4 
#define RST_PIN  9     // Configurable, see typical pin layout above
#define SS_PIN   10    // Configurable, see typical pin layout above
#define RECEIVER 2

namespace Dev{
  LiquidCrystal_74HC595 lcd(6, 8, 7, 1, 3, 4, 5, 6, 7);

  MFRC522 mfrc522(SS_PIN, RST_PIN);
  MFRC522::MIFARE_Key key;


  SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
}

#endif // DEVICES_H