/* Your code here! */
#pragma once
#include "cs225/PNG.h"
#include "dsets.h"
#include <vector>

class SquareMaze
{
  public:
    SquareMaze();
    void makeMaze(int width,int height);
    bool canTravel(int x, int y, int dir) const;
    void setWall(int x, int y, int dir, bool exists);
    vector<int> solveMaze();
    cs225::PNG * drawMaze()const;
    cs225::PNG * drawMazeWithSolution();

};
