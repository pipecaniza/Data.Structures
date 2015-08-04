#pragma once

template<typename T>
struct Node
{
	T Value;
	Node<T>* Next;

	Node(const T& value)
	{
		Value = value;
		Next = nullptr;
	}
	
	~Node(){}
};


template<typename T>
class LinkedList
{
private:
	Node<T>* First;
	Node<T>* Last;
	int size;

public:
	LinkedList()
	{
		this->First = nullptr;
		this->Last = nullptr;
		this->size = 0;
	}
	
	~LinkedList()
	{
		Node<T>* current = this->First;
		while (current != nullptr)
		{
			Node<T>* next = current->Next;
			delete current;
			current = next;
		}
	}
	
	void push_back(const T& elem)
	{
		if (this->First == nullptr)
		{
			this->First = new Node<T>(elem);
			this->Last = this->First;
			this->size++;
		}
		else{
			this->Last->Next = new Node<T>(elem);
			this->Last = Last->Next;
			this->size++;
		}
	}	
	
	void remove(const int& at)
	{
		if (at == 0){
			Node<T>* ptr_aux = this->First->Next;
			delete this->First;
			this->First = ptr_aux;
			this->size--;
			return;
		}
		Node<T>* previous = nullptr;
		Node<T>* current = this->First;
		// size_t -> unsigned int
		for (size_t i = 0; i < at && i < this->size; i++)
		{
			previous = current;
			current = current->Next;
		}
		delete previous->Next;
		previous->Next = current;
		this->size--;
	}
	
	int find(const T& obj)
	{
		Node<T>* current = this->First;
		// size_t -> unsigned int
		for (size_t i = 0; i < this->size; i++)
		{
			if (current->Value == obj)
				return i;
			current = current->Next;
		}
		return -1;
	}

	// O(n)
	Node<T>& operator [](const int& target)
	{
		if (target > this->size)
			return *(this->Last);

		Node<T>* current = this->First;
		for (size_t i = 0; i < target; i++)
		{
			current = current->Next;
		}
		return *current;
	}
};