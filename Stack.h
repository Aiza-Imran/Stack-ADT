#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
	T* data;
	int capacity;
	int top;
	void reSize(int);
public:
	Stack();
	Stack(const Stack<T>&);
	Stack<T>& operator = (const Stack<T>&);
	~Stack();
	void push(T);
	T pop();
	T stackTop() const;
	bool isEmpty();
	bool isFull();
	int getCapacity() const;
	int getNoOfElements() const;
};


#endif // !STACK_H