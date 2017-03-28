template <typename T>
Leftist_Heap<T>::~Leftist_Heap()
{
  int j;
  while(root != NULL)
  {
    j= deletemin();
  }
  return;
}

template <typename T>
Leftist_Node<T>* Leftist_Heap<T>:: merge(Leftist_Node<T>*  t1,Leftist_Node<T>* t2 )
{
  if(t1==NULL)
    return t2;
  if(t2==NULL)
    return t1;
  if(t1->value > t2->value)
  {
    Leftist_Node<T>* temp= t1;
    t1 = t2;
    t2 =temp;

  };

    // now
  if(t1->left_node==NULL) // maybe his shou be a second funiction
  {
    t1->left_node =t2; // no need to change the rank
  }else
  {
    t1->right_node = merge(t1->right_node, t2);

    if(t1->left_node->rank < t1->right_node->rank)
    {
      Leftist_Node<T>* temp= t1->left_node;
      t1->left_node =  t1->right_node;
      t1->right_node =temp;
    }
    t1->rank = t1->right_node->rank +1;
  }
  return t1;
}

template <typename T>
void Leftist_Heap<T>:: insert(T value)
{
  root= merge(root, new Leftist_Node<T>(value, NULL, NULL));

};
template <typename T>
void Leftist_Heap<T>:: deletemin()
{
  if(root == NULL)
    return;
  Leftist_Node<T>* temp = root;
  root = merge(root->left_node, root->right_node);
  delete temp;
};

template <typename T>
void Leftist_Heap<T>::preorder()
{
  preorder(root);
}
template <typename T>
void Leftist_Heap<T>::inorder()
{
  inorder(root);
}
template <typename T>
void Leftist_Heap<T>::preorder(Leftist_Node<T>*  & tree)
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
void Leftist_Heap<T>::inorder(Leftist_Node<T>*  & tree)
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
void Leftist_Heap<T>::levelorder()
{
  //bool empty= false;
  linkedlist<Leftist_Node<T>*>* queue= new linkedlist<Leftist_Node<T>*>();
  queue->insert(root);
  queue->insert(NULL);// add root

  while(!(queue->isEmpty()))
  {
    Leftist_Node<T>* temp = queue->pop();
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
