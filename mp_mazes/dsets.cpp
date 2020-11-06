/* Your code here! */
#include <iostream>
#include <cstdlib>
#include "dsets.h"
using namespace std;

void DisjointSets::addelements(int num){
    for (int i = 0; i < num; i++){
        elems.push_back(-1);    // add elems into the vector and initialize them all as -1
    }
}

int DisjointSets::find(int elem){
    if(elems[elem] < 0){ // check if root by seeing if it is a negative number 
        return elem; // if root, return
    }
    else{
        int foundroot = find(elems[elem]);  // recursively find up the uptree until the root is found
        elems[elem] = foundroot;    // compress paths
        return foundroot;   // return the root
    }
}

void DisjointSets::setunion(int a, int b){
    int first = find(a);    // find the root of a
    int second = find(b);   // find the root of b
    if (first == second)    // check if it's the same root
        return;
    else if (elems[first] > elems[second]){ // second is larger than first
        elems[second] = elems[second] + elems[first];   // updates second's size
        elems[first] = second;       // first points to second
    }
    else{    // for when first is greater than second or if the two are equal 
        elems[first] = elems[second] + elems[first];    // updates first's size
        elems[second] = first;       // second points to first
    } 

}

int DisjointSets::size(int elem){
    int root = find(elem);  // find the root 
    int size = -1 * elems[root];    // multiply by -1 since the vector stores a negative set size
    return size;
}
