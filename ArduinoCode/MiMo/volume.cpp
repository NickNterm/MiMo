#include "volume.h"

static int volume = 0;
static int volumeMute = 0;
static String buffer;

void drawVolume(U8GLIB_SSD1306_128X64 u8g) {
  // read the volume
  if (Serial.available() > 0) {
    char c = Serial.read();  // Read the next character
    // If it is \n
    if (c == '\n') {
      // Here is all the data in the buffer
      char* token = strtok(buffer.c_str(), ",");
      volume = String(token).toInt();
      token = strtok(NULL, ",");
      volumeMute = String(token).toInt();
      // Reset buffer
      buffer = "";
    } else {
      buffer += c;
    }
  }

  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_7x14);
    int strWidth = u8g.getStrWidth("Volume");
    u8g.drawStr((128 - strWidth) / 2, 15, "Volume");
    if (volumeMute == 0) {
      u8g.drawBitmapP((128 - 16) / 2, 20, 16 / 8, 16, menu_icon_Volume);
    } else {
      u8g.drawBitmapP((128 - 16) / 2, 20, 16 / 8, 16, volume_MuteIcon);
    }
    u8g.drawRFrame(10, 40, 108, 20, 3);
    int volumeWidth = map(volume, 0, 100, 0, 104);
    u8g.drawBox(12, 43, volumeWidth, 14);
    if (volumeWidth >= 2) {
      u8g.drawBox(13, 42, volumeWidth - 2, 16);
    }

  } while (u8g.nextPage());
}

void volumeEncoderPlus(void) {
  volume = volume + 2;
  if (volume > 100) {
    volume = 100;
  }
  Serial.println("Volume=" + String(volume));
}

void volumeEncoderMinus(void) {
  volume = volume - 2;
  if (volume < 0) {
    volume = 0;
  }
  Serial.println("Volume=" + String(volume));
}

void volumeEncoderClick(void) {
  if (volumeMute == 0) {
    volumeMute = 1;
    Serial.println("Volume=" + String(volume));
  } else {
    volumeMute = 0;
    Serial.println("Volume=0");
  }
}
