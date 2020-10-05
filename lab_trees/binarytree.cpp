/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
using namespace std;
/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirrorhelper(root);

}
// helper function for mirror()
template <typename T>
void BinaryTree<T>::mirrorhelper(Node* subRoot){
    if (subRoot == NULL)
        return;
    
    Node *oldright = subRoot->right;
    subRoot->right = subRoot->left;
    subRoot->left = oldright;
   
    mirrorhelper(subRoot->left);
    mirrorhelper(subRoot->right);
}
    

/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    InorderTraversal <int> traversal(this->getRoot());
    Node * prev = NULL;
    for (auto it = traversal.begin(); it != traversal.end(); ++it) {
        if(prev != NULL && prev->elem > (*it)->elem)
            return false;
        prev = (*it);
    }
    return true;
    
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    return isOrderedRecursivehelper(root);
}

template <typename T>
bool BinaryTree<T>::isOrderedRecursivehelper(const Node* subRoot) const{
    // checking leftmost of the right node and rightmost of the left node
    if (subRoot->right != NULL){
        if (leftmosthelper(subRoot->right)->elem < subRoot->elem)
            return false;
    }
    if (subRoot ->left != NULL){
        if (rightmosthelper(subRoot->left)->elem > subRoot->elem)
            return false;
    }
    // if (subRoot->left != NULL && subRoot ->right != NULL){ // does this work for all cases? 
    //     if (!isOrderedRecursivehelper(subRoot->left) || !isOrderedRecursivehelper(subRoot->right))
    //      return false;
    // } // or have to split into ... otherwise not checking through every single node?
    if (subRoot ->left != NULL){
        if (!isOrderedRecursivehelper(subRoot->left))
            return false;
    }
    if (subRoot ->right != NULL){
        if (!isOrderedRecursivehelper(subRoot->right))
            return false;
    }
    return true;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::leftmosthelper(typename BinaryTree<T>::Node *subRoot) const{
    if (subRoot == NULL)
        return NULL;
    else if (subRoot ->left == NULL)
        return subRoot;
    return leftmosthelper(subRoot->left);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::rightmosthelper(typename BinaryTree<T>::Node *subRoot) const{
    if (subRoot == NULL)
        return NULL;
    else if (subRoot ->right == NULL)
        return subRoot;
    return leftmosthelper(subRoot->right);
}
