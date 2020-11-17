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
    _rightwalls.resize(size, true);   // draw walls at every single cell
    _bottomwalls.resize(size, true);
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    // while(dset.size(0) != size){// check if everything is in one union
    int count = 0; 
     while(count < size-1){
        // int i = rand() % size;  // a random cell
        int x = rand() % width; 
        int y = rand() % height; 
        int i = x + y * _width; 
        bool rwallcheck = rand()%2;  // 0 = wall doesn't exist; 1 = wall exists

        if(rwallcheck == 0){  // break the dwall instead
            if((y < height - 1) && (_bottomwalls[i] == true) && (dset.find(i) != dset.find(i+width))){
                dset.setunion(i, i+width);
                _bottomwalls[i] = false;
                count++;
            }
        }
        else{ // wall exists, break rwall
            if((x < width - 1) && (_rightwalls[i] == true) && (dset.find(i) != dset.find(i+1))){
                dset.setunion(i, i+1);
                _rightwalls[i] = false;
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
        if(x < _width -1 && (_rightwalls[index] == false)) //  rt wall?
            return true;
    }
    else if (dir == 1){ // check downward step
        if(y < _height -1 && (_bottomwalls[index] == false)) // is this valid for array and rt wall?
            return true;
    }
    else if (dir == 2){ // check leftward step
        if(x > 0 && (_rightwalls[y * _width + (x-1)] == false)) // is this valid for array and rt wall?
            return true;
    }
    else if (dir == 3){ // check upward step
        if(y > 0 && (_bottomwalls[(y-1) * _width + x] == false)) // is this valid for array and rt wall?
            return true;
    }
    //else
    return false;
}
void SquareMaze::setWall(int x, int y, int dir, bool exists){
    // 0 = rwall; 1 = dwall; assuming rwall = | and dwall = _ ? 
    int index = y * _width + x;
    if(dir == 0){   // right
        _rightwalls[index] = exists;
    }
    else if(dir == 1){  // bottom
        _bottomwalls[index] = exists;
    }
}
// vector<int> SquareMaze::solveMaze() {
//     int size = _width * _height;
//   vector<int> length(size, -1); //Fill them in with temp values. Width * height = max. possible length.
//   vector<int> path(size, 0);
//   vector<int> previous(size, 0);
//   queue<int> q; //For backtracking purposes.
//   q.push(0);

//   while(!q.empty()) { //Where maze solving actually happens
//     int index = q.front();
//     int x = index%_width;
//     int y = index/_width;
//     if (canTravel(x, y, 0) && length[index + 1] < 0) {
//       length[index + 1] = length[index] + 1; //Increment length
//       path[index + 1] = 0;
//       previous[index + 1] = index;
//       q.push(index + 1);
//     }
//     if (canTravel(x, y, 1) && length[index + _width] < 0) {
//       length[index + _width] = length[index] + 1;
//       path[index + _width] = 1;
//       previous[index + _width] = index;
//       q.push(index + _width);
//     }
//     if (canTravel(x, y, 2) && length[index - 1] < 0) {
//       length[index - 1] = length[index] + 1;
//       path[index - 1] = 2;
//       previous[index - 1] = index;
//       q.push(index - 1);
//     }
//     if (canTravel(x, y, 3) && length[index - _width] < 0) {
//       length[index - _width] = length[index] + 1;
//       path[index - _width] = 3;
//       previous[index - _width] = index;
//       q.push(index - _width);
//     }
//     q.pop();
//   }

//   int longestPathIndex = -1;
//   int longestDist = -1;

//   //Find the path with longest length in the last row
//   for (int i = (_height - 1) * _width; i < _width * _height; i++) {
//     if (length[i] > longestDist) {
//       longestPathIndex = i;
//       longestDist = length[i];
//     }
//   }

//   vector<int> result;
//   while (longestPathIndex > 0) { //Actually push the path in to vector but starts from bottom
//     result.push_back(path[longestPathIndex]);
//     longestPathIndex = previous[longestPathIndex];
//   }

//   reverse(result.begin(), result.end());

//   return result;
// }
vector <int> SquareMaze::solveMaze(){
    // how to guarantee linear time check? 
    vector<int> path(_width * _height, 0);
    vector<int> visited(_width * _height, 0);
    vector<int> pathlength(_width * _height, -1); 
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
            pathlength[((i.second+1)%_height) * _width + (i.first%_width)] = pathlength[(i.second%_height) * _width + ((i.first)%_width)] +1; // increment by 1, not sure about this
            queue.push({i.first, i.second+1});    // does this work? 
            if( (i.second+1) % _height == _height -1)
                options.push({i.first,i.second+1}); // store another list of all valid possibilities
        }
        //up
        if (canTravel(i.first % _width, i.second % _height, 3) && visited[((i.second-1)%_height) * _width + (i.first%_width)] == 0){
            path[((i.second-1)%_height) * _width + ((i.first)%_width)] = 3; // set path to left, should this just be i.first or i.first-1? 
            visited[((i.second-1)%_height) * _width + (i.first%_width)] = 1; // if visited, set to 1
            pathlength[((i.second-1)%_height) * _width + (i.first%_width)] = pathlength[(i.second%_height) * _width + ((i.first)%_width)] +1; // increment by 1, not sure about this
            queue.push({i.first, i.second-1});    // does this work? 
        }
        queue.pop();
    }
    // for loop through the last row and check the largest distance by using the path
    
    pair<int, int> x = options.front();
    int longestlength = pathlength[(x.second%_height) * _width + ((x.first)%_width)];
    options.pop(); 
    while(!options.empty()){    // infinite looping here
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
            if(_rightwalls[j * _width + i] == true){
                for(int k = 0; k < 11; k++){
                    HSLAPixel & pixel = themaze->getPixel((i+1)*10,j*10+k);
                    pixel.l = 0;//darken
                }
            }
            if(_bottomwalls[j * _width + i] == true){
                for(int k = 0; k < 11; k++){
                    HSLAPixel & pixel = themaze->getPixel(i*10+k,(j+1)*10);
                    pixel.l = 0;    //darken
                }
            }
            if((_rightwalls[j * _width + i] == true) && (_bottomwalls[j * _width + i] == true)){
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
        if (solution[i] == 0){    // R
            for( int j = 0; j < 11; j++){
                HSLAPixel & pixel = mazesolution->getPixel((point.first + j), point.second);
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
            }
            point.first = point.first + 10;
        }
        else if (solution[i] == 1){    // D
            for( int j = 0; j < 11; j++){
                HSLAPixel & pixel = mazesolution->getPixel(point.first, (point.second+j));
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
            }
            point.second = point.second + 10;
        }
        else if (solution[i] == 2){    // L
            for( int j = 0; j < 11; j++){
                HSLAPixel & pixel = mazesolution->getPixel((point.first-j), point.second);
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
            }
            point.first = point.first -10;
        }
        else if (solution[i] == 3){    // U
            for( int j = 0; j < 11; j++){
                HSLAPixel & pixel = mazesolution->getPixel(point.first, (point.second-j));
				pixel.h = 0;
				pixel.s = 1.0;
				pixel.l = 0.5;
            }
            point.second = point.second -10;
        }
    }
    // getthe last cell, check this
    int x = point.first/10;
    int y = _height-1;
    // whiten the exit
    for (int k = 1; k < 10; k++){
        HSLAPixel & pixel = mazesolution->getPixel(x*10+k, (y+1)*10);    // the other coordinate part 
        pixel.l = 1;    // whiten
        pixel.a = 1;
    }
    return mazesolution;
}