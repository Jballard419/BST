template<typename T>
node<T>::node(T value)
{
	this->m_value=value;
	m_previous=nullptr;
  m_next=nullptr;
}
template<typename T>
void node<T>::setvalue(T val)
 {
	m_value=val;
	return;
}
template<typename T>
void node<T>::setprevious(node<T>* prev)
{
	m_previous=prev;
	return;
}
template<typename T>
node<T>* node<T>::getprevious()
{
	return m_previous;
}
template<typename T>
void node<T>::setnext(node<T>* prev)
{
	m_next=prev;
	return;
}
template<typename T>
node<T>* node<T>::getnext()
{
	return m_next;
}
template<typename T>
T node<T>::getvalue()
{
  return m_value;
}
