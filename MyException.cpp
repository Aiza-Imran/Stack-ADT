#include <iostream>
using namespace std;

#include "MyException.h"


MyException::MyException()
{ }
MyException::MyException(string s) :msg(s)
{
	//msg = s;
}
void MyException::operator+=(string s)
{
	msg += s;
}
const char* MyException::what() const
{
	return msg.c_str();
}
