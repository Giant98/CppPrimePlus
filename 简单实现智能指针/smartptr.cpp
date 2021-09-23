#include <iostream>
#include "smartptr.h"
using namespace std;

int main()
{
	//测试构造函数和赋值运算符重载函数
	SmartPtr<int>p1(new int(0));
	p1 = p1;
	//测试拷贝函数
	SmartPtr<int>p2(p1);
	//测试赋值运算符重载
	SmartPtr<int>p3(new int(1));
	p3 = p1;

	return 0;
}