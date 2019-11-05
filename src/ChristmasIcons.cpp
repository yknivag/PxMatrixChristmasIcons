/*
  ChristmasIcons.h - ESP library for PxMatrix displays which contains a number of Christmas Icons.
  Created by Gavin Smalley, October 31st 2019.
  Released into the public domain.
*/

#include "ChristmasIcons.h"

ChristmasIcons::ChristmasIcons(PxMATRIX* display) {
  _display = display;
}

void ChristmasIcons::drawIcon(int x, int y, const uint16_t image[]) {

  uint16_t * buffer = new uint16_t[2048];
  memcpy_P(buffer, image, 2048);

  int imageWidth = ICON_HEIGHT;
  int imageHeight = ICON_WIDTH;
  int counter = 0;
  for (int yy = 0; yy < imageHeight; yy++)
  {
    for (int xx = 0; xx < imageWidth; xx++)
    {
      _display->drawPixel(xx + x , yy + y, buffer[counter]);
//    _display->drawPixel(xx + x , yy + y, image[counter]);
      counter++;
    }
  }
  free(buffer);
}

