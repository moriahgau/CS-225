/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {
    class HSLAPixel {
        public: 
        double h; double s; double l; double a; // declare variables
        HSLAPixel(); // default constructor
        HSLAPixel(double hue, double saturation, double luminance); // ctor with 3 arguments
        HSLAPixel(double hue, double saturation, double luminance, double alpha); // ctor with all 4 arguments
    };
    
}
