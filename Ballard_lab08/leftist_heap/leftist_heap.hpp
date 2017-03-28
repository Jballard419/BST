template <typename T>
Leftist_Node<T>* Leftist_Heap<T>:: merge(Leftist_Node *t1,Leftist_Node *t2 )
{
  if(t1==NULL)
    return t2;
  if(t2==NULL)
    return t1;
  if(t1->value<t2->value)
    swap(t1, t2);

    // now
  if(t1->left_node==NULL) // maybe his shou be a second funiction
  {
    t1->left_node =t2; // no need to change the rank
  }else
  {
    h1->right_node = merge(h1->right_node, h2);

    if(h1->left_node->rank < h1->right_node->rank)
      swap(h1->left_node,h1->right_node);
    h1->rank = h1->right_node->rank +1;
  }
}

template <typename T>
void Leftist_Heap<T>:: insert(T value)
(
  root= merge(root, new Leftist_Node<T>(value, NULL, NULL));

);
template <typename T>
void Leftist_Heap<T>:: deletemin()
{
  if(root == NULL)
    return;
  Leftist_Node<T>* temp = root;
  root = merge(root->left_node, root->right_node);
  delete temp;
}

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
  linkedlist<Leftist_Node<T>*>* queue= new linkedlist<Leftist_Node<T>*>();
  queue->insert(root);// add root

  while(!(queue->isEmpty()))
  {
    Leftist_Node<T>* temp = queue->pop();
    if(temp != NULL)
    {
      queue->insert(temp->left_node);
      queue->insert(temp->right_node);
      std::cout << temp-> value << " ";

    }


  }

}
