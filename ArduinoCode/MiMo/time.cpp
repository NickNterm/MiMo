#include "time.h"

static String buffer;

static int progress = 10;
static char* time = "00:00";
static char* day = "Monday";
static char* date = "00/00/00";

void drawTime( U8GLIB_SSD1306_128X64 u8g ){
  if(Serial.available() > 0){
    char c = Serial.read();// Read the next character
    // If it is \n 
    if (c == '\n'){
      time = strtok(buffer.c_str(), ",");
      day = strtok(NULL, ",");
      date = strtok(NULL, "");
      Serial.println("Time");
      //Reset the buffer
      buffer = "";
    }
    else
    {
      buffer += c;
    }
  }
  
  u8g.firstPage();
  do {
      u8g.setFont(u8g_font_10x20);
      int width = u8g.getStrWidth(String(time).c_str());
      u8g.drawStr((128-width)/2, 22,String(time).c_str());
      u8g.setFont(u8g_font_9x15);
      u8g.drawLine(35, 27, 93, 27);
      width = u8g.getStrWidth(String(day).c_str());
      u8g.drawStr((128-width)/2, 42,String(day).c_str());
      width = u8g.getStrWidth(String(date).c_str());
      u8g.drawStr((128-width)/2, 62,String(date).c_str());
  } while (u8g.nextPage());
  //u8g.drawBitmapP(32, 38, 64 / 8, 20, battery_batteryProgress);
}
