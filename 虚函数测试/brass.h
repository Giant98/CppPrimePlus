#pragma once
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
class Brass {
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	virtual void ViewAcct() const;//若不被声明为虚函数，则无论何时都调用Brass::ViewAcct()
	virtual ~Brass() {}
};

class BrassPlus :public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string& s = "NullBody", long an = -1, double dal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct()const;
};


/*##########Stack 类模板#############*/
template <typename T>
class Stack//类模板
{
private:
	enum { MAX = 10 };
	T items[MAX];
	int top;
public:
	Stack();
	bool isEmpty();
};

template <typename T>
Stack<T>::Stack()
{
	top = 0;
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return top == 0;
}


/*##########ArrayTP 包含非类型（表达式）参数的类模板#############*/
template<typename T, int n>
class ArrayTP
{
private:
	T arr[n];
public:
	ArrayTP() {};
	explicit ArrayTP(const T& v);
	virtual T& operator[](int i);
};

template<typename T, int n>
ArrayTP<T, n>::ArrayTP(const T& v) {
	for (int i = 0; i < n; i++)arr[i] = v;
}
template<typename T, int n>
T& ArrayTP<T, n>::operator[](int i)
{
	return arr[i];
}
template<typename T, int n, int m>//默认n<m
ArrayTP<T, n>change(const ArrayTP<T, m>& B){
	ArrayTP<T, n>A(1);
	for (int i = 0; i < n; i++)A[i] = 5;
	return A;
}
#endif