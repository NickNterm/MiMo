#ifndef VOLUME_H
#define VOLUME_H

#include <Arduino.h>
#include <string.h>
#include "U8glib.h"
#include "icons.h"

void drawVolume( U8GLIB_SSD1306_128X64 u8g );

void volumeEncoderPlus( void );

void volumeEncoderMinus( void );

void volumeEncoderClick( void );
#endif
