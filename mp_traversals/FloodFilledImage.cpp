#include "cs225/PNG.h"
#include <list>
#include <iostream>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;

/**
 * Constructs a new instance of a FloodFilledImage with a image `png`.
 * 
 * @param png The starting image of a FloodFilledImage
 */
FloodFilledImage::FloodFilledImage(const PNG & png) {
  /** @todo [Part 2] */
  png_ = png;
  traversal_.clear();
  colorPicker_.clear();
  }

/**
 * Adds a FloodFill operation to the FloodFillImage.  This function must store the operation,
 * which will be used by `animate`.
 * 
 * @param traversal ImageTraversal used for this FloodFill operation.
 * @param colorPicker ColorPicker used for this FloodFill operation.
 */
void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
  // what does it mean that this function must store the operation? Implying that we'd need a stack or queue? 
  traversal_.push_back(&traversal);
  colorPicker_.push_back(&colorPicker);
}

/**
 * Creates an Animation of frames from the FloodFill operations added to this object.
 * 
 * Each FloodFill operation added by `addFloodFill` is executed based on the order
 * the operation was added.  This is done by:
 * 1. Visiting pixels within the image based on the order provided by the ImageTraversal iterator and
 * 2. Updating each pixel to a new color based on the ColorPicker
 * 
 * While applying the FloodFill to the image, an Animation is created by saving the image
 * after every `frameInterval` pixels are filled.  To ensure a smooth Animation, the first
 * frame is always the starting image and the final frame is always the finished image.
 * 
 * (For example, if `frameInterval` is `4` the frames are:
 *   - The initial frame
 *   - Then after the 4th pixel has been filled
 *   - Then after the 8th pixel has been filled
 *   - ...
 *   - The final frame, after all pixels have been filed)
 */ 
Animation FloodFilledImage::animate(unsigned frameInterval) const {
  Animation animation;
  /** @todo [Part 2] */
  // not entirely sure what they're trying to ask us to do?
  PNG copypng = png_; 
  //animation.addFrame(copypng); //don't need this since initial frame covered in the loop? 
  int counter = 0;
  for (unsigned i = 0; i < traversal_.size(); i ++){
    for (ImageTraversal:: Iterator iterate = traversal_[i]->begin(); iterate != traversal_[i]->end(); ++iterate){
        if (counter % frameInterval == 0){
          animation.addFrame(copypng);
        }
        counter ++;
        HSLAPixel & pixel = copypng.getPixel((*iterate).x, (*iterate).y); //according to iterator;
        pixel = colorPicker_[i]->getColor((*iterate).x, (*iterate).y);  //color pickervalue;
    }
  }
  if (counter % frameInterval != 0) // not sure if want/don't want double count if last frame is multiple of interval
    animation.addFrame(copypng); 
  return animation;
}
