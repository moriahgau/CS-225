#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <math.h>

#include <string>
using cs225::HSLAPixel;
using cs225::PNG;

void rotate(std::string inputFile, std::string outputFile) {
  PNG* original = new PNG();
  original->readFromFile(inputFile); //
  unsigned width = original->width();
  unsigned height = original->height();
    // Create out.png
  PNG* output = new PNG (width, height);

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
  for (unsigned y = 0; y < height; y++) {
     for (unsigned x = 0; x < width; x++) {
            // Calculate the pixel difference
        HSLAPixel& curr = original->getPixel(x, y);
        HSLAPixel& rotate = output->getPixel(width-1-x, height-1-y);
        rotate = curr;
        }
    }

    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    delete output;
    delete original;
}
// Create a gradient 
cs225::PNG createSpotlight(cs225::PNG image, int centerX, int centerY) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);

      // Create a gradient based on distance from edge of photo
      pixel.h = pixel.h - pixel.h *0.005 * sqrt(((x-centerX)*(x-centerX)) + ((y-centerY)*(y-centerY))); 
      
    }
  }
  return image;
  
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  //  make image with 3 colors, try to throw in two rectangles to 
  // split screen lengthwise and have a spotlight in each rect
  	// TODO: Part 3
  double h = 166;
  for(unsigned z=0; z<png.width(); z=z+75){
	for (unsigned x = z; x < png.width(); x++) {
		for (unsigned y = z; y < png.width(); y++) {
			cs225::HSLAPixel & curPixel = png.getPixel(x, y);
			cs225::HSLAPixel pixel(h, 1.0, 0.5, 1.0);
     
      if (h == 360 || h > 360){
        h = 166;
      }
      else
        h = 50;
      
      curPixel = pixel;
		}
	}
  }
  png = createSpotlight(png, 50, 50);
  png = createSpotlight(png, 400, 400);
  png = createSpotlight(png, 750, 750);
	return png;
  //return png;
}
