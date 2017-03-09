#ifndef K_heap_H
#define K_heap_H
#include <iostream>
#include <math.h>

template <typename T>
class k_heap {
private:
  int k;

  T* heap;
  int max_size;
  int size;

public:
  k_heap (int k, int max_size ): k(k), size(0), max_size(max_size)
  {
      heap = new T[max_size];
  };
  virtual ~k_heap ();
  // here to make a max k heap very quickly
  virtual bool comparsion( T x, T y){  return x<y;  }
  int getparent(int i){return floor((i-1)/k);};
  int eldestchild(int i){return (k* i + 1); };
  virtual void deletemin() { remove_node_location(0);  };



  void insert( T value );
  void remove_node(T value);
  void remove_node_location(int i);

  void heapify_down(int location);
  void heapify_up(int location);


  virtual void deletemax();
  void drake( T A[], int size); // build bottom up style
  void levelorder();

};
#endif
#include "min-kheap.hpp"
