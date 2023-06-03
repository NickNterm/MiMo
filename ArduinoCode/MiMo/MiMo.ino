#include <U8glib.h>
#include <Encoder.h>
#include "icons.h"
#include "dcube.h"

// Initialize the Encoder
Encoder myEnc(2, 3);

// Initialize the I2C OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);  // Fast I2C / TWI

// The Index of the element that i currently show in menu
int elementPageIndex = 0;

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

// Menu UI
void drawMenuUI(void) {
  // Calculate Indexes
  int prevIndex = elementPageIndex - 1;
  int nextIndex = elementPageIndex + 1;
  if (elementPageIndex - 1 < 0) {
    prevIndex = menu_icon_allArray_LEN - 1;
  }
  if (elementPageIndex + 1 == menu_icon_allArray_LEN) {
    nextIndex = 0;
  }
  // Create the first page
  u8g.firstPage();
  do {
    // Draw ScrollBar
    u8g.drawBitmapP(120, 0, 8 / 8, 64, scrollBar);
    u8g.drawBox(125, (elementPageIndex)*64 / 12, 3, 6);

    // Draw Selection UP
    u8g.drawBitmapP(2, 2, 16 / 8, 16, menu_icon_allArray[prevIndex]);
    u8g.setFont(u8g_font_7x14);
    u8g.drawStr(22, 15, menu_icon_label[prevIndex]);

    // Draw Selected
    u8g.setFont(u8g_font_7x14B);
    u8g.drawBitmapP(0, 22, 128 / 8, 20, selectedElement);
    u8g.drawBitmapP(2, 24, 16 / 8, 16, menu_icon_allArray[elementPageIndex]);
    u8g.drawStr(22, 37, menu_icon_label[elementPageIndex]);

    // Draw Selection DOWN
    u8g.setFont(u8g_font_7x14);
    u8g.drawBitmapP(2, 46, 16 / 8, 16, menu_icon_allArray[nextIndex]);
    u8g.drawStr(22, 59, menu_icon_label[nextIndex]);
  } while (u8g.nextPage());
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
      elementPageIndex++;
      if (elementPageIndex == menu_icon_allArray_LEN) {
        elementPageIndex = 0;
      }
    } else {
      // Decrement
      elementPageIndex--;
      if (elementPageIndex == -1) {
        elementPageIndex = menu_icon_allArray_LEN - 1;
      }
    }
    // Set old Position
    oldPosition = myEnc.read();
  }
  // If is firstClick and the time is up 
  if (swReleaseTime + swDoubleTapTimeBetween < millis() && isFirstClick) {
    // register a single click
    if (nowShowing == "Menu") {
      nowShowing = menu_icon_label[elementPageIndex];
    }
    isFirstClick = false;
  }

  // Show the right screen
  if (nowShowing == "Menu") {
    drawMenuUI();
  } else if (nowShowing == "3DCube") {
    draw3DCube(u8g);
  } else if (nowShowing == "Battery") {
    draw3DCube(u8g);
  } else {
    u8g.firstPage();
    do {
      drawDefault();
    } while (u8g.nextPage());
  }
  delay(50);
}