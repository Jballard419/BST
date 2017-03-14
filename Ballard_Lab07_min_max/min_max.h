#ifndef MIN_MAX_heap_H
#define MIN_MAX_heap_H
#include <iostream>
#include <math.h>


template <typename T>
class min_max_heap
{
private:
  int k;

  T* heap;
  int max_size;
  int size;
public:
  min_max_heap(int k, int max_size ): k(k), size(0), max_size(max_size)
  {
      heap = new T[max_size];
  };

  virtual ~min_max_heap();
  // helper funcitions
  int getparent(int i){return floor((i-1)/k);};
  int getgrandparent(int i){ return getparent(i)==0 ?-1: getparent(getparent(i));};
  void swap(int a, int b);
  bool isMinlevel(int i){ return 0==((int)floor(log(i+1)/log(k))%2);};
  int eldestchild(int i){return (k* i + 1); };
  int eldestgrandchild(int i){return eldestchild(eldestchild(i));};
  int getlevel(int i){ return floor(log(i+1)/log(k)); }; //TODO: k only works for 2
  int num_grandchild(int i);
  // used with trikle down

  int find_min_desecent(int i);
  int find_max_desecent(int i);

  //for bottom up and delete
  void trickledown(int i);
  void trickledown_min(int i);
  void trickledown_max(int i);
  // for insert
  void bubbleup(int i);
  void bubbleup_min(int i);
  void bubbleup_max(int i);

  // call able funcion
  void insert( T value );
  virtual void deletemin();
  virtual void deletemax();
  void levelorder();
  void bottom_up( T A[], int size);
};
 #endif
 #include "min_max.hpp"
