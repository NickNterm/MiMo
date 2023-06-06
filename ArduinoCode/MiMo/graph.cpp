#include "graph.h"


static int points[GRAPH_NUM_OF_POINTS]= {
    10, 20, 12, 34, 45, 52, 36, 22, 12, 10,
    10,  8, 12, 15, 35, 56, 67, 82, 55, 23,
    12, 20, 22, 23, 24, 32, 43, 44, 47, 44,
}; 

// Graph Height = 62-20 = 42
static int graph_height = 42;
static int graph_width = 100;
static String buffer;

void addPoint(int npoint){
    for(int i = 0; i < GRAPH_NUM_OF_POINTS - 1; i++){
        points[i] = points[i+1];
    }
    points[GRAPH_NUM_OF_POINTS - 1] = npoint;
}

void drawGraph( U8GLIB_SSD1306_128X64 u8g, String title ){
    if(Serial.available() > 0){
        buffer = Serial.readString();
        buffer.trim();
        if(buffer.length() > 0){
            addPoint(buffer.toInt());
        }
        Serial.println("Graph"+title);
    }
    u8g.firstPage();
    do{
        u8g.setFont(u8g_font_7x14);
        int strWidth = u8g.getStrWidth(title.c_str());
        u8g.drawStr((128 - strWidth) / 2, 15, title.c_str());
        u8g.setFont(u8g_font_04b_03);

        // Horizontal bottom line
        u8g.drawLine(15, 20, 15, 62);

        // Vertical left line
        u8g.drawLine(15, 62, 120, 62);

        // Graph Labels
        u8g.drawStr(0, 22, "100");
        u8g.drawStr(3, 44, "50");
        u8g.drawStr(8, 64, "0");

        // Graph vertical ticks
        for(int i = 0; i <= GRAPH_NUM_OF_POINTS; i=i+3){
            u8g.drawLine(15 + (i * graph_width/GRAPH_NUM_OF_POINTS), 62, 15 + (i * graph_width/GRAPH_NUM_OF_POINTS), 64);
        }

        // Graph horizontal ticks
        u8g.drawLine(13, 20, 15, 20);
        u8g.drawLine(13, 41, 15, 41);
        u8g.drawLine(13, 62, 15, 62);

        // Draw lines
        for(int i = 1; i < GRAPH_NUM_OF_POINTS; i++){
            u8g.drawLine(15 + ((i-1) * graph_width/GRAPH_NUM_OF_POINTS), 62 - (points[i-1] * graph_height/100), 15 + (i * graph_width/GRAPH_NUM_OF_POINTS), 62 - (points[i] * graph_height/100));
        }
    }while(u8g.nextPage());
}

