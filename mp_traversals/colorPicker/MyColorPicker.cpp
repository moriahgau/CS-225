#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;


MyColorPicker::MyColorPicker(double increment, double smallincrement)
  : hue(0), luminance (0), saturation(0), increment(increment), smallincrement(smallincrement) { }

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  HSLAPixel pixel(hue, saturation, luminance);
  hue += increment*1.20;
  saturation += smallincrement;
  luminance += smallincrement; 
  if (hue >= 360) 
    { hue -= 360; }
  if (saturation >= 1) 
    { saturation -= 1; }
  if (luminance >= 1) 
    { luminance -= 1; }
  
  return pixel;
}
