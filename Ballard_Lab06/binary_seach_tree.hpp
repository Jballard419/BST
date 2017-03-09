


\
template <typename T>
void BST<T>::insert( T value){

  insert(value, root);
  return;
}

template <typename T>
void BST<T>::remove(T value)
{
  remove( value, root);

}
template <typename T>
BST<T>::~BST()
{
  int j;
  while(root != NULL)
  {
    j= deletemin();
  }
  return;
}

template <typename T>
Binary_Node<T>* BST<T>::search (T value)
{
    search ( value, root);
}

template <typename T>
T BST<T>::deletemin()
{

return  deletemin(root);
}

template <typename T>
T BST<T>::deletemax()
{

return  deletemax(root);
}
template <typename T>
void BST<T>::preorder()
{
  preorder(root);
}
template <typename T>
void BST<T>::inorder()
{
  inorder(root);
}

template <typename T>
void BST<T>::levelorder()
{
  linkedlist<Binary_Node<T>*>* queue= new linkedlist<Binary_Node<T>*>();
  queue->insert(root);// add root

  while(!(queue->isEmpty()))
  {
    Binary_Node<T>* temp = queue->pop();
    if(temp != NULL)
    {
      queue->insert(temp->left_node);
      queue->insert(temp->right_node);
      std::cout << temp-> value << " ";

    }


  }

}



template <typename T>
void BST<T>::insert( T value, Binary_Node<T>*  & tree)
{
  if(tree == NULL)
  {
    tree = new Binary_Node<T>(value, NULL, NULL );
    // will make NULL pointer in to a new node
  } else if(value < tree->value){
    insert(value , tree-> left_node);
  } else
    {
      insert(value, tree->right_node );
    }
  return;
}

template <typename T>
void BST<T>::remove(T value, Binary_Node<T>*  & tree)
{
  if(tree == NULL)
  {
  //  std::cout<< value <<" was not in the tree" << std::endl;

  }
  else if( value < tree->value)
  {
    remove(value, tree->left_node );
  }else if( value > tree->value)
  {
    remove(value, tree->right_node );
  }else if (tree->left_node != NULL && (tree->right_node != NULL))
  {
    tree->value = deletemin(tree-> right_node); //patch the hole
    remove(value,tree);// checks for
  }else // one child
  {
    Binary_Node<T>* temp = tree;
    if(tree->right_node != NULL)
    {
      tree= temp->right_node;
    } else { tree=temp->left_node ; }// firgures out which child
    delete temp;
    remove(value,tree); // destory the node

  }
return;

}

template <typename T>
Binary_Node<T>* BST<T>::search (T value, Binary_Node<T>*  & tree)
{
  if (tree == NULL)
  {
    return NULL;
  }else if (value == tree->value)
  {
    return tree;
  } else if ( value <tree->value)
  {
    return search(value, tree -> left_node);
  }
  return search(value, tree -> right_node);



}

template <typename T>
T BST<T>::deletemin(Binary_Node<T>*  & tree)
{
  T value;
  if(tree-> left_node != NULL)
  {
    value = deletemin(tree -> left_node);
  }else
  {
    value = tree -> value;

    Binary_Node<T>* temp = tree;

    tree = tree-> right_node; // saves the struct of tree
    delete temp;
  }
return value;


}
template <typename T>
T BST<T>::deletemax(Binary_Node<T>*  & tree)
{
  T value;
  if(tree-> right_node != NULL)
  {
    value = deletemax(tree -> right_node);
  }else
  {
    value = tree -> value;

    Binary_Node<T>* temp = tree;

    tree = tree-> left_node; // saves the struct of tree
    delete temp;
  }
return value;


}

template <typename T>
void BST<T>::preorder(Binary_Node<T>*  & tree)
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
void BST<T>::inorder(Binary_Node<T>*  & tree)
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
//will pass a queue in a bit
