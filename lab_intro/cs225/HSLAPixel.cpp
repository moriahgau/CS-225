/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {
    HSLAPixel::HSLAPixel(){ // default constructor
        h = 0.0;
        s = 0.0;
        l = 1.0;
        a = 1.0;
    }
    HSLAPixel:: HSLAPixel(double hue, double saturation, double luminance){ // constructor with 3 arguments
        h = hue; 
        s = saturation; 
        l = luminance; 
        a = 1.0;
    }
    HSLAPixel:: HSLAPixel(double hue, double saturation, double luminance, double alpha){ // constructor with all 4 arguments
        h = hue; 
        s = saturation; 
        l = luminance; 
        a = alpha; 
    }
}
