#ifndef EXCEPTION_H
#define EXCEPTION_H

class MyException :public exception
{
	string msg;
public:
	MyException();
	MyException(string s);

	virtual void operator+=(string s);
	const char* what() const override;
};


#endif // !EXCEPTION_H
