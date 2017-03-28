#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include "linkedlist.h"



template <typename T>
struct Leftist_Node
{
  T value;
  Leftist_Node *left_node;
  Leftist_Node *right_node;
  int rank;
  Leftist_Node( const T & new_value, Leftist_Node *left, Leftist_Node *right, int r = 0 )
  : value(new_value), left_node(left), right_node(right),rank(r) { }; // trying a different way to make a constructor

};

template <typename T>
class Leftist_Heap
{
public:
Leftist_Heap(): root(NULL){};
void insert( T value);
void deletemin();
Leftist_Node<T>* merge(Leftist_Node *t1,Leftist_Node *t2 );
void swap(Leftist_Node *t1,Leftist_Node *t2 )
{
  Leftist_Node<T>* temp= t1;
  t1 = t2;
  t2 =temp;

};
void preorder();
void inorder();
void levelorder();
private:
Leftist_Node<T>* root;

void preorder(Leftist_Node<T>*  & tree);
void inorder(Leftist_Node<T>*  & tree);


};
#include "leftist_heap.hpp"

#endif
