#ifndef _IR_H
#define _IR_H

enum KeyCodes {
  KEY_POWER = 0xFFA25D,
  KEY_FUNC_STOP = 0xFFE21D,
  KEY_VOL_ADD = 0xFF629D,
  KEY_FAST_BACK = 0xFF22DD,
  KEY_PAUSE = 0xFF02FD,
  KEY_FAST_FORWARD = 0xFFC23D,
  KEY_DOWN = 0xFFE01F,
  KEY_VOL_DE = 0xFFA857,
  KEY_UP = 0xFF906F,
  KEY_EQ = 0xFF9867,
  KEY_ST_REPT = 0xFFB04F,
  KEY_0 = 0xFF6897,
  KEY_1 = 0xFF30CF,
  KEY_2 = 0xFF18E7,
  KEY_3 = 0xFF7A85,
  KEY_4 = 0xFF10EF,
  KEY_5 = 0xFF38C7,
  KEY_6 = 0xFF5AA5,
  KEY_7 = 0xFF42BD,
  KEY_8 = 0xFF4AB5,
  KEY_9 = 0xFF52AD,
  KEY_REPEAT = 0xFFFFFFFF
};

#define KEY_NUM 21
#define S_REPEAT 22

KeyCodes keyValue[] = { KEY_POWER, KEY_FUNC_STOP, KEY_VOL_ADD, KEY_FAST_BACK, KEY_PAUSE, KEY_FAST_FORWARD,
                        KEY_DOWN, KEY_VOL_DE, KEY_UP, KEY_EQ, KEY_ST_REPT, KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5,
                        KEY_6, KEY_7, KEY_8, KEY_9 };

char keyBuf[][15] = { "POWER", "FUNC/STOP", "VOL+", "FAST BACK", "PAUSE", "FAST FORWARD", "DOWN", "VOL-",
                      "UP", "EQ", "ST/REPT", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
#endif