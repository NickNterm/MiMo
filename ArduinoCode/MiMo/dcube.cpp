#include "dcube.h"

int points[8][2];  // eight 2D points for the cube, values will be calculated in the code


int orig_points[8][3] = {  // eight 3D points - set values for 3D cube
  { -1, -1, 1 },
  { 1, -1, 1 },
  { 1, 1, 1 },
  { -1, 1, 1 },
  { -1, -1, -1 },
  { 1, -1, -1 },
  { 1, 1, -1 },
  { -1, 1, -1 }
};

float rotated_3d_points[8][3];  // eight 3D points - rotated around Y axis
float angle_deg = 60.0;         // rotation around the Y axis
float z_offset = -4.0;          // offset on Z axis
float cube_size = 70.0;         // cube size (multiplier)
float time_frame;               // ever increasing time value

void draw3DCube(U8GLIB_SSD1306_128X64 u8g) {
  time_frame++;                                 // increase the time frame value by 1
  cube_size = 50 + sin(time_frame * 0.2) * 20;  // oscilate cube size between values 30 - 70

  //z_offset =  -2.0;    //
  //cube_size = 18.0;    // uncomment those two lines for a "wide angle camera" -- bigger perspective distort

  // increase the angle by 5° increments
  if (angle_deg < 90 - 5) {
    angle_deg = angle_deg + 5;
  } else {
    angle_deg = 0;
  }

  // calculate the points
  for (int i = 0; i < 8; i++) {
    // rotate 3d points around the Y axis (rotating X nad Z positions)
    rotated_3d_points[i][0] = orig_points[i][0] * cos(radians(angle_deg)) - orig_points[i][2] * sin(radians(angle_deg));
    rotated_3d_points[i][1] = orig_points[i][1];
    rotated_3d_points[i][2] = orig_points[i][0] * sin(radians(angle_deg)) + orig_points[i][2] * cos(radians(angle_deg)) + z_offset;

    // project 3d points into 2d space with perspective divide -- 2D x = x/z,   2D y = y/z
    points[i][0] = round(64 + rotated_3d_points[i][0] / rotated_3d_points[i][2] * cube_size);
    points[i][1] = round(32 + rotated_3d_points[i][1] / rotated_3d_points[i][2] * cube_size);
  }


  u8g.firstPage();
  do {
    // connect the lines between the individual points
    u8g.drawLine(points[0][0], points[0][1], points[1][0], points[1][1]);  // connect points 0-1
    u8g.drawLine(points[1][0], points[1][1], points[2][0], points[2][1]);  // connect points 1-2
    u8g.drawLine(points[2][0], points[2][1], points[3][0], points[3][1]);  // connect points 2-3
    u8g.drawLine(points[3][0], points[3][1], points[0][0], points[0][1]);  // connect points 3-0

    u8g.drawLine(points[4][0], points[4][1], points[5][0], points[5][1]);  // connect points 4-5
    u8g.drawLine(points[5][0], points[5][1], points[6][0], points[6][1]);  // connect points 5-6
    u8g.drawLine(points[6][0], points[6][1], points[7][0], points[7][1]);  // connect points 6-7
    u8g.drawLine(points[7][0], points[7][1], points[4][0], points[4][1]);  // connect points 7-4

    u8g.drawLine(points[0][0], points[0][1], points[4][0], points[4][1]);  // connect points 0-4
    u8g.drawLine(points[1][0], points[1][1], points[5][0], points[5][1]);  // connect points 1-5
    u8g.drawLine(points[2][0], points[2][1], points[6][0], points[6][1]);  // connect points 2-6
    u8g.drawLine(points[3][0], points[3][1], points[7][0], points[7][1]);  // connect points 3-7

  } while (u8g.nextPage());  // u8g library specific, has to be there
}