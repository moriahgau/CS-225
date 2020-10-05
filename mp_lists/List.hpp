/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_ = 0;
}// not sure what to do here? 

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode *currentnode = head_;
  while(currentnode != NULL){
    ListNode *nextnode = currentnode->next;
    delete currentnode; 
    currentnode = nextnode;
    length_--;
  }
  head_ = NULL;
  tail_ = NULL;
  length_ =0;

}


/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata); // need to delete in destructor to avoid leak? 
  if(head_ != nullptr){
    newNode -> next = head_;
    newNode -> prev = NULL;
    head_->prev = newNode;
    head_ = newNode; 
  }
  
  else{
    newNode->prev = NULL;
    newNode->next = NULL;
    head_ = newNode;
    tail_ = newNode;
  }  

  length_++;

}
/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata); // need to delete in destructor to avoid leak? 
  if(tail_ != nullptr){
    newNode -> next = NULL;
    newNode -> prev = tail_;
    tail_->next = newNode;
    tail_ = newNode; 
  }
  else{
    newNode->prev = NULL;
    newNode->next = NULL;
    head_ = newNode;
    tail_ = newNode;
  }  
  length_++;
}

// template <typename T>
// typename List< T >::split(int splitPoint){
// List<T> secondlist;
// int pastlength = length_;
// if (splitPoint > length_)
// 	return List<T>();
// if else (splitPoint < 0)
// 	splitPoint = 0;
// ListNode * headtwo= split(head_, splitPoint);
// secondlist.length_ = pastlength - splitPoint;
// if(headtwo == head_){
// 	headtwo = NULL;
// 	secondlist.head_ = headtwo;
// 	secondlist.tail_ = NULL;
// 	secondlist.length_ = 0;
// }
// else{
// 	secondlist.tail_ = headtwo;
// 	secondlist.head = headtwo;
// 	while(secondlist.tail_->next != NULL)
// 		secondlist.tail_ = secondlist.tail_->next;
// 	}
// return secondlist;
// }

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1 // do I need to check if curr is NULL? 
  ListNode * curr = start;
if (splitPoint >= length_)
	return NULL; //  a,b,c,d 5
else if (splitPoint == 0)
  return head_;
for (int i = 0; i < splitPoint; i++ ) {
    if(curr == NULL)
      return NULL;
    curr = curr->next;
  }
  tail_ = curr->prev;
  curr->prev->next = NULL;
  curr->prev = NULL;
  return curr;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */   
