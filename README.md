# PxMatrix Christmas Icon Library

An ESP32/ESP8266 Library which contains a number of Christmas Icons prepared for use on PxMatrix compatible dispalys. The library also includes a displayIcon method and an example sketch.

## Copyright and Acknowledgements

The icons in this set are NOT my work. They are taken from a set available on the internet which has been made available by the creator "free for non-commercial use". Please RESPECT this and use this library ONLY for NON-COMMERCIAL purposes.

Link to the icons - http://www.iconarchive.com/show/xmas-icons-by-pixture.html

The majority of code in this library is NOT my work either. Most of it is a copy and paste from the PxMatrix library examples and the *drawIcon()* method is a copy from Brian Lough's YouTuber subscriber counter code written for the same display.

Image conversion was carried out using the converter at http://rinkydinkelectronics.com/t_imageconverter565.php

In short I've done very little, other than gather together existing works into a single place. I take no credit for the work of the incredibly talented people who have made this possible.

## Compatability

The library should work with all boards that is supported by the PxMatrix library and any display 32x32 pixels or larger that is supported by that library.

## Hardware Wiring

See PxMatrix library for hardware and wiring requirements.

## Features

The library contains 44 Christmas themed icons pre-prepared for use with the PxMatrix library and supported displays. Adding more icons (or removing icons) is a simple as adding correctly formatted .h files to the icons folder within the library structure and adding the appropriate *#include* line to the file *IncludeList.h*.

##Usage

### Include

*#include <ChristmasIcons.h>*

### Constructor

The constructor takes a pointer to the PxMatrix display object.

eg *ChristmasIcons ChristmasIcons(&display);*

### drawIcon()

*void drawIcon(int x = 0, int y = 0, const uint16_t image[]);*

The *drawIcon()* method takes three parameters:
    1. The x position of the top left of the icon.
    2. The y position of the top left of the icon.
    3. The name of the icon (these can be found in the array at the top of the code, or as the name of the variable in each .h file).

## Examples

### Christmas Icons

A single example is provided that shows 4 icons at a time on a 64x64 display and simply cycles throug the collection available. The example has been well commented to make it easy to apply the principles to your own project.
