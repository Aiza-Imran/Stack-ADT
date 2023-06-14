#include<iostream>
using namespace std;

#include"Stack.h"
#include"EmptyStack.h"

//resizes stack to a new capacity
template<typename T>
void Stack<T>::reSize(int newCapacity)
{

	T * temp = new T[newCapacity];
	for (int i = 0; i < top; i++)
		temp[i] = data[i];

	int noe = top;
	this->~Stack();

	data = temp;
	capacity = newCapacity;
	top = noe;
}

//default constructor
template<typename T>
Stack<T>::Stack()
{
	capacity = 0;
	top = 0;
	data = nullptr;
}

//copy constructor
template<typename T>
Stack<T>::Stack(const Stack<T>& ref):Stack()
{
	*this = ref;
}

//copy assigment
template<typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& ref)
{
	if (this == &ref)
		return *this;
	this->~Stack();
	if (!ref.data)
		return *this;
	capacity = ref.capacity;
	top = ref.top;
	data = new T[capacity];
	for (int i = 0; i < top; i++)
		data[i] = ref.data[i];

	return *this;
}


//destructor
template<typename T>
Stack<T>::~Stack()
{
	if (data)
		delete[] data;
	data = nullptr;
	capacity = 0;
	top = 0;
}

//inserts element into stack
template<typename T>
void Stack<T>::push(T element)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	data[top] = element;
	top++;
}

//removes element from top of stack
template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		throw EmptyStack("Stack is Empty.\n");
	}
	T val = data[top - 1];
	top--;

	if (top > 0 && top == capacity / 4)    //shrinks stack if available space in stack is more than one-fourth of total capacity
		reSize(capacity / 2);

	return val;
}


//returns the top most element in stack
template<typename T>
T Stack<T>::stackTop() const
{
	return data[top - 1];
}


//returns true if stack is empty
template<typename T>
bool Stack<T>::isEmpty()
{
	return top == 0 ? true : false;
}

//return true if stack is full
template<typename T>
bool Stack<T>::isFull()
{
	return top == capacity ? true : false;
}

//return total capacity of the stack
template<typename T>
int Stack<T>::getCapacity() const
{
	return capacity;
}

//returns total number of elements in stack
template<typename T>
int Stack<T>::getNoOfElements() const
{
	return top;
}