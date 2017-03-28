template <typename T>
Skew_Heap<T>::~Skew_Heap()
{
  int j;
  while(root != NULL)
  {
    j= deletemin();
  }
  return;
}
template <typename T>
Skew_Node<T>* Skew_Heap<T>:: merge(Skew_Node<T>* t1,Skew_Node<T>* t2 )
{
  if(t1==NULL)
    return t2;
  if(t2==NULL)
    return t1;
  if(t1->value>t2->value)
  {
    Skew_Node<T>* temp= t1;
    t1 = t2;
    t2 =temp;

  }

    // now
    Skew_Node<T>* temp = t1->right_node;
    t1->right_node = t1->left_node;
    t1->left_node = merge(temp, t2);
    return t1;

}

template <typename T>
void Skew_Heap<T>:: insert(T value)
{
  root= merge(root, new Skew_Node<T>(value, NULL, NULL));

};
template <typename T>
void Skew_Heap<T>:: deletemin()
{
  if(root == NULL)
    return;
  Skew_Node<T>* temp = root;
  root = merge(root->left_node, root->right_node);
  delete temp;
}

template <typename T>
void Skew_Heap<T>::preorder()
{
  preorder(root);
}
template <typename T>
void Skew_Heap<T>::inorder()
{
  inorder(root);
}
template <typename T>
void Skew_Heap<T>::preorder(Skew_Node<T>*  & tree)
{
  if( tree == NULL)
  {
    return;
  }
  std::cout << tree -> value <<" " ;
  preorder(tree -> left_node);
  preorder(tree-> right_node);
  return;

}

template <typename T>
void Skew_Heap<T>::inorder(Skew_Node<T>*  & tree)
{
  if( tree == NULL)
  {
    return;
  }
  inorder(tree -> left_node);
  std::cout << tree -> value <<" " ;
  inorder(tree-> right_node);
  return;

}

template <typename T>
void Skew_Heap<T>::levelorder()
{
  linkedlist<Skew_Node<T>*>* queue= new linkedlist<Skew_Node<T>*>();
  queue->insert(root);
  queue->insert(NULL);// add root

  while(!(queue->isEmpty()))
  {
    Skew_Node<T>* temp = queue->pop();
    if(temp != NULL)
    {
      if(temp->left_node!=NULL)
        queue->insert(temp->left_node);
      if(temp->right_node != NULL)
        queue->insert(temp->right_node);
      //empty=false;
      std::cout << temp-> value << " ";

    }else
    {
         std::cout << "\n" ;
       if(!(queue->isEmpty()))
        queue->insert(NULL);
    }
  }

}
