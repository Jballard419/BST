#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include "linkedlist.h"



template <typename T>
struct Binary_Node
{
  T value;
  Binary_Node *left_node;
  Binary_Node *right_node;
  Binary_Node( const T & new_value, Binary_Node *left, Binary_Node *right )
  : value(new_value), left_node(left), right_node(right) { }; // trying a different way to make a constructor

};

template <typename T>
class BST
{
public:
BST(): root(NULL){};
void insert( T value);

void remove(T value);

Binary_Node<T>* search (T value);

T deletemin();
T deletemax();
void preorder();
void inorder();
void levelorder();


private:
Binary_Node<T>* root;
void insert( T value, Binary_Node<T>*  & tree);

void remove(T value,Binary_Node<T>*  & tree);

Binary_Node<T>* search (T value,Binary_Node<T>*  & tree);

T deletemin(Binary_Node<T>*  & tree);
T deletemax(Binary_Node<T>*  & tree);
void preorder(Binary_Node<T>*  & tree);
void inorder(Binary_Node<T>*  & tree);


};
#include "binary_seach_tree.hpp"

#endif
