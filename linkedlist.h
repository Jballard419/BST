#ifndef linkedlist_H
#define linkedlist_H

#include "node.h"
#include <iostream>

template <typename T>
class linkedlist
{
    public:


	  linkedlist();

	 ~linkedlist();
	//in: the linkedlist
	//out: a bool to check if the linkedlist is empty
	//called when we want to make sure there is nothing in the stack

	//in: a value to store at the bottom of the linkedlist
	//out a new value at the bottom of the linkedlist
	//called: when the user wants to store a value in linkedlist

	 void insert(const T val);
	//in:
	//out the value at the top of the linkedlist
	//called: when the user wants to remove the value at the top of the linkedlist
	 void delete_node(const T val);

   T pop();

   void insert(const T val, node<T>* temp);
	//in:
	//out the value at the top of the linkedlist
	//called: when the user wants to remove the value at the top of the linkedlist
	 void delete_node(const T val, node<T>* temp);
	//in the linkedlist
	//out: the value at the top of the linkedlist
	//called: when the user wants to store the value at the top of the linkedlist without removing it
	 void reverse();

   void reverse(node<T>* test);

	 //in: the linkedlist
	 //out: a print out of everything inside the linkedlist
	 //called: when a print out of the linkedlist is required
	 void print() const;
   bool isEmpty();

 private:
  node<T>* m_top;






 };
 #include "linkedlist.hpp"
 #endif
