/* Your code here! */
#include "maze.h"
#include "dsets.h"
#include <algorithm> 
#include <time.h>
using namespace std;
using namespace cs225;

SquareMaze::SquareMaze(){
    _width = 0; 
    _height = 0; 
}
void SquareMaze::makeMaze(int width,int height){
    this->_width = width;
    this->_height = height;
    int size = width * height; 
    // create walls at every single location and then go through, also on the edges of every cell
    // randomize rand() when to use setunion to remove walls and merge cells
    // then call setunion again to remove specific vwalls and hwalls to merge into one big maze
    // can also use double for loop to setunion, while loop to check everything is in one union
    //if in the same disjoint set, there is a path, each square should be in a different set
    //only one path between two squares without coming back to yourself
    // 0 = no walls; 1 = rwall, | ; 2 = dwall, _; 3 = both walls, how to cover right most wall with |-? or _|? 
    dset.addelements(size);   // add elements to disjoint set
    _cells.resize(size, 3);   // draw walls at every single cell
    // vector <int> temp;
    // for(int j = 0; j < size; j++){
    //     temp[j] = j;
    // }
    // random seed for 
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    // random_shuffle(temp.begin(), temp.end()); // if change out of vector
    // for (int i = 0; i < temp.size(); i++){ 
    while(dset.size(0) != size){// check if everything is in one union
        int i = rand() % size;
        int randwalls = rand() % 3;  // check maze is not connected error
        // if (randwalls == 0){ // if no walls
        //     if((i +1 < width -1 ) && (i+width < height -1))&& (dset.find(i) != dset.find(i+1)) && (dset.find(i) != dset.find(i+width))){
        //     // temp[i] --> i
        //     // check out of bounds, then check same set to the right and below, i + width
        //     dset.setunion(i, i + 1);
        //     dset.setunion(i, i + width);
        //     _cells[i] = 0;
        //     }
        // }
        if (randwalls == 1){ // remove dwall
            if (_cells[i] == 0)
                continue;
            // bounds, check right
            if((i +1 < width -1 ) && (dset.find(i) != dset.find(i+1))){
            // do I need to call setWall? 
            dset.setunion(i, i + 1);
            _cells[i] = 1;
            }
        }
        else if (randwalls == 2){ // remove rwall
            if (_cells[i] == 0)
                continue;
            //bounds, check under
            if((i+width < height -1) && (dset.find(i) != dset.find(i+width))){
            //call set wall? 
            dset.setunion(i, i + width);
            _cells[i] = 2;
            }
        }
    }

}
bool SquareMaze::canTravel(int x, int y, int dir) const{
    int index = y * _width + x; // use this to determine vector index? 
    if(_width == 0 || _height == 0)
        return false;
    if (dir == 0){ // check rightward step
        if(x < _width -1 && _cells[index] != 3 && _cells[index] != 1) //  rt wall?
            return true;
    }
    else if (dir == 1){ // check downward step
        if(x < _height -1 && _cells[index] != 3 && _cells[index] != 2) // is this valid for array and rt wall?
            return true;
    }
    else if (dir == 2){ // check leftward step
        if(x > 0 && _cells[y * _width + (x-1)] != 3 && _cells[y * _width + (x-1)] != 1) // is this valid for array and rt wall?
            return true;
    }
    else if (dir == 3){ // check upward step
        if(x > 0 && _cells[(y-1) * _width + x] != 3 && _cells[(y-1) * _width + x] != 2) // is this valid for array and rt wall?
            return true;
    }
    else{
        return false;
    }
}
void SquareMaze::setWall(int x, int y, int dir, bool exists){
    // 0 = rwall; 1 = dwall; assuming rwall = | and dwall = _ ? 
    int index = y * _width + x;
    if (dir == 0 && exists){ // wall exists on the right
        if (_cells[index] == 0) // if no walls
            _cells[index] = 1;  // add a rwall
        else if(_cells[index] == 2) // if just a dwall
            _cells[index] = 3;  // have both walls
    }
    else if (dir == 0 && !exists){ // no wall exists on the right 
       if (_cells[index] == 1)  //  if rwall
            _cells[index] = 0;  //  remove rwall 
        else if(_cells[index] == 3) // if both walls
            _cells[index] = 2;  // only have dwall 
    }
    else if (dir == 1 && exists){ // wall exists on the bottom
       if (_cells[index] == 0) // if no walls
            _cells[index] = 2;  // add a dwall
        else if(_cells[index] == 1) // if just a rwall
            _cells[index] = 3;  // have both walls
    }
    else if (dir == 1 && !exists){
        if (_cells[index] == 2)  //  if dwall
            _cells[index] = 0;  //  remove dwall 
        else if(_cells[index] == 3) // if both walls
            _cells[index] = 1;  // only have rwall 
    }
}
vector <int> SquareMaze::solveMaze(){
    vector<int> temp;
    return temp;
}
cs225::PNG * SquareMaze::drawMaze()const{
    cs225::PNG * themaze = new PNG(_width * 10 + 1, _height * 10 + 1); 
    // Walls on top perimeter
    for (int i = 0; i < 10 * _width + 1; i ++){   //PNG HSP l = 0; get pixel and set luminosity, this is the top, position (i, 0)
        if ( i < 1 || i > 9){    // check to confirm not at the entrance
            HSLAPixel & pixel = themaze->getPixel(i,0);
            pixel.l = 0;    // darken
        }
    }
    // walls on the left perimeter
    for (int j = 0 ;j < 10 * _height + 1; j++){
        HSLAPixel & pixel = themaze->getPixel(0,j);
        pixel.l = 0;// position (0, j)
    }

    for (int i = 0; i < _width; i ++){
        for (int j = 0 ;j < _height; j++){
            if(_cells[j * _width + i] == 1){
                for(int k = 0; k < 11; k++){
                    HSLAPixel & pixel = themaze->getPixel((i+1)*10,j*10+k);
                    pixel.l = 0;    //darken
                }
            }
            else if(_cells[j * _width + i] == 2){
                for(int k = 0; k < 11; k++){
                    HSLAPixel & pixel = themaze->getPixel(i*10+k,(j+1)*10);
                    pixel.l = 0;    //darken
                }
            }
        }
    }
    return themaze; 
    
}
cs225::PNG * SquareMaze::drawMazeWithSolution(){
    cs225::PNG * temp = NULL; 
    return temp;
};
