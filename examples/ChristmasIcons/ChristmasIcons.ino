/* -------------------------------------------------------------------------
   ChristmasIcons Library Examples
   ESP library for PxMatrix displays which contains a number of Christmas Icons.
   Created by Gavin Smalley, October 31st 2019.
   Released into the public domain.

   Please Note: This example will only run on a 64x64 display or larger as it displays
                four 32x32 icons at a time.
                The library itself works on any PxMatrix display which is at least
                32x32.
   ------------------------------------------------------------------------- */

/* Set Up the PxMatrix Display
   This is boilerplate code required for the PxMatrix display to run,
   it is not specific to this library or example.
   For more details see the PxMatrix library documentation and its own examples. */

#define double_buffer
#include <PxMatrix.h>

#define DISPLAY_DRAW_TIME 10

#ifdef ESP32

#define P_LAT 22
#define P_A 19
#define P_B 23
#define P_C 18
#define P_D 5
#define P_E 15
#define P_OE 2
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

#endif

#ifdef ESP8266

#include <Ticker.h>
Ticker display_ticker;
#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_D 12
#define P_E 0
#define P_OE 2

#endif

// Pins for LED MATRIX

//PxMATRIX display(64,32,P_LAT, P_OE,P_A,P_B,P_C,P_D);
PxMATRIX display(64,64,P_LAT, P_OE,P_A,P_B,P_C,P_D,P_E);

#ifdef ESP8266
// ISR for display refresh
void display_updater()
{
  display.display(DISPLAY_DRAW_TIME);
}
#endif

#ifdef ESP32
void IRAM_ATTR display_updater() {
  display.display(DISPLAY_DRAW_TIME);
}
#endif

/* Begin the Christmas Icons Code */

#include <ChristmasIcons.h>

/* The constructor takes a pointer to the PxMatrix display object. */

ChristmasIcons ChristmasIcons(&display);

/* Set up an array of icons and some control variables so that the code
   can iterate through them later.
   It would be unusual to do this this way in a practical project,
   more likely would be to reference the Icon name (list below) directly in
   the ChristmasIcons.drawIcon() call, eg
     ChristmasIcons.drawIcon(5, 5, bells);
   This section is, therefore, quite specific to this example. */

const uint16_t *icons[44] = {
  bells,
  bigbell,
  bluelight,
  candycane,
  hat,
  clearlight,
  goldball,
  goldcandle,
  goldstar,
  greenball,
  greencandle,
  greencandle_2,
  greenlight,
  holly_1,
  holly_2,
  present_1,
  present_2,
  present_3,
  present_4,
  present_5,
  purpleball,
  reindeer,
  reindeers,
  redball,
  redcandle,
  redcandle_2,
  redlight,
  santa,
  silverball,
  silvercandle,
  silverstar,
  sled,
  snowglobe_penguin,
  snowglobe_tree,
  snowman,
  stocking,
  tree_1,
  tree_2,
  whitecandle,
  woodenball,
  wreath_1,
  wreath_2,
  wreath_3,
  yellowlight
};
int icon_count = 44;
int current_icon = 0;

/* Now run setup() */

void setup()
{
  /* Start the serial interface so we can see any debug messages if debugging is enabled. */
  Serial.begin(115200);

  /* More boiler plate for the PxMatrix display
     You may have to adjust these depending on your display
     If the colours are muddled, see:
       https://github.com/2dom/PxMatrix/pull/140
     after the display.begin() line.
     If you have missing lines, or strange patterns, you may been to change the value in display.begin()
     or enable other modes, again see the PxMatrix library documentation. */

  display.begin(32);
  display.setFastUpdate(true);
  display.clearDisplay();

  #ifdef ESP8266
    display_ticker.attach(0.002, display_updater);
  #endif

  #ifdef ESP32
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &display_updater, true);
    timerAlarmWrite(timer, 2000, true);
    timerAlarmEnable(timer);
  #endif
  /* End Boilerplate */
}

void loop()
{
  /* Setup has initialised everything but there is still nothing on the screen.
     Here in the loop, in this example, we will:
       - Clear the display
       - Add 4 Icons to the buffer
       - Push the buffer to the display
     The icons are pushed in order 4 at a time from the array of icons at the top of the code.
     In a real world application, you would probably display specific ones in specific places
     and you may accompany them with text.  Details of how to add text can be found in
     the PxMatrix documentation and examples. */

  display.clearDisplay();

  /*The drawIcon(int x, int y, const uint16_t image[]) method takes three parameters:
    1. The x position of the top left of the Icon.
    2. The y position of the top left of the Icon.
    3. The name of the Icon (these can be found in the array at the top of the code
       - It is possible to add further icons in the same format simply by dropping a .h file
         in the icons directory, and adding in include statement for that file in "IncludeList.h"
         The value of this parameter is then the name of the variable in
         that file containing the data. */

  int x = 0;
  int y = 0;
  for (int frame = 0; frame < 4; frame++) {
    switch (frame) {
      case 0:
        x = 0;
        y = 0;
        break;
      case 1:
        x = 32;
        y = 0;
        break;
      case 2:
        x = 0;
        y = 32;
        break;
      case 3:
        x = 32;
        y = 32;
        break;
    }
    /* This is the interesting line here, this is line that adds the icon to the buffer
       All of the code above it, chooses where on the display to put it and that below
       simply walks one step through the array of icons.
       A more typical use case would be:
         ChristmasIcons.drawIcon(16, 16, santa);
    */
    ChristmasIcons.drawIcon(x, y, icons[current_icon]);
    current_icon++;
    if (current_icon == icon_count) {
      current_icon = 0;
    }
  }

  /* Here you would add anything else you wanted to the screen buffer */

  /* Finally, push the contents of the buffer to the screen */
  display.showBuffer();

  /* and wait a few seconds before going round for the next four */
  delay(2500);
}
