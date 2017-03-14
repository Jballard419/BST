
template <typename T>
void k_heap<T>::heapify_down(int location)
{
  if((location>= floor(size/k)))
  { return;}
  int child=eldestchild(location);
  int lowest_kid=child;
  int i= 1;
  while(i < k)
  {
    if ((child+i)>= size) { break; /* empty node */ };

    if(comparsion(heap[child+i], heap[lowest_kid] ))
      lowest_kid = child +i;
    i++;
  }
  if(comparsion(heap[lowest_kid], heap[location])  )
  {
    T temp = heap[lowest_kid];
    heap[lowest_kid]= heap[ location];
    heap[location]= temp;

    heapify_down(lowest_kid);
  }

  return;



}
template <typename T>
k_heap<T>::~k_heap()
{
  delete(heap);
  return;
}


template <typename T>
void k_heap<T>::insert( T value)
{
  int test=size;

  int adult=getparent(size);
  while (adult>=0 && test  != 0){

    if(comparsion(value , heap[adult])  )
    {
      ///heap[adult]= heap[ location];
      heap[test]= heap[adult];
      test = adult;
      adult= getparent(adult);
    }else
    {
      break;
    }
  };
  heap[test]= value;
  size ++;
  return ;
}
template <typename T>
void k_heap<T>::heapify_up( int location)
{
  if(location == 0){
    return;
  }

  int adult=getparent(location);


    if(comparsion(heap[location] , heap[adult])  )
    {
      T temp =heap[adult];
      heap[adult]= heap[ location];
      heap[location]= temp;

      heapify_up(adult);
    }



  return ;
}
template <typename T>
void k_heap<T>::remove_node_location(int i)
{



      size --;

      heap[i]=heap[size];
      heap[size] = -1;


      if(i != 0)
      {


      if( comparsion(heap[i], heap[getparent(i)]) )
      {
        heapify_up(i);
      }else
      {
          heapify_down(i);
      };
    } else
    {
        heapify_down(i);
    }


return;

};
template <typename T>
void k_heap<T>::remove_node(T val)
{
  if(val<heap[0]) {return;}
  int i = 0;
  while (i<size) {
    if ( val == heap [i])
    {
      size --;
      heap[i]=heap[size];
      if(i==size){ return;}
      if(i != 0)
      {
      if( comparsion(heap[i], heap[getparent(i)]) )
      {
        heapify_up(i);
      }else
      {
          heapify_down(i);
      };
    } else
    {
        heapify_down(i);
    }

        // shouldn't have to reset the loop;

    }else
    {
      i++;
    }
  }

};
template <typename T>
void k_heap<T>::drake(T A[], int size_new)
{
  size = size_new;
  for (int i = 0; i < size; i++) {
    heap[i]= A[i];
  };
  for (int i = (floor(size/k) -1); i>-1; i--)
  {
      heapify_down(i);
  }
}

template <typename T>
void k_heap<T>::deletemax()
{
  int low_index= heap[0];
  for (int i = floor(size-2/k)+1 ; i<size; i++)
  {
      if(comparsion(heap[low_index], heap[i]))
      {
        low_index = i;
      };

  }
  if(low_index= size -1)
  {
    size --;
  }
  remove_node_location(low_index);
}

template <typename T>
void k_heap<T>::levelorder()
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
