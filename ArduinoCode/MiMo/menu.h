#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include <string.h>
#include "U8glib.h"
#include "icons.h"


void drawMenu( U8GLIB_SSD1306_128X64 u8g );

void menuEncoderPlus( void );

void menuEncoderMinus( void );

int getElementPageIndex( void );

#endif
