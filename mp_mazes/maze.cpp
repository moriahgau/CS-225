/* Your code here! */
#include "maze.h"
#include "dsets.h"
#include <algorithm> 
#include <time.h>
#include <queue>
#include <unistd.h>

using namespace std;
using namespace cs225;

SquareMaze::SquareMaze(){   // initialize the private variables
    _width = 0; 
    _height = 0; 
}
void SquareMaze::makeMaze(int width,int height){
    this->_width = width;
    this->_height = height;
    int size = width * height;  // initialize the new maze size

    dset.addelements(size);   // add elements to disjoint set
    _rightwalls.resize(size, true);   // draw rwalls, "rightwall"s, at every single cell
    _bottomwalls.resize(size, true);  // draw dwalls, "downwall"s,  at every single cell
    struct timespec ts;               // seed for to use rand()
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    int count = 0; 
     while(count < size-1){            // which all of the cells have not been visited yet
        int x = rand() % width;        // find random (x,y) coordinates and therefore indexes
        int y = rand() % height; 
        int i = x + y * _width; 
        bool rwallcheck = rand()%2;  // randomize which wall to remove, 0 = break the dwall; 1 = break the rwall

        if(rwallcheck == 0){  // break the dwall
            // check that y is within bonds and the two indexes are not already in the same disjoint set
            if((y < height - 1) && (_bottomwalls[i] == true) && (dset.find(i) != dset.find(i+width))){
                dset.setunion(i, i+width);  // remove walls and merge cells
                _bottomwalls[i] = false;    // set bool to false
                count++;
            }
        }
        else{ // break rwall
            // check that x is within bonds and the two indexes are not already in the same disjoint set
            if((x < width - 1) && (_rightwalls[i] == true) && (dset.find(i) != dset.find(i+1))){
                dset.setunion(i, i+1);  // remove walls and merge cells
                _rightwalls[i] = false; // set bool to false
                count++;
            }
        }
     }

}
bool SquareMaze::canTravel(int x, int y, int dir) const{
    int index = y * _width + x; // determine index
    if (dir == 0){ // check rightward step
        if(x < _width -1 && (_rightwalls[index] == false)) //  check that x is within bonds and it has no rwall
            return true;
    }
    else if (dir == 1){ // check downward step
        if(y < _height -1 && (_bottomwalls[index] == false)) // check that y is within bonds and it has no dwall
            return true;
    }
    else if (dir == 2){ // check leftward step
        if(x > 0 && (_rightwalls[y * _width + (x-1)] == false)) // check that x is within bonds and its left has no rwall
            return true;
    }
    else if (dir == 3){ // check upward step
        if(y > 0 && (_bottomwalls[(y-1) * _width + x] == false)) // check that y is within bonds and its top has no dwall
            return true;
    }
    return false;
}
void SquareMaze::setWall(int x, int y, int dir, bool exists){
    int index = y * _width + x; 
    if(dir == 0){   // Right
        _rightwalls[index] = exists;    // set rwall at index to bool
    }
    else if(dir == 1){  // Down
        _bottomwalls[index] = exists;   // set dwall at index to bool
    }
}
vector <int> SquareMaze::solveMaze(){
    // how to guarantee linear time check? 
    int size = _width * _height;
    vector<int> path(size, 0);      // create path, visited, pathlength, and prev vectors with the size of the maze 
    vector<int> visited(size, 0);
    vector<int> pathlength(size, -1); 
    vector <int> prev(size, 0); 
    std::queue <pair<int, int>> queue; // create queue to store coordinates
    queue.push({0,0}); // push the starting point

    while(!queue.empty()){
        // BFS traversal check
        // LEFT
        pair<int, int> i = queue.front(); // set i to the first element in the queue
        if (canTravel(i.first, i.second, 2) && visited[(i.second) * _width + ((i.first-1))] == 0){  // check you can go left and it has not been visited
            path[(i.second) * _width + ((i.first-1))] = 2; // set path to left
            visited[(i.second) * _width + ((i.first-1))] = 1; // if visited, set to 1
            pathlength[(i.second) * _width + ((i.first-1))] = pathlength[(i.second) * _width + ((i.first))] +1; // increment the pathlength
            prev[(i.second) * _width + ((i.first-1))] = i.first + i.second * _width;    // set to previous index
            queue.push({i.first-1, i.second});    // push the left cell 
        }
        // RIGHT
        if (canTravel(i.first, i.second, 0) && visited[(i.second) * _width + ((i.first+1))] == 0){   // check you can go right and it has not been visited
            path[(i.second) * _width + ((i.first+1))] = 0; // set path to right
            visited[(i.second) * _width + ((i.first+1))] = 1; // if visited, set to 1
            pathlength[(i.second) * _width + ((i.first+1))] = pathlength[(i.second) * _width + ((i.first))] +1; // increment the pathlength
            prev[(i.second) * _width + ((i.first+1))] = i.first + i.second * _width;    // set to previous index
            queue.push({i.first+1, i.second});    // push the right cell
        }
        // DOWN
        if (canTravel(i.first, i.second, 1) && visited[((i.second+1)) * _width + (i.first)] == 0){ // check you can go down and it has not been visited
            path[((i.second+1)) * _width + ((i.first))] = 1; // set path to down
            visited[((i.second+1)) * _width + (i.first)] = 1; // if visited, set to 1
            pathlength[((i.second+1)) * _width + (i.first)] = pathlength[(i.second) * _width + ((i.first))] +1; // increment the pathlength
            prev[(i.second+1) * _width + ((i.first))] = i.first + i.second * _width;    // set to previous index
            queue.push({i.first, i.second+1});    // push the below cell
        }
        // UP
        if (canTravel(i.first, i.second, 3) && visited[((i.second-1)) * _width + (i.first)] == 0){  // check you can go up and it has not been visited
            path[((i.second-1)) * _width + ((i.first))] = 3; // set path to up
            visited[((i.second-1)) * _width + (i.first)] = 1; // if visited, set to 1
            pathlength[((i.second-1)) * _width + (i.first)] = pathlength[(i.second) * _width + ((i.first))] +1; // increment pathlength
            prev[(i.second-1) * _width + (i.first)] = i.first + i.second * _width;  // set to previous index
            queue.push({i.first, i.second-1});    // push the above cell
        }
        queue.pop();     // remove coordinate from queue
    }
    int longindex = 0; 
    int longestpath = 0;
    for (int i = (_height-1) * _width; i < size; i++){  // iterate through the bottom of the maze
        if(pathlength[i] > longestpath){    // compare to find longer path
            longindex = i; 
            longestpath = pathlength[i];       // update both variables if longer found
        }
    }
    //reverse the path
    vector<int> finalpath;
    while (longindex != 0) {                    // loop through 
        finalpath.push_back(path[longindex]);   // push back the path value 
        longindex = prev[longindex];            // update the longindex
    }

    reverse(finalpath.begin(), finalpath.end());    // reverse the order of elements in finalpath

    return finalpath;

}
    cs225::PNG * SquareMaze::drawMaze()const{
    cs225::PNG * themaze = new PNG(_width * 10 + 1, _height * 10 + 1);  // create a maze with the measurements
    // Walls on top perimeter
    for (int i = 0; i < 10 * _width + 1; i ++){   // loop through the width of the maze
        if ( i < 1 || i > 9){    // check to confirm not at the entrance
            HSLAPixel & pixel1 = themaze->getPixel(i,0);    // get the pixels in the top row
            pixel1.l = 0;    // darken
        }
    }
    // walls on the left perimeter
    for (int j = 0 ;j < 10 * _height + 1; j++){ // loop through the height of the maze
        HSLAPixel & pixel = themaze->getPixel(0,j); // get the pixels in the left column
        pixel.l = 0;    // darken 
    }

    for (int i = 0; i < _width; i ++){
        for (int j = 0 ;j < _height; j++){      // traverse through every cell
            if(_rightwalls[j * _width + i] == true){    // if right wall exists
                for(int k = 0; k < 11; k++){    // iterate through pixels
                    HSLAPixel & pixel = themaze->getPixel((i+1)*10,j*10+k); // get pixels
                    pixel.l = 0;    //darken
                }
            }
            if(_bottomwalls[j * _width + i] == true){   // if bottom wall exists
                for(int k = 0; k < 11; k++){    // iterate through pixels
                    HSLAPixel & pixel = themaze->getPixel(i*10+k,(j+1)*10); //get pixels
                    pixel.l = 0;    //darken
                }
            }
            if((_rightwalls[j * _width + i] == true) && (_bottomwalls[j * _width + i] == true)){    // same if both right and bottom wall exist
                for(int k = 0; k < 11; k++){    // iterate through pixels
                    HSLAPixel & pixel1 = themaze->getPixel((i+1)*10,j*10+k);    // get pixels
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
    cs225::PNG * mazesolution = drawMaze(); // draw the maze
    vector <int> solution = solveMaze();    // set solution to the return vector of solveMaze
    pair<int, int> point (5,5); 
    // coloring the path red
    for (size_t i = 0; i < solution.size(); i++){   // traverse through entire maze
        if (solution[i] == 0){    // if RIGHT
            for( int j = 0; j < 11; j++){   // traverse through pixels 
                HSLAPixel & pixel = mazesolution->getPixel((point.first + j), point.second);    // get pixels
				pixel.h = 0;    // turn red
				pixel.s = 1.0;
				pixel.l = 0.5;
                pixel.a = 1;
            }
            point.first = point.first + 10; // increment point.first
        }
        else if (solution[i] == 1){    // if DOWN
            for( int j = 0; j < 11; j++){   // traverse through pixels 
                HSLAPixel & pixel = mazesolution->getPixel(point.first, (point.second+j));  // get pixels and turn red
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
                pixel.a = 1;
            }
            point.second = point.second + 10;   // increment point.second
        }
        else if (solution[i] == 2){    // if LEFT
            for( int j = 0; j < 11; j++){   // traverse through pixels
                HSLAPixel & pixel = mazesolution->getPixel((point.first-j), point.second);  // get pixels and turn red
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
                pixel.a = 1;
            }
            point.first = point.first -10;  // increment point.first
        }
        else if (solution[i] == 3){    // if UP
            for( int j = 0; j < 11; j++){   // traverse through pixels
                HSLAPixel & pixel = mazesolution->getPixel(point.first, (point.second-j));  // get pixels and turn red
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
                pixel.a = 1;
            }
            point.second = point.second -10;    // increment point.second
        }
    }
    // getthe last cell, check this
    int x = point.first/10; // find the x of the last cell
    int y = _height-1;  // y of the last cell
    // whiten the exit
    for (int k = 1; k < 10; k++){   // traverse through pixels 
        HSLAPixel & pixel = mazesolution->getPixel(x*10+k, (y+1)*10);    // get the pixel
        pixel.l = 1;    // whiten
        pixel.a = 1;
    }
    return mazesolution;    // return the marked mazesolution
}