#include "skew_heap.h"
#include "leftist_heap.h"
#include <fstream>
#include "Timer.cpp"



int main(int argc, char const *argv[]) {
  /* code */
  std::cout << "hi" << std::endl;
  long* randomnums;
  Timer time1;
  double x;
  int n= 50000;
  double leftist_times[8][7];
  double skew_times[8][7];

  leftist_times[0][0]=n;
  leftist_times[4][0]=n;
  skew_times[0][0]=n;
  skew_times[4][0]=n;
  for(int i= 1; i<4; i++)
  {
    leftist_times[i][0]=leftist_times[i-1][0]*2;
    leftist_times[i+4][0]=leftist_times[i-1][0]*2;
    skew_times[i][0]=leftist_times[i-1][0]*2;
    skew_times[i+4][0]=leftist_times[i-1][0]*2;
  } // stores n values

  for( int i = 0; i<4; i++) // loop for n values
  {
    n= n*2;
    Leftist_Heap<long>* left_heap = new Leftist_Heap<long>();
    Skew_Heap<long>* skew= new Skew_Heap<long>();
    randomnums=new long[n];
    std::cout << "next n" << std::endl;
    for (int key=0; key< 5; key++) // for the five keys
    {
      srand(key); // sets  random

      for (int j=0 ; j< n ; j++)
      {
        randomnums[j]= rand() % (4*n) +1;

      }
      time1.start();

      for (int j=0 ; j< n ; j++)
      {
        left_heap->insert(randomnums[j]);
      }
      leftist_times[i][key +1]=time1.stop();

      time1.start();
      for (int j=0 ; j< n ; j++)
      {
        skew->insert(randomnums[j]);
      }
      skew_times[i][key +1]=time1.stop();
      srand(key);
      time1.start();//reseting for new nums
      for (int j=0 ; j< n/10 ; j++)
      {
        x=(double)randomnums[j]/(4*n);

        if(x<0.5)
        {
            left_heap->deletemin();
        }else
          left_heap->insert((rand() % (4*n) +1));


      }
      leftist_times[i+4][key +1]=time1.stop();

      srand(key);
      time1.start();//reseting for new nums
      for (int j=0 ; j< n/10 ; j++)
      {
        x=(double)randomnums[j]/(4*n);

        if(x<0.5)
        {
            skew->deletemin();
        }else
            skew->insert((rand() % (4*n) +1));


      }
      skew_times[i+4][key +1]=time1.stop();

    }
    delete(left_heap);
    delete(skew);
    delete(randomnums);

  }
      std::cout << "\n leftist_heap : build time \n " << std::endl;
  for( int i = 0; i<8; i++) // loop for n values
  {
    for (int j=0 ; j< 6 ; j++)
    {
      if(i==4)
        std::cout << "delete and insert " << std::endl;
      if (j==6) {
        leftist_times[i][6]= leftist_times[i][6]/5;
      }
      if(j>0 && j!=6)
      {
        leftist_times[i][6]= leftist_times[i][6]+leftist_times[i][j];
      }
      std::cout << leftist_times[i][j] << " ";
    }
    std::cout << "\n";

  }
    std::cout << "\n skew_heap : build time \n " << std::endl;
  for( int i = 0; i<8; i++) // loop for n values
  {
    skew_times[i][6]=0.0;
    if(i==4)
      std::cout << "delete and insert " << std::endl;
    for (int j=0 ; j< 7 ; j++)
    {
      if (j==6) {
        skew_times[i][6]= skew_times[i][6]/5;
      }
      if(j>0 && j!=6)
      {
        skew_times[i][6]= skew_times[i][6]+skew_times[i][j];
      }
      std::cout << skew_times[i][j] << " ";
    }
    std::cout << "\n";

  }

};
