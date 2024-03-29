#include "icons.h"
#include <avr/pgmspace.h>

// ' 3DCube', 16x16px
const unsigned char menu_icon_3DCube [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x30, 0x0c, 0x28, 0x14, 0x27, 0xe4, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x27, 0xe4, 0x28, 0x14, 0x30, 0x0c, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00
};
// ' 96Icon', 16x16px
const unsigned char menu_icon_96Icon [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x3e, 0x7c, 0x22, 0x40, 0x22, 0x40, 0x22, 0x40, 0x3e, 0x7c, 0x02, 0x44, 
	0x02, 0x44, 0x02, 0x44, 0x3e, 0x7c, 0x00, 0x00, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00
};
// ' Analiser', 16x16px
const unsigned char menu_icon_Analiser [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x06, 0xc0, 0x00, 0xc0, 0x36, 0xd8, 
	0x06, 0xc0, 0x36, 0xd8, 0x36, 0xd8, 0x00, 0x00, 0x7f, 0xfe, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00
};
// ' CPU', 16x16px
const unsigned char menu_icon_CPU [] PROGMEM = {
	0x00, 0x00, 0x05, 0xa0, 0x05, 0xa0, 0x0f, 0xf0, 0x18, 0x18, 0x70, 0x0e, 0x13, 0xc8, 0x72, 0x4e, 
	0x72, 0x4e, 0x13, 0xc8, 0x70, 0x0e, 0x18, 0x18, 0x0f, 0xf0, 0x05, 0xa0, 0x05, 0xa0, 0x00, 0x00
};
// ' GPU', 16x16px
const unsigned char menu_icon_GPU [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x3f, 0xfc, 0x30, 0x0c, 0x35, 0xac, 0x30, 0x0c, 0x35, 0xac, 
	0x35, 0xac, 0x30, 0x0c, 0x35, 0xac, 0x30, 0x0c, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00
};
// ' Network', 16x16px
const unsigned char menu_icon_Network [] PROGMEM = {
	0x00, 0x00, 0x10, 0x08, 0x21, 0x84, 0x4b, 0xd2, 0x53, 0xca, 0x53, 0xca, 0x4b, 0xd2, 0x23, 0xc4, 
	0x13, 0xc8, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x01, 0x80, 0x00, 0x00
};
// ' Temp', 16x16px
const unsigned char menu_icon_Temp [] PROGMEM = {
	0x00, 0x00, 0x00, 0x10, 0x1c, 0x28, 0x20, 0x28, 0x20, 0x28, 0x20, 0x28, 0x1c, 0x28, 0x00, 0x38, 
	0x00, 0x38, 0x1c, 0x38, 0x20, 0x38, 0x2c, 0x7c, 0x24, 0x7c, 0x1c, 0x7c, 0x00, 0x38, 0x00, 0x00
};
// ' Time', 16x16px
const unsigned char menu_icon_Time [] PROGMEM = {
	0x00, 0x00, 0x03, 0xc0, 0x0c, 0x30, 0x10, 0x08, 0x20, 0x14, 0x44, 0x22, 0x42, 0x42, 0x41, 0x82, 
	0x41, 0x82, 0x40, 0x02, 0x40, 0x02, 0x20, 0x04, 0x10, 0x08, 0x08, 0x10, 0x07, 0xe0, 0x00, 0x00
};
// ' Volume', 16x16px
const unsigned char menu_icon_Volume [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 0xc4, 0x03, 0x42, 0x7e, 0x52, 0x40, 0x4a, 0x40, 0x4a, 
	0x40, 0x4a, 0x40, 0x4a, 0x7e, 0x52, 0x03, 0x42, 0x01, 0xc4, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00
};
// ' Weather', 16x16px
const unsigned char menu_icon_Weather [] PROGMEM = {
	0x00, 0x00, 0x02, 0x40, 0x11, 0x88, 0x33, 0xcc, 0x09, 0x90, 0x05, 0xa0, 0x52, 0x4a, 0x3d, 0xbc, 
	0x3d, 0xbc, 0x52, 0x4a, 0x05, 0xa0, 0x09, 0x90, 0x33, 0xcc, 0x11, 0x88, 0x02, 0x40, 0x00, 0x00
};
// ' scrollBar', 8x64px
const unsigned char scrollBar [] PROGMEM = {
	0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 
	0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 
	0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 
	0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02
};
// ' MuteIcon', 16x16px
const unsigned char volume_MuteIcon [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x06, 0x80, 0xfc, 0xa2, 0x80, 0x94, 0x80, 0x88, 
	0x80, 0x94, 0x80, 0xa2, 0xfc, 0x80, 0x06, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// ' dowloadIcon', 16x16px
const unsigned char network_dowloadIcon [] PROGMEM = {
	0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x21, 0x84, 0x71, 0x8e, 
	0x39, 0x9c, 0x1d, 0xb8, 0x0f, 0xf0, 0x07, 0xe0, 0x03, 0xc0, 0x01, 0x80, 0x00, 0x00, 0x7f, 0xfe
};
// ' uploadIcon', 16x16px
const unsigned char network_uploadIcon [] PROGMEM = {
	0x01, 0x80, 0x03, 0xc0, 0x07, 0xe0, 0x0f, 0xf0, 0x1d, 0xb8, 0x39, 0x9c, 0x71, 0x8e, 0x21, 0x84, 
	0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x7f, 0xfe
};
// ' SelectedElement', 128x20px
const unsigned char selectedElement [] PROGMEM = {
	0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x40, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x20, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x20, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x40, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 
	0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 992)
const int menu_icon_allArray_LEN = 10;
const unsigned char* menu_icon_allArray[10] = {
	menu_icon_3DCube,
	menu_icon_96Icon,
	menu_icon_Analiser,
	menu_icon_CPU,
	menu_icon_GPU,
	menu_icon_Network,
	menu_icon_Temp,
	menu_icon_Time,
	menu_icon_Volume,
	menu_icon_Weather
};
const unsigned char* menu_icon_label[10] = {
	"3DCube",
	"Slang Quotes",
	"Analiser",
	"CPU Usage",
	"GPU Usage",
	"Network",
	"Temprature",
	"Time",
	"Volume",
	"Weather"
};
