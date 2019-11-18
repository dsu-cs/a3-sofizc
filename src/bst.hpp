#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include <vector>
#include "node.hpp"
using namespace std;

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
    void inorderHelper(std::vector<T>*, Node<T>*);
    Node<T>* insertHelper(int, Node<T>*);
};


template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}


template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;   
    inorderHelper(vec, root);
    return vec;
}

//fuction to assist with calls, since can't pass node into inorder function
template<class T>
void BST<T>::inorderHelper(std::vector<T>* vec, Node<T>* currentNode)
{
    if(currentNode != NULL) {
    
        inorderHelper(vec, currentNode->get_left());   
        vec->push_back(currentNode->get_data());      
        inorderHelper(vec, currentNode->get_right()); 
    }
}

template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
    root = insertHelper(new_data, root); //insert new data into bst recuservily
    node_count++;
}

template<class T>
Node<T>* BST<T>::insertHelper(int new_data, Node<T>* currentNode)
{
    if(currentNode == NULL)
    {   
        return new Node<T>(new_data);
    }
    else if(new_data < currentNode->get_data()) {
    
        currentNode->set_left(insertHelper(new_data, currentNode->get_left())); // move data left
    }
    else
    {
        currentNode->set_right(insertHelper(new_data, currentNode->get_right())); //move data right
    }
    return currentNode;    
}

template<class T>
Node<T> *BST<T>::search(T val)
{

}



template<class T>
void BST<T>::remove(T val)
{

}



template<class T>
int BST<T>::get_size()
{
    return node_count;
}