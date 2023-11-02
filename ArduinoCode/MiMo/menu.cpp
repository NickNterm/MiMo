#include "menu.h"

static int elementPageIndex = 7;
static int prevIndex = menu_icon_allArray_LEN - 1;
static int nextIndex = 1;

int getElementPageIndex(void) {
  return elementPageIndex;
}

void updateNextPrev(void) {
  nextIndex = elementPageIndex + 1;
  prevIndex = elementPageIndex - 1;
  if (elementPageIndex - 1 < 0) {
    prevIndex = menu_icon_allArray_LEN - 1;
  }
  if (elementPageIndex == menu_icon_allArray_LEN - 1) {
    nextIndex = 0;
  }
}

void drawMenu(U8GLIB_SSD1306_128X64 u8g) {
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

void menuEncoderPlus(void) {
  elementPageIndex++;
  if (elementPageIndex == menu_icon_allArray_LEN) {
    elementPageIndex = 0;
  }
  updateNextPrev();
}

void menuEncoderMinus(void) {
  elementPageIndex--;
  if (elementPageIndex == -1) {
    elementPageIndex = menu_icon_allArray_LEN - 1;
  }
  updateNextPrev();
}
