#include "battery.h"

static String buffer;

static int progress = 10;

void drawBattery( U8GLIB_SSD1306_128X64 u8g ){
  if(Serial.available() > 0){
    char c = Serial.read();// Read the next character
    // If it is \n 
    if (c == '\n'){
      // Here is all the data in the buffer
      progress = buffer.toInt();
      // Reset buffer
      buffer = "";
      Serial.println("Battery");
    }
    else
    {
      buffer += c;
    }
  }
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_7x14);
    String progressString = String(progress) + "%";
    int strWidth = u8g.getStrPixelWidth("Battery Level");
    u8g.drawStr((128 - strWidth)/2, 12, "Battery Level");
    strWidth = u8g.getStrPixelWidth(progressString.c_str());
    u8g.drawStr((128 - strWidth)/2, 31, progressString.c_str());
    u8g.drawBitmapP(32, 38, 64/8, 20, battery_batteryProgress);
    u8g.drawBox(39, 41, map(progress, 0, 100, 0, 50),14);
  } while (u8g.nextPage());
  //u8g.drawBitmapP(32, 38, 64 / 8, 20, battery_batteryProgress);
}