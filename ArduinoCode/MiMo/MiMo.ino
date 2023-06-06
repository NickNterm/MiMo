#include <U8glib.h>
#include <Encoder.h>
#include "dcube.h"
#include "menu.h"
#include "graph.h"
#include "battery.h"
#include "icons.h"
#include "volume.h"

// Initialize the Encoder
Encoder myEnc(2, 3);

// Initialize the I2C OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);  // Fast I2C / TWI


// This is the Screen that we show
String nowShowing = "Menu";

// The Encoder Position
long oldPosition = -999;

// The Time that I release the switch
long swReleaseTime = 0;

// Time Between Double Click
int swDoubleTapTimeBetween = 300;

// The Boolean that checks if the button press
// is the first click and not the double click
boolean isFirstClick = false;

// The Default Screen
void drawDefault(void) {
  u8g.setFont(u8g_font_7x14B);
  u8g.drawStr(0, 10, "This feature is not implemented yet");
}

// Setup Function
void setup(void) {
  // Create an interrupt for group 2
  PCICR |= B00000100;

  // For Group 2 watch the interrupt for D4
  PCMSK2 |= B00010000;

  // Start Serial
  Serial.begin(9600);

  // Start Screen
  u8g.setColorIndex(1);

  // Read encoder first position
  oldPosition = myEnc.read();
}

// Here comes the interrupts for pins in the group 2
ISR(PCINT2_vect) {
  // Check if the Sw is pressed
  if (PIND & B00010000) {
    // Set that its the first Click
    isFirstClick = true;
    if (swReleaseTime + swDoubleTapTimeBetween > millis()) {
      // If the time is valid then it's
      // a double click
      // double tap is sucessful
      isFirstClick = false;

      // Double Click Function
      if (nowShowing != "Menu") {
        nowShowing = "Menu";
      }
    }
  } else if (!(PIND & B00010000)) {
    // when i release
    // set the ReleaseTime
    swReleaseTime = millis();
  }
}



void loop(void) {
  // If there are 4 divisions diff then rotary changed
  if (abs(myEnc.read() - oldPosition) >= 4) {
    // Set new Position
    long newPosition = myEnc.read();
    if (oldPosition > newPosition) {
      // Increment
      if (nowShowing == "Menu") {
        menuEncoderMinus();
      }else if(nowShowing == "Volume"){
        volumeEncoderMinus();
      }
    } else {
      // Decrement
      if (nowShowing == "Menu") {
        menuEncoderPlus();
      }else if(nowShowing == "Volume"){
        volumeEncoderPlus();
      }
    }
    // Set old Position
    oldPosition = myEnc.read();
  }
  // If is firstClick and the time is up
  if (swReleaseTime + swDoubleTapTimeBetween < millis() && isFirstClick) {
    // register a single click
    if (nowShowing == "Menu") {
      nowShowing = menu_icon_label[getElementPageIndex()];
      Serial.println(nowShowing);
    } else if (nowShowing == "Volume") {
      volumeEncoderClick();
    }
    isFirstClick = false;
  }

  // Show the right screen
  if (nowShowing == "Menu") {
    drawMenu(u8g);
  } else if (nowShowing == "3DCube") {
    draw3DCube(u8g);
  } else if (nowShowing == "Battery") {
    drawBattery(u8g);
  } else if (nowShowing == "Volume") {
    drawVolume(u8g);
  } else if (nowShowing == "GPU Usage") {
    drawGraph(u8g, "GPU");
  } else if (nowShowing == "CPU Usage") {
    drawGraph(u8g, "CPU");
  } else {
    u8g.firstPage();
    do {
      drawDefault();
    } while (u8g.nextPage());
  }
}
