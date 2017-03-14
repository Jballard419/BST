template <typename T>
int min_max_heap<T>::num_grandchild(int i)
{
    int eldest= eldestgrandchild(i);
    int num= size - eldest;
    if (num<0)
      return 0;
    if(eldestgrandchild(eldestchild(i))<size )
    {
      num =1;
      for (int j=0;j<getlevel(eldestgrandchild(i));j++)
      {
        num=k*num;
      }


    } // if greater then grandchild
    return num;
};

template <typename T>
int min_max_heap<T>::find_min_desecent(int i)
{
  int grandkids=num_grandchild(i);
  int eldest =eldestchild(i);
  int smallest = eldest;
  if (grandkids ==0)
  {

    for(int j= 0; j<k; j++)
    {
      if(eldest+j >= size)
      {
        break;
      }
      if(heap[smallest]>heap[eldest+j])
      {
        smallest= eldest+j;
      }
    }
  return smallest;
  //  compare only children
  }
   eldest=  eldestgrandchild(i);
   smallest= eldest;
  // compare grandkids
  for(int j =1; j<grandkids; j++)
  {
    if(heap[smallest]>heap[eldest+j])
    {
      smallest= eldest+j;
    }
  };
  eldest=eldestchild(i);

  //compare akward uncles that have no children
  for( int j =k-1; j> 0; j--)
  {
    if( grandkids> j*k)
    {
      break;
    }
     if(heap[smallest]> heap[eldest +j])
     {
        smallest= eldest+j;
     }
  };
  return smallest;

}
template <typename T>
int min_max_heap<T>::find_max_desecent(int i)
{
  int grandkids=num_grandchild(i);
  int eldest=eldestchild(i);
  int smallest = eldest;
  if (grandkids ==0)
  {
    for(int j= 0; j<k; j++)
    {
      if(eldest+j >= size)
      {
        break;
      }
      if(heap[smallest]<heap[eldest+j])
      {
        smallest= eldest+j;
      }
    }
  return smallest;
  //  compare only children
  }
   eldest=  eldestgrandchild(i);
   smallest= eldest;
  // compare grandkids
  for(int j =1; j<grandkids; j++)
  {
    if(heap[smallest]<heap[eldest+j])
    {
      smallest= eldest+j;
    }
  };
  eldest=eldestchild(i);

  //compare akward uncles that have no children
  for( int j =k-1; j> 0; j--)
  {
    if( grandkids> j*k)
    {
      break;
    }
     if(heap[smallest]< heap[eldest +j])
     {
        smallest= eldest+j;
     }
  };
  return smallest;

}
template <typename T>
void min_max_heap<T>::trickledown(int i)
{
  if(isMinlevel(i))
    return trickledown_min(i);
  return trickledown_max(i);


};
template <typename T>
void min_max_heap<T>::trickledown_min(int i)
{
  int m;
  if(eldestchild(i)<size)
    m = find_min_desecent(i);

    if(getgrandparent(m)==i) // m is a grand kid
    {
      if(heap[m]<heap[i])
      {
        swap(m,i);
        if (heap[m]> heap[getparent(m)])
          swap(m, getparent(m));
        trickledown_min(m);
      }

    }else{

      if(heap[m]<heap[i])
      {
        swap(m,i);
      }
    };
    return;

};
template <typename T>
void min_max_heap<T>::trickledown_max(int i)
{
  int m;
  if(eldestchild(i)<size)
    m = find_max_desecent(i);

    if(getgrandparent(m)==i) // m is a grand kid
    {
      if(heap[m]>heap[i])
      {
        swap(m,i);
        if (heap[m]< heap[getparent(m)])
          swap(m, getparent(m));
        trickledown_max(m);
      }

    }else{

      if(heap[m]>heap[i])
      {
        swap(m,i);
      }
    };
    return;

};
template <typename T>
void min_max_heap<T>::bubbleup(int i)
{

  if(isMinlevel(i))
  {
    if(i!= 0  && heap[i]>heap[getparent(i)])
    {
      swap( i, getparent(i));
      bubbleup_max(getparent(i));
    }else
    {
        bubbleup_min(i);
    }

  }else
  {
    if(i!= 0  && heap[i]<=heap[getparent(i)])
    {
      swap( i, getparent(i));
      bubbleup_min(getparent(i));
    }else
    {
        bubbleup_max(i);
    }

  }


}
template <typename T>
void min_max_heap<T>::bubbleup_min(int i)
{
  if(getgrandparent(i)!= -1)
  {
    if(heap[i]<heap[getgrandparent(i)])
    {
      swap(i, getgrandparent(i));
      bubbleup_min(getgrandparent(i));
    }
  }
  return;

}
template <typename T>
void min_max_heap<T>::bubbleup_max(int i)
{
  if(getgrandparent(i)!= -1)
  {
    if(heap[i]>heap[getgrandparent(i)])
    {
      swap(i, getgrandparent(i));
      bubbleup_max(getgrandparent(i));
    }
  }
  return;

}
template <typename T>
void min_max_heap<T>::insert( T value)
{
  heap[size]= value;
  size++;
  bubbleup(size-1);
  return;

}
template <typename T>
void min_max_heap<T>::deletemin()
{

  size --;
  heap[0]=heap[size];
  heap[size]= -1;
  trickledown_min(0);
}
template <typename T>
void min_max_heap<T>::deletemax()
{
  size--;
  if(size<1 )
  {
    size = 0;
    heap[size]= -1;

  }
  int largest= 1;

  for(int j=2; j<=k; j++)
  {
    if(j>=size)
    {
      break;
    }
    if(heap[j]> heap[largest])
    {
      largest=j;
    }

  }
  heap[largest]=heap[size];
  heap[size]=-1;
  trickledown_max(largest);

}
template <typename T>
void min_max_heap<T>::bottom_up( T A[], int size_new)
{
  size = size_new;
  for (int i = 0; i < size; i++) {
    heap[i]= A[i];
  };
  for (int i = (floor(size/k) -1); i>-1; i--)
  {
      trickledown(i);
  }

}
template <typename T>
void min_max_heap<T>::levelorder()
{
  int temp = 1;
  int help=0; // offset need to make it work
  for (int i = 0; i < size; i++) {
    std::cout << heap[i] << ' ';
    if((i- help)%temp==0)
    {
      std::cout << '\n';
      temp=temp*k;
      help=i; // who needs cmath;
    }else if ( i % k ==0)
    {
      std::cout << " - ";
    }
  }

}
template <typename T>
void min_max_heap<T>::swap(int a, int b)
{
  T temp = heap[a];
  heap[a]= heap[b];
  heap[b]= temp;
  return;

}
template <typename T>
min_max_heap<T>::~min_max_heap()
{
  delete(heap);
  return;

}
