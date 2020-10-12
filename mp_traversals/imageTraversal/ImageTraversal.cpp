#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traversal_ = NULL;
  png_ = PNG();
  start_ = Point();
  tolerance_ = 0; 
  visited = NULL;
  current_ = Point();

}
ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, PNG png, Point start, double tolerance){
  traversal_ = traversal;
  png_ = png;
  start_ = start;
  tolerance_ = tolerance; 
  current_ = start;
  visited = new bool[png.width()*png.height()];
  for(unsigned int x = 0; x < png.width(); x++){
    for(unsigned int y = 0; y < png.height(); y++){
      visited[png.width() * y + x] = false;
    }
  }
  visited[png.width() * start_.y + start_.x] = true;
  adding(start);
}

// Iterator(const Iterator& other){
//   traversal_ = other.traversal_;
//   png_ = other.png_;
//   start_ = other.start_;
//   tolerance_ = other.tolerance_; 
//   current_ = other.start_;
//   visited = new bool[other.png_.width()* other.png_.height()];
//   for(int x = 0; x < other.png_.width(); x++){
//     for(int y = 0; y < other.png_.height(); y++){
//       visited[other.png_.width() * y + x] = false;
//     }
//   }
// }

//make a destructor to clear the visited bool array
// delete[] visited;
ImageTraversal::Iterator::~Iterator() {
  if(visited != NULL)
    delete[] visited;
  visited = NULL; 
}


 bool ImageTraversal::Iterator::alreadyvisited(Point newpoint){
  // ImageTraversal temp = ; // is this calling the copy ctor correctly? 
  // Point curr = temp->pop(); // make a copy of the traversal pointer to a stack or queue, but just grabbing first
  //  for(int x = 0; x < png_.width(); x++){
  //   for(int y = 0; y < png_.height(); y++){
      // if((current_.x == newpoint.x) && (current_.y == newpoint.y))
      //   visited[png_.width() * curr.y + curr.x] = true;
      //visited[png_.width() * curr.y + curr.x] = false;
  //    }
  //  }
  if(visited[png_.width() * newpoint.y + newpoint.x] == true)
    return true;
  return false;
 }

 bool ImageTraversal::Iterator::tolerancecheck(Point newpoint){
   // figured should use calculateDelta here, but a little confused 
   /*
   The pixel at the point is greater than or equal to a given tolerance away from the pixel at the starting point. 
   The function ImageTraversal::calculateDelta is provided for you to calculate the difference between two pixels.
   */
  if (newpoint.x >= png_.width() || newpoint.y >= png_.height())
    return false;
  if (newpoint.x < 0 || newpoint.y < 0)
    return false;
  if (newpoint.x < png_.width() && newpoint.y < png_.height()){
    HSLAPixel & starting = png_.getPixel(start_.x,start_.y);
    HSLAPixel & curr = png_.getPixel(newpoint.x,newpoint.y);
    if(calculateDelta(starting, curr) < tolerance_){ //with a given tolerance or do i need to somehow incorporate traversal?
      if(!alreadyvisited(newpoint))
        return true;
    }
  }
  return false;
 }

void ImageTraversal::Iterator::adding(Point newpoint){
  //ImageTraversal* temp = traversal_; // need to call copy ctor here too
  Point right(newpoint.x+1, newpoint.y);
  traversal_->add(right);
  Point below(newpoint.x, newpoint.y+1);
  traversal_->add(below);
  Point left(newpoint.x-1, newpoint.y);
  traversal_->add(left);
  Point above(newpoint.x, newpoint.y-1);
  traversal_->add(above);
   
}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  // pop, check checks--> assign the current point to this new point, call adding function and add this current point to the bool visited array, then return *this
  // also need to make sure that the traversal isn't empty
  // if not valid --> keep popping until valid 
  current_ = traversal_->pop(); 
  if (tolerancecheck(current_))
    adding(current_);
  while(!traversal_->empty() && !tolerancecheck(current_)){
    // only for when you haven't found it yet
    current_ = traversal_->pop();
    // adding(current_);
    if (tolerancecheck(current_))
      adding(current_);
  }
  // found
  visited[png_.width() * current_.y + current_.x] = true;
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  // location is the same, the traversal_ is the same, and the current_ is the same? 
  bool thisEmpty = false; 
  bool otherEmpty = false;

  if (traversal_ == NULL) { thisEmpty = true; }
  if (other.traversal_ == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = traversal_->empty(); }
  if (!otherEmpty) { otherEmpty = other.traversal_->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the traversals are equal, return true
  else if ((!thisEmpty)&&(!otherEmpty)) return (traversal_ != other.traversal_); //both not empty then compare the traversals
  else return true; // one is empty while the other is not, return true
}

