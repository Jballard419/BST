#ifndef node_H
#define node_H

template<typename T>
class node
{
public:
	//in:
	//out: a node that can store a T value and a pointer to a box
	//called: anytime a new box is made normally in Push
	node(T value);
	//in: val, and a box
	//out: a box holding that value
	//called: in push
	void setvalue(T val);
	//in:
	//out the value in the box
	//called: in push
	T getvalue();

	//in: a pointer and the pointer inside the box
	//out: the pointer inside the box referrers to the box the other pointer referrers to
	//called: in Push so we don't lose the previous box
	void setprevious(node* prev);
  void setnext(node* prev);

	//in: the box
	//out: the pointer inside the box
	//called: in Pop to find the previous box before deleting the top box
	node<T>* getprevious();
  node<T>* getnext();

	private:
	T m_value;
	node<T>* m_previous;
  node<T>* m_next; //pointer  making it a linked list

};

#include "node.hpp"

#endif
