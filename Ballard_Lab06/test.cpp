#include "binary_seach_tree.h"
#include "min-kheap.h"
#include <fstream>
#include "Timer.cpp"



int main(int argc, char const *argv[]) {
  /* code */
  std::cout << "hi" << std::endl;
  long* randomnums;
  Timer time1;
  double x;
  int n= 50000;
  double heap_times[8][7];
  double BST_times[8][7];

  heap_times[0][0]=n;
  heap_times[4][0]=n;
  BST_times[0][0]=n;
  BST_times[4][0]=n;
  for(int i= 1; i<4; i++)
  {
    heap_times[i][0]=heap_times[i-1][0]*2;
    heap_times[i+4][0]=heap_times[i-1][0]*2;
    BST_times[i][0]=heap_times[i-1][0]*2;
    BST_times[i+4][0]=heap_times[i-1][0]*2;
  } // stores n values

  for( int i = 0; i<4; i++) // loop for n values
  {
    n= n*2;
    k_heap<long>* min_heap = new k_heap<long>(3, (n + n/10));
    BST<long>* tree= new BST<long>();
    randomnums=new long[n];
    std::cout << "next n" << std::endl;
    for (int key=0; key< 5; key++) // for the five keys
    {
      srand(key); // sets  random
      std::cout << "next key" << std::endl;
      for (int j=0 ; j< n ; j++)
      {
        randomnums[j]= rand() % (4*n) +1;

      }
      time1.start();

      min_heap->drake(randomnums, n);
      heap_times[i][key +1]=time1.stop();

      time1.start();
      for (int j=0 ; j< n ; j++)
      {
        tree->insert(randomnums[j]);
      }
      BST_times[i][key +1]=time1.stop();
      srand(key);
      time1.start();//reseting for new nums
      for (int j=0 ; j< n/10 ; j++)
      {
        x=(double)randomnums[j]/(4*n);

        if(x<0.1)
        {
            //min_heap->deletemin();
        }else if (x< 0.2)
        {
            //min_heap->deletemax();
        }else if (x<1) {
          min_heap->insert((rand() % (4*n) +1));
        }else
        {
          //min_heap->remove_node((rand() % (4*n) +1));
        }

      }
      heap_times[i+4][key +1]=time1.stop();

      srand(key);
      time1.start();//reseting for new nums
      for (int j=0 ; j< n/10 ; j++)
      {
        x=(double)randomnums[j]/(4*n);

        if(x<0.1)
        {
            tree->deletemin();
        }else if (x< 0.2)
        {
            tree->deletemax();
        }else if (x<0.5) {
            tree->insert((rand() % (4*n) +1));
        }else
        {
          tree->remove((rand() % (4*n) +1));
        }

      }
      BST_times[i+4][key +1]=time1.stop();

    }
    delete(min_heap);
    //delete(tree);
    delete(randomnums);

  }
  for( int i = 0; i<8; i++) // loop for n values
  {
    for (int j=0 ; j< 6 ; j++)
    {
      if (j==6) {
        heap_times[i][6]= heap_times[i][6]/5;
      }
      if(j>0 && j!=6)
      {
        heap_times[i][6]= heap_times[i][6]+heap_times[i][j];
      }
      std::cout << heap_times[i][j] << " ";
    }
    std::cout << "\n";

  }
    std::cout << "\n binary_seach_tree \n " << std::endl;
  for( int i = 0; i<8; i++) // loop for n values
  {
    BST_times[i][6]=0.0;
    for (int j=0 ; j< 7 ; j++)
    {
      if (j==6) {
        BST_times[i][6]= BST_times[i][6]/5;
      }
      if(j>0 && j!=6)
      {
        BST_times[i][6]= BST_times[i][6]+BST_times[i][j];
      }
      std::cout << BST_times[i][j] << " ";
    }
    std::cout << "\n";

  }

}
