template <typename T>
Skew_Node<T>* Skew_Heap<T>:: merge(Skew_Node *t1,Skew_Node *t2 )
{
  if(t1==NULL)
    return t2;
  if(t2==NULL)
    return t1;
  if(t1->value<t2->value)
    swap(t1, t2);

    // now
    Skew_Node<T>* temp = t1->right_node;
    t1->right_node = t1->left_node;
    t1->left_node = merge(temp, H2);
    return t1;

}

template <typename T>
void Skew_Heap<T>:: insert(T value)
(
  root= merge(root, new Skew_Node<T>(value, NULL, NULL));

);
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
  queue->insert(root);// add root

  while(!(queue->isEmpty()))
  {
    Skew_Node<T>* temp = queue->pop();
    if(temp != NULL)
    {
      queue->insert(temp->left_node);
      queue->insert(temp->right_node);
      std::cout << temp-> value << " ";

    }


  }

}
