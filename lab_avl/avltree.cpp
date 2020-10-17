/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    if (t == NULL || t->right == NULL)
      return;

    Node * temp = t->right;
    t->right = temp->left;
    temp->left = t;
    t = temp;

    //need to recalculate height
    t->left->height = std::max(heightOrNeg1(t->left->left), heightOrNeg1(t->left->right)) + 1;
    t->height = t->height + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    if (t == NULL || t->left == NULL)
      return;

    Node * temp = t->left;
    t->left = temp->right;
    temp->right = t;
    t = temp;

    t->right->height = std::max(heightOrNeg1(t->right->right), heightOrNeg1(t->right->left)) + 1;
    t->height = t->height + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (subtree == NULL)
      return;
    //calculate balance factor
    int bf = heightOrNeg1(subtree->left) - heightOrNeg1(subtree->right);
    if (bf > 1) { // left heavy
      int lf = heightOrNeg1(subtree->left->left) - heightOrNeg1(subtree->left->right);
      if (lf == 1)
        rotateRight(subtree);
      else
        rotateLeftRight(subtree);
    }
    if (bf < -1) { // right heavy
      int rf = heightOrNeg1(subtree->right->left) - heightOrNeg1(subtree->right->right);
      if (rf == 1)
        rotateRightLeft(subtree);
      else
        rotateLeft(subtree);
    }

    subtree->height = std::max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == NULL)
      subtree = new Node(key,value);
    else if (key < subtree->key)
      insert(subtree->left,key,value);
    else if (key > subtree->key)
      insert(subtree->right,key,value);
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    // Node * temp = new Node();
    // temp = subtree;
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left,key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node * iop = subtree->left;
            while (iop->right != NULL)
              iop = iop ->right;
            swap(subtree, iop);
            remove(subtree->left, key); 
            // delete subtree;
            // subtree = NULL;
        } 
        else {
            /* one-child remove */
            // your code here
            if (subtree->right != NULL && subtree->left == NULL)
              {
                Node *temp = subtree; 
                subtree = subtree->right;
                delete temp;
              }
            else{
              Node *temp = subtree; 
              subtree = subtree->left;
              delete temp;
            // subtree = NULL;
            }
        // your code here
        // rebalance(subtree);
      }
    }
    rebalance(subtree); // because recursion,  want to rebalance every time
}