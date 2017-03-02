
template <typename T>

template <typename T>

BGT<T>::BST(): root(NULL){};
template <typename T>
void BGT<T>::insert( T value){

  insert(value, root);
}

template <typename T>
void BGT<T>::remove(T value)
{
  remove( value, root);

}

template <typename T>
Binary_Node<T>* BGT<T>::search (T value)
{
    search ( value, root);
}

template <typename T>
T BGT<T>::deletemin()
{

return  deletemin(root);
}

template <typename T>
T BGT<T>::deletemax()
{

return  deletemax(root);
}
template <typename T>
void BGT<T>::preorder()
{
  preorder(root);
}
template <typename T>
void BGT<T>::inorder()
{
  inorder(root);
}

template <typename T>
void BGT<T>::levelorder();
{
  // make queue of Binary Nodes
  // add root

  // while not empty
  // pop front
  // if not null add left node
  // if not null add right node
  // print value




}



template <typename T>
void BGT<T>::insert( T value, Binary_Node<T>*  & tree)
{
  if(tree == NULL)
  {
    tree = new Binary_Node<T>(value, NULL, NULL );
    // will make NULL pointer in to a new node
  } else if(value < tree->value){
    insert(value , tree-> left_node);
  } else if (value => tree->value)
    {
      insert(x, tree->right_node );
    }
  return;
}

template <typename T>
void BGT<T>::remove(T value, Binary_Node<T>*  & tree)
{
  if(tree == NULL)
  { return;}
  else if( value < tree->value)
  {
    remove(value, tree->left_node );
  }else if( value > tree->value)
  {
    remove(value, tree->right_node );
  }else if (tree->left_node != NULL && (tree->right_node != NULL)
  {
    tree->value = deletemin(tree-> right_node); //patch the hole
  }else // one child
  {
    Binary_Node *temp = tree;
    t= (t->right_node != NULL) ? T->right_node, T->left_node // firgures out which child
    delete temp; // destory the node

  }
return;

}

template <typename T>
Binary_Node<T>* BGT<T>::search (T value, Binary_Node<T>*  & tree)
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
T BGT<T>::deletemin(Binary_Node<T>*  & tree)
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
T BGT<T>::deletemax(Binary_Node<T>*  & tree)
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
void BGT<T>::preorder(Binary_Node<T>*  & tree)
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
void BGT<T>::inorder(Binary_Node<T>*  & tree)
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
