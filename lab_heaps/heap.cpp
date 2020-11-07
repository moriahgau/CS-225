
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
    return currentIdx * 2;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    return currentIdx * 2 + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return currentIdx / 2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    if (currentIdx*2 < _elems.size() || currentIdx*2+1 < _elems.size()) return true;
    return false;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    if (rightChild(currentIdx) >= _elems.size()) return leftChild(currentIdx);
    size_t left = leftChild(currentIdx);
    size_t right = rightChild(currentIdx);
    if (higherPriority(_elems[left], _elems[right])) return left;
    return right;
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    if (!hasAChild(currentIdx)) return;
    size_t priorityChild = maxPriorityChild(currentIdx); //index of child with highest priority
    if (higherPriority(_elems[priorityChild], _elems[currentIdx])) { //checking data of 'currentIdx' and 'priorityChild'
      std::swap(_elems[currentIdx], _elems[priorityChild]);
      heapifyDown(priorityChild);
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
    _elems.push_back(T()); //_elems.size() == 1
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    // @TODO Construct a heap using the buildHeap algorithm
    // _elems.push_back(elems);
    _elems.push_back(T());
    for (size_t i = 0; i < elems.size(); i ++){
      _elems.push_back(elems[i]);
    }
    //_elems.insert(_elems.end(), elems.begin(), elems.end());
    for (size_t s = parent(_elems.size()); s > 0; s--) { // remove the -1
      heapifyDown(s);
    }

}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    // @TODO Remove, and return, the element with highest priority
    if (empty()) return T();
    std::swap(_elems[root()], _elems[_elems.size()-1]);
    T result = _elems[_elems.size()-1];
    _elems.pop_back();
    heapifyDown(root());
    return result;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    return _elems[root()];
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    // @TODO Add elem to the heap
    _elems.push_back(elem);
    heapifyUp(_elems.size()-1);
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
    // _elems[idx+1] = elem;
    //heapifyUp(idx+1);
    T oldElem = _elems[idx];
    _elems[idx] = elem;
    if (elem>oldElem) heapifyDown(idx);
    else heapifyUp(idx);
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
    if (_elems.size() <= 1) return true;
    return false;
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
