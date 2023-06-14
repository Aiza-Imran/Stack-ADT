#ifndef EMPTY_STACK_H
#define EMPTY_STACK_H

#include"MyException.h"

class EmptyStack :public MyException
{
public:
	//using MyException::MyException;
	EmptyStack();
	EmptyStack(string);

};
#endif // !EMPTY_STACK_H