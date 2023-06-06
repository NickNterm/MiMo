#ifndef GRAPH_H
#define GRAPH_H

#include <Arduino.h>
#include <U8glib.h>

#define GRAPH_NUM_OF_POINTS 30

void drawGraph( U8GLIB_SSD1306_128X64 u8g, String title );

#endif
