#include <iostream>
#include "smartptr.h"
using namespace std;

int main()
{
	//���Թ��캯���͸�ֵ��������غ���
	SmartPtr<int>p1(new int(0));
	p1 = p1;
	//���Կ�������
	SmartPtr<int>p2(p1);
	//���Ը�ֵ���������
	SmartPtr<int>p3(new int(1));
	p3 = p1;

	return 0;
}