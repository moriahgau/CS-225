/* Your code here! */
#pragma once
#include <vector>
using namespace std;

class DisjointSets{
    public: 
    void addelements(int num);  // Creates n unconnected root nodes at the end of the vector
    int find(int elem); // compress paths and returns the index of the root of the up-tree
    void setunion(int a, int b);    // connects elements into a union
    int size(int elem); // returns the number of nodes in the elem's up-tree

    private:
    vector<int> elems;  // vector named elems filled with ints 


};