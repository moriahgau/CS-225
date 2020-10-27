/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if (curDim < 0 || curDim >= Dim)
      return false;
    if (first[curDim] < second[curDim])
      return true;
    else if (first[curDim] == second[curDim])
      return first<second;
    else 
      return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    double curr_distance = 0;
    double pot_distance = 0;
    for (int i = 0; i < Dim; i++){
      curr_distance = curr_distance + (target[i] - currentBest[i])*(target[i] - currentBest[i]);
      pot_distance = pot_distance + (target[i] - potential[i])*(target[i] - potential[i]);
    }
    if(pot_distance < curr_distance)
      return true;
    else if(pot_distance == curr_distance)
      return potential<currentBest;
    else
      return false;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
    for (size_t i = 0; i < newPoints.size(); i++){
      tpoints.push_back(newPoints[i]);
    }
    size = tpoints.size();
    root = buildTree(0, tpoints.size()-1, 0); // seg faulting here
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::buildTree(int start, int end, int dimension) {
  if (start > end)
    return NULL;
  if (start == end)
    return new KDTreeNode(tpoints[start]);
  // cout << "how about here?" << endl;
  else{ // find the median then run buildtree function recursivly: left start--> median; right median-->end
  int median = (start+end)/2;
  int nextdimen = (dimension+1)% Dim;
  quickselect(start, end, median, dimension);
  KDTreeNode * subroot = new KDTreeNode(tpoints[median]);
  subroot->left = buildTree(start, median - 1, nextdimen);
  subroot->right = buildTree(median + 1, end, nextdimen);
  return subroot;
  }
}
template <int Dim>
void KDTree<Dim>::swap(Point <Dim> &first, Point <Dim> &second)
{
  Point <Dim> temp = first;
  first = second;
  second = temp;
}
template <int Dim> // behaves like a mergesort, a recursive function
int KDTree<Dim>::partition( int left, int right, int pivotIndex, int dimension) // have to also check the dimension
{ 
    Point<Dim> pivotValue = tpoints[pivotIndex];
    swap (tpoints[pivotIndex], tpoints[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++) { 
        // if (tpoints[i] < pivotValue){
       if (smallerDimVal(tpoints[i], pivotValue, dimension)) { 
          swap(tpoints[storeIndex], tpoints[i]); 
          storeIndex++; 
        } 
    } 
    swap(tpoints[right], tpoints[storeIndex]); 
    return storeIndex; 
} 
template <int Dim> // behaves like a mergesort, a recursive function
Point<Dim> & KDTree<Dim>::quickselect(int start, int end, int k, int dimension) {
  if (start == end)
    return tpoints[start];
  int median = (start+end)/2;
  int pivotIndex = median;
  pivotIndex = partition(start, end, pivotIndex, dimension);
  if (k == pivotIndex)
    return tpoints[k];
  else if (k < pivotIndex)
    return quickselect(start, pivotIndex-1, k, dimension);
  else
    return quickselect(pivotIndex+1, end, k, dimension);
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
    this = new KDTree(other.tpoints);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if (*this != rhs){
    delete *this; 
    this = new KDTree(rhs);
  }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
  destroy(root);
}

template <int Dim>
void KDTree<Dim>::destroy(KDTreeNode * subroot) {
  /**
   * @todo Implement this function!
   */
  if (subroot == NULL)
    return;
  if (subroot->left != NULL)
    destroy(subroot->left);
  if (subroot->right != NULL)
    destroy(subroot->right);
  delete subroot;
  // subroot = NULL; 
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function! kind of lost on how to start
     */
    // DFS traverse through the entire tree and check distance between that and query point and want to return the shortest 
    
    //stored a nodeimmediately check its distance;
    //subroot->right = findNearestNeighbor();
    //check distance for the same point again? backtracing
   return fNN_helper(query, root, 0);
}

template <int Dim>
Point<Dim> KDTree<Dim>::fNN_helper(const Point<Dim>& query, KDTreeNode * subroot, int dimension) const
{
    Point<Dim> best = subroot->point;
    if (subroot->left == NULL && subroot->right == NULL)
      return best;
    if (smallerDimVal(query, subroot->point, dimension)) {
        if (subroot->left != NULL){
          best = fNN_helper(query, subroot->left, (dimension +1)% Dim);
        }
    }
    else{
      if(subroot->right != NULL){
        best = fNN_helper(query, subroot->right, (dimension + 1) % Dim);
      }
    }
    if (shouldReplace(query, best, subroot->point)){ // will best be the same as subroot->point here? 
      best = subroot->point;
    }
    double distance = radius(query, best);
    double splitplane = ((subroot->point[dimension])-query[dimension])*((subroot->point[dimension])-query[dimension]); // not sure how to calculate this? need to somehow connect to query
    cout << "splitplane" << splitplane << endl;
    if (splitplane <= distance){ // do i need to make another else if (splitplane == distance) where best < subroot->point? 
      Point <Dim> check = subroot->point;
      if (smallerDimVal(query, subroot->point, dimension)){
        if (subroot->right != NULL){
          Point <Dim> check = fNN_helper(query, subroot->right, (dimension+1)%Dim);
          if (shouldReplace(query, best, check))
            best = check;
        }
      }
      else{
        if (subroot->left != NULL){
          Point <Dim> check = fNN_helper(query, subroot->left, (dimension+1)%Dim);
          if (shouldReplace(query, best, check))
            best = check;
        }
      }
    }
    
    return best;

    //subroot->left = findNearestNeighbor();
     // check the distance between best and query as well as between subroot and query and update best to = the smaller one
    // subroot->right = 
    // check the distance between best and query as well as between subroot and query and update best to = the smaller one
    // finding if to check right after checking left?
}

template <int Dim> // behaves like a mergesort, a recursive function
double KDTree<Dim>::radius( const Point <Dim> & firstpoint, const Point <Dim> & secondpoint)const{ // want to ask about the reference point
  double radius = 0.0; 
  for (int i = 0; i < Dim; i++){
    radius = radius + (firstpoint[i]-secondpoint[i])*(firstpoint[i] - secondpoint[i]);
  }
  return radius;
}

