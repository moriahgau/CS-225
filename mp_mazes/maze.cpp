/* Your code here! */
#include "maze.h"
#include "dsets.h"
#include <algorithm> 
#include <time.h>
#include <queue>
#include <unistd.h>

using namespace std;
using namespace cs225;

SquareMaze::SquareMaze(){
    _width = 0; 
    _height = 0; 
}
int SquareMaze::getwalls(int x){
    return _cells[x];
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
    // while(dset.size(0) != size){// check if everything is in one union
    int count = 0; 
     while((count < (size-1)) && (dset.size(0) != size)){
        // int i = rand() % size;  // a random cell
        int x = rand() % width; 
        int y = rand() % height; 
        int i = x + y * width;  // a random cell
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
        if (randwalls == 2){ // remove dwall
            // gdb by checking each cells[i] and if it's actually being replaced
            // whenever breakdown wall, print wall breaking down
            if (_cells[i] == 0 || _cells[i] == 1)   // second is 2? or 1? 
                continue;
            // if(((i+width)/width) < _height -1) && (dset.find(i) != dset.find(i+width))))){
            // if((i < size - width) && (dset.find(i) != dset.find(i+width))){
            else if((y < (height -1)) && (dset.find(i) != dset.find(i+width))){
                dset.setunion(i, i + width);
                if (_cells[i] == 3) // if both exist 
                    _cells[i] = 1;  // remove the dwall, theefore only rwall exists
                else                // if only dwall
                    _cells[i] = 0;  // then no walls
                count++;
            }
        }
        else if (randwalls == 1){ // remove rwall
            if (_cells[i] == 0 || _cells[i] == 2)
                continue;
            //bounds, check under
            // if((((i+1)%width) < _width -1 ) && (dset.find(i) != dset.find(i+1))){
            // if((((i+1)% width)!= 0) && (dset.find(i) != dset.find(i+1))){
            else if((x < (width -1)) && (dset.find(i) != dset.find(i+1))){
                dset.setunion(i, i + 1);
                // _cells[i] = 2;
                if (_cells[i] == 3) // if both exist 
                    _cells[i] = 2;  // remove the rwall, theefore only dwall exists
                else                // if only rwall
                    _cells[i] = 0;  // then no walls
                count++;
            }
        }
    }

}
bool SquareMaze::canTravel(int x, int y, int dir) const{
    int index = y * _width + x; // use this to determine vector index? 
    // if(_width == 0 || _height == 0)
    //     return false;
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
    //else
    return false;
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
    // how to guarantee linear time check? 
    vector<int> path(_width * _height, -1);
    vector<int> visited(_width * _height, 0);
    vector<int> pathlength(_width * _height, 0); 
    std::queue <pair<int, int>> queue; // backtracking for BFS traversal
    std::queue <pair<int, int>> options;
    //int x = 0; int y = 0;   // assume starting pt to be top left
    queue.push({0,0}); // push the starting point

    while(!queue.empty()){
        // BFS traversal check
        //left
        pair<int, int> i = queue.front(); // confused  <-1,2,-1> <2,-1,-1>
        if (canTravel(i.first % _width, i.second % _height, 2) && visited[(i.second%_height) * _width + ((i.first-1)%_width)] == 0){
            path[(i.second%_height) * _width + ((i.first-1)%_width)] = 2; // set path to left, should this just be i.first or i.first-1? 
            visited[(i.second%_height) * _width + ((i.first-1)%_width)] = 1; // if visited, set to 1
            pathlength[(i.second%_height) * _width + ((i.first-1)%_width)] = pathlength[(i.second%_height) * _width + ((i.first)%_width)] +1; // increment by 1, not sure about this
            queue.push({i.first-1, i.second});    // does this work? 
        }
        //right
        if (canTravel(i.first % _width, i.second % _height, 0) && visited[(i.second%_height) * _width + ((i.first+1)%_width)] == 0){
            path[(i.second%_height) * _width + ((i.first+1)%_width)] = 0; // set path to left, should this just be i.first or i.first-1? 
            visited[(i.second%_height) * _width + ((i.first+1)%_width)] = 1; // if visited, set to 1
            pathlength[(i.second%_height) * _width + ((i.first+1)%_width)] = pathlength[(i.second%_height) * _width + ((i.first)%_width)] +1; // increment by 1, not sure about this
            queue.push({i.first+1, i.second});    // does this work? 
        }
        //down
        if (canTravel(i.first % _width, i.second % _height, 1) && visited[((i.second+1)%_height) * _width + (i.first%_width)] == 0){
            path[((i.second+1)%_height) * _width + ((i.first)%_width)] = 1; // set path to left, should this just be i.first or i.first-1? 
            visited[((i.second+1)%_height) * _width + (i.first%_width)] = 1; // if visited, set to 1
            pathlength[((i.second+1)%_height) * _width + (i.first%_width)] = pathlength[(i.second%_height) * _width + ((i.first)%_width)] +1;; // increment by 1, not sure about this
            queue.push({i.first, i.second+1});    // does this work? 
            if( (i.second+1) % _height == _height -1)
                options.push({i.first,i.second+1}); // store another list of all valid possibilities
        }
        //up
        if (canTravel(i.first % _width, i.second % _height, 3) && visited[((i.second-1)%_height) * _width + (i.first%_width)] == 0){
            path[((i.second-1)%_height) * _width + ((i.first)%_width)] = 3; // set path to left, should this just be i.first or i.first-1? 
            visited[((i.second-1)%_height) * _width + (i.first%_width)] = 1; // if visited, set to 1
            pathlength[((i.second-1)%_height) * _width + (i.first%_width)] = pathlength[(i.second%_height) * _width + ((i.first)%_width)] +1;; // increment by 1, not sure about this
            queue.push({i.first, i.second-1});    // does this work? 
        }
        queue.pop();
    }
    // for loop through the last row and check the largest distance by using the path
    
    pair<int, int> x = options.front();
    int longestlength = pathlength[(x.second%_height) * _width + ((x.first)%_width)];
    options.pop(); 
    while(!options.empty()){
        pair<int, int> y = options.front(); // will this hit NULl due to above pop at some point and error? 
        if (longestlength < pathlength[(y.second%_height) * _width + ((y.first)%_width)]){
            x = y;
            longestlength = pathlength[(y.second%_height) * _width + ((y.first)%_width)];
        }
        // if the longest path are the same, do the x index check comparison 
        else if(pathlength[(x.second%_height) * _width + ((x.first)%_width)] == pathlength[(y.second%_height) * _width + ((y.first)%_width)]){
            if (x.first < y.first)
                continue;
            else{
                x = y;
                longestlength = pathlength[(y.second%_height) * _width + ((y.first)%_width)];
            }
        }
        options.pop();
    }
    //reverse path, x is the final point
    vector <int> finalpath;
    pair <int, int> curr = x;
    pair <int, int> start (0,0);
    while(curr != start){   // what about the very first element which is 4? 
        // if path is L, R, D, U push to front of the finalpath
        // if path L, R, D, U, apply direction to current {10,10} --> IF LEFT {11, 10}
        if(path[(curr.second%_height) * _width + (curr.first%_width)] == 0){ // if R
            finalpath.push_back(path[(curr.second%_height) * _width + (curr.first%_width)]);
            curr = {curr.first-1, curr.second};
        }
        else if(path[(curr.second%_height) * _width + (curr.first%_width)] == 2){ // if L
            finalpath.push_back(path[(curr.second%_height) * _width + (curr.first%_width)]);
            curr = {curr.first+1, curr.second};
        }
        else if(path[(curr.second%_height) * _width + (curr.first%_width)] == 1){ // if D
            finalpath.push_back(path[(curr.second%_height) * _width + (curr.first%_width)]);
            curr = {curr.first, curr.second-1};
        }
        else if(path[(curr.second%_height) * _width + (curr.first%_width)] == 3){ // if U
            finalpath.push_back(path[(curr.second%_height) * _width + (curr.first%_width)]);
            curr = {curr.first, curr.second+1};
        }
    }
    return finalpath;
}
cs225::PNG * SquareMaze::drawMaze()const{
    cs225::PNG * themaze = new PNG(_width * 10 + 1, _height * 10 + 1); 
    // Walls on top perimeter
    for (int i = 0; i < 10 * _width + 1; i ++){   //PNG HSP l = 0; get pixel and set luminosity, this is the top, position (i, 0)
        if ( i < 1 || i > 9){    // check to confirm not at the entrance
            HSLAPixel & pixel1 = themaze->getPixel(i,0);
            pixel1.l = 0;    // darken
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
                    pixel.l = 0;//darken
                }
            }
            else if(_cells[j * _width + i] == 2){
                for(int k = 0; k < 11; k++){
                    HSLAPixel & pixel = themaze->getPixel(i*10+k,(j+1)*10);
                    pixel.l = 0;    //darken
                }
            }
            else if(_cells[j * _width + i] == 3){
                for(int k = 0; k < 11; k++){
                    HSLAPixel & pixel1 = themaze->getPixel((i+1)*10,j*10+k);
                    HSLAPixel & pixel2 = themaze->getPixel(i*10+k,(j+1)*10);
                    pixel1.l = 0;    //darken
                    pixel2.l = 0;
                }
            }
        }
    }
    return themaze; // do I also need to draw the bottom perimeter? 
    
}
cs225::PNG * SquareMaze::drawMazeWithSolution(){
    cs225::PNG * mazesolution = drawMaze();
    vector <int> solution = solveMaze();
    pair<int, int> point (5,5);
    // coloring the path red
    for (size_t i = 0; i < solution.size(); i++){
        if (i == 0){    // R
            for( int j = 0; j < 11; j++){
                HSLAPixel & pixel = mazesolution->getPixel(point.first, point.second);
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
				point.first++;
            }
        }
        else if (i == 1){    // D
            for( int j = 0; j < 11; j++){
                HSLAPixel & pixel = mazesolution->getPixel(point.first, point.second);
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
				point.second++;
            }
        }
        else if (i == 2){    // L
            for( int j = 0; j < 11; j++){
                HSLAPixel & pixel = mazesolution->getPixel(point.first, point.second);
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
				point.first--;
            }
        }
        else if (i == 3){    // U
            for( int j = 0; j < 11; j++){
                HSLAPixel & pixel = mazesolution->getPixel(point.first, point.second);
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
				point.first--;
            }
        }
    }
    // getthe last cell, check this
    int x = point.first/10;
    int y = _height-1;
    // whiten the exit
    for (int k = 0; k < 10; k++){
        HSLAPixel & pixel = mazesolution->getPixel(x*10+k, (y+1)*10);    // the other coordinate part 
        pixel.l = 1;    // whiten
    }
    return mazesolution;
};
