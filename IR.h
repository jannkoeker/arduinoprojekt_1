#ifndef _IR_H
#define _IR_H

enum KeyCodes {
  KEY_POWER = 0x45,
  KEY_FUNC_STOP = 0x47,
  KEY_VOL_ADD = 0x46,
  KEY_FAST_BACK = 0x44,
  KEY_PAUSE = 0x40,
  KEY_FAST_FORWARD = 0x43,
  KEY_DOWN = 0x07,
  KEY_VOL_DE = 0x15,
  KEY_UP = 0x09,
  KEY_EQ = 0x19,
  KEY_ST_REPT = 0x0D,
  KEY_0 = 0x16,
  KEY_1 = 0x0C,
  KEY_2 = 0x18,
  KEY_3 = 0x5E,
  KEY_4 = 0x08,
  KEY_5 = 0x1C,
  KEY_6 = 0x5A,
  KEY_7 = 0x42,
  KEY_8 = 0x52,
  KEY_9 = 0x4A
};

#define KEY_NUM 21
#define S_REPEAT 22

KeyCodes keyValue[] = { KEY_POWER, KEY_FUNC_STOP, KEY_VOL_ADD, KEY_FAST_BACK, KEY_PAUSE, KEY_FAST_FORWARD,
                             KEY_DOWN, KEY_VOL_DE, KEY_UP, KEY_EQ, KEY_ST_REPT, KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5,
                             KEY_6, KEY_7, KEY_8, KEY_9 };

char keyBuf[][15] = { "POWER", "FUNC/STOP", "VOL+", "FAST BACK", "PAUSE", "FAST FORWARD", "DOWN", "VOL-",
                      "UP", "EQ", "ST/REPT", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
#endif