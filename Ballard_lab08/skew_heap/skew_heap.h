#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include "linkedlist.h"



template <typename T>
struct Skew_Node
{
  T value;
  Skew_Node *left_node;
  Skew_Node *right_node;
  int rank;
  Skew_Node( const T & new_value, Skew_Node *left, Skew_Node *right, int r = 0 )
  : value(new_value), left_node(left), right_node(right),rank(r) { }; // trying a different way to make a constructor

};

template <typename T>
class Skew_Heap
{
public:
Skew_Heap(): root(NULL){};
void insert( T value);
void deletemin();
Skew_Node<T>* merge(Skew_Node *t1,Skew_Node *t2 );
void swap(Skew_Node *t1,Skew_Node *t2 )
{
  Skew_Node<T>* temp= t1;
  t1 = t2;
  t2 =temp;

};
void preorder();
void inorder();
void levelorder();
private:
Skew_Node<T>* root;

void preorder(Skew_Node<T>*  & tree);
void inorder(Skew_Node<T>*  & tree);


};
#include "skew_heap.hpp"

#endif
