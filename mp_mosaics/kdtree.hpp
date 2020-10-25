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
      curr_distance = curr_distance + (target[i] - curretBest[i])*(target[i] - curretBest[i]);
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
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    return Point<Dim>();
}

