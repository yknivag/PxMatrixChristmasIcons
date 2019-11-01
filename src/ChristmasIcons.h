/*
  ChristmasIcons.h - ESP library for PxMatrix displays which contains a number of Christmas Icons.
  Created by Gavin Smalley, October 31st 2019.
  Released into the public domain.
*/
#ifndef ChristmasIcons_h
#define ChristmasIcons_h

#ifndef PxMatrix_h
#include <PxMatrix.h> // Satisfy dependency on PxMatrix library if not already included.
#endif

#include <IncludeList.h>

#define ICON_HEIGHT 32
#define ICON_WIDTH 32

class ChristmasIcons
{
  public:
    ChristmasIcons(PxMATRIX* display);
    void drawIcon(int x = 0, int y = 0, const uint16_t image[] = bells);
  private:
    PxMATRIX* _display;
};

#endif
