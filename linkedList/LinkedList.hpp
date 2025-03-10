/**
*	@author Sam Jerguson
*	@date 9/5/2021
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/
template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const //FIXED
{
	/** TODO 
		Fix this method
	*/
	return m_size;
}

template <typename T>
bool LinkedList<T>::search(T value) const //FIXED
{
	Node<T>* temp = m_front;
	bool isFound = false;
	for(int i = 1; i <= m_size; i++)
	{
		if(temp->getValue() == value)
		{
			isFound = true;
			break;
		}
		else
		{
			temp = temp->getNext();
		}
	}
	/** TODO 
		Fix this method
	*/

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;
	
	if(!isEmpty())
	{
		lastNode = m_front;
		secondintoLast = m_front;
		for(int i = 1; i <= m_size; i++)
		{
			secondintoLast = lastNode;
			lastNode = lastNode->getNext();
			if(i == m_size-1)
			{
				secondintoLast->setNext(nullptr);
			}
		}
		delete lastNode;
		m_size--;
		isRemoved = true;
	}

	/** TODO 
		Fix this method
	*/

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
