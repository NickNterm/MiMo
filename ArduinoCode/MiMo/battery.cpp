#include "battery.h"

void drawBattery( U8GLIB_SSD1306_128X64 u8g ){
  u8g.setFont(u8g_font_7x14);
  u8g.drawStr(22, 15, menu_icon_label[prevIndex]);
}