/* Your code here! */
#pragma once
#include "cs225/PNG.h"
#include "dsets.h"
#include <vector>

class SquareMaze
{
  public:
    SquareMaze();
    void makeMaze(int width,int height);  // maze constructor
    bool canTravel(int x, int y, int dir) const;  // determines if can travel a certain direction from a point
    void setWall(int x, int y, int dir, bool exists); // sets the wall 
    vector<int> solveMaze();  // finds the solution of the maze
    cs225::PNG * drawMaze()const; // draws the maze
    cs225::PNG * drawMazeWithSolution();  // draws the solution of the maze with the red lines
  private: 
    int _width; // width of the maze
    int _height;  // height of the maze
    vector <bool> _rightwalls;  // vectors for whether the right and/or bottom walls exist 
    vector <bool> _bottomwalls;
    DisjointSets dset;  // disjoint set 
};