template <typename T>
void List<T>::tripleRotate() {
  //@todo Graded in MP3.1
  //int count = 1; // a,b,c —> b,c,a
  ListNode *tempa = nullptr;
  ListNode *tempb = nullptr;
  ListNode *tempc = nullptr;
  ListNode *tempbprevious = nullptr;
  ListNode *individualhead = head_;
  //while(individualhead != NULL){	
  while (true){
   //if(count%3 == 0){  // while loop instead? for a,b,c   ,d,e,f,   g; b,c,a, e,f,d
    //if(length_ - count >3){
      //for(i = individualhead; i < count + 3; i++){
        //individualhead->prev = individualhead->next->next->next; //not sure how to connect a to e here
        if (individualhead!=NULL)
          tempa = individualhead; 
        else
        {
            return;
        }
        
        if (individualhead->next!=NULL){
          tempb = individualhead->next;
        }
        else
        {
          return;
        }
        
        if (individualhead->next->next!=NULL)
          tempc = tempb->next;
        else
        {
          return;
        }
        if(tempa == head_)
          head_ = head_->next;
        //now rearrange, infinite loop starts: a,b,c,d,e,f,g --   b,c,a,   e,f,d, g
        
        //tempa->prev = tempbprevious;
        //tempbprevious = tempa;
        if (tempbprevious != NULL)
          tempbprevious->next = tempb;
        tempa->prev = tempc;
        tempa->next = tempc->next;
        if (tempc->next !=NULL)
          tempc->next->prev = tempa;
        tempc->next = tempa;
        tempc->prev = tempb;
        tempb->next = tempc;
        tempb->prev = tempbprevious;
        individualhead = tempa->next;;
        tempbprevious = tempa;
        
        
        

      // a to e
      // count = count + 3;
      //cout <<*this<<endl;
    //}
  }
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  //     for (ListNode* i = startPoint; i != endPoint; i = i->next){
  //   cout << i->data <<endl;
  // }
  if (startPoint == NULL  || endPoint == NULL)
    return;
  if (startPoint == endPoint)
    return;
  ListNode *head = startPoint; // (7), 1,2,3 (4)
  ListNode *tail = endPoint; //tail = 3
  ListNode *temp = startPoint; // temp = 1
  ListNode *afteroldtail = endPoint ->next; // afteroldtail = 4;
  ListNode *beforeoldhead = head->prev; // beforeoldhead = 7;
  
    while (head != afteroldtail){ // swapping the directions in the list   
    ListNode *secondtemp = head->prev; // temp = 7
    head->prev = head->next; // 1->prev = 2
    head->next = secondtemp; // 1->next = 7
    head = head->prev; // head = 2
  }

  // startPoint->prev = afteroldtail;
  startPoint = endPoint; // startpoint is now 3
  endPoint = temp; // endpoint is now 1
  startPoint->prev = beforeoldhead; // 3->prev = 7
  // 3->next     //(before = 7), 1,2,3 (afteroldtail = 4) --> 3,2,1

  if(beforeoldhead != NULL){
    beforeoldhead->next = startPoint; //7->next = 3
    startPoint->prev = beforeoldhead;
  }
  if (beforeoldhead == NULL){
    head_ = startPoint;
  }
  endPoint->next = afteroldtail; // 1->next = 4
  if(afteroldtail != NULL){
    afteroldtail->prev = endPoint; // 4->prev = 1
    // endPoint->next = afteroldtail;
  }
  if (afteroldtail == NULL){
    tail_ = endPoint;
  }
  //     for (ListNode* i = startPoint; i != endPoint; i = i->next){ //7,1,2,3,4
  //   cout << i->data <<endl;
  // }
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  // if (n > length_)
  //   reverse();
if (n < 1 || n == 1)
  return;
ListNode *start = head_; 
ListNode *end = head_;
while (start != NULL){  // should this be NULL? what if there's a list afterwards
  for (int i = 0; i < n-1; i++){ //1,2,3
    if (end->next == NULL)
      break;
    end = end->next; // end = 3, end = 6, end = 8
  }
  reverse(start, end);// 3,2,1,
  start = end->next; // start = 4, end = 3
  end = end->next;
}
return;
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  if (first == NULL)
    return second;
  else if (second == NULL)
    return first;
  // ListNode* first = firsthead;
  // ListNode* second = secondhead;
  ListNode* curr = NULL;
  if (first ->data < second->data){ 
    curr = first;
    first = first->next;
  }
  else{
    curr = second;
    second = second->next;
  }
  ListNode *temphead = curr; 
  while (first != NULL && second != NULL){
    if (first ->data < second->data){
      curr->next = first;
      first->prev = curr;
      curr = first;
      first = first->next;
     }
    else
    {
      curr->next = second;
      second->prev = curr;
      curr = second;
      second = second->next;
    }
  }
  if (first != NULL && second == NULL){
    curr->next = first;
    first->prev = curr;
  }
  else if (first == NULL && second != NULL){
    curr->next = second;
    second->prev = curr;
  }
  return temphead;
  }

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T> // is this the helper function we make or is there another one? do we make one called sort?
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if(start == NULL || start->next == NULL)
    return start;
  ListNode * second = split(start, chainLength/2);
  return merge(mergesort(start, chainLength/2), mergesort(second, chainLength-chainLength/2));
}


