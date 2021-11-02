#include<iostream>
#include<string>
#include"brass.h"
const int CLIENTS = 5;

int main() {
	using std::cout;
	using std::endl;
	//三种智能指针
	std::auto_ptr<double>pd(new double);
	std::unique_ptr<double>pdu(new double);
	std::shared_ptr<std::string>pss(new std::string);
	Brass* p_clients[CLIENTS];//指向Brass的指针数组，可以指向Brass对象，也可以指向BrassPlus对象
	//但无法访问BrassPlus对象多出来的数据，但能通过成员函数访问到
	p_clients[0] = new Brass{ "Harry",112233,1500 };
	p_clients[1] = new Brass{ "Harry2",112233,1500 };
	p_clients[2] = new Brass{ "Harry3",112233,1500 };
	p_clients[3] = new BrassPlus{ "Harry",112233,1500, 800,0.1 };
	p_clients[4] = new BrassPlus{ "Harry",112233,1500,350,0.12 };
	//cout << p_clients[4]->maxLoan;不能访问BrassPlus额外的数据
	for (int i = 0; i < CLIENTS; i++) {
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++) {
		delete p_clients[i];
	}


	//测试类模板
	Stack<std::string>S;
	if (S.isEmpty())cout << "模板类生成成功" << endl;

	//测试有非类型参数的类模板
	ArrayTP<int, 5>A(5);
	if(A[4]==5)	cout << "生成有非参数的模板类对象测试成功" << endl;
	ArrayTP<int, 4>A_4 = change<int,4>(A);
	if(A[3]==5) cout << "有非参数的模板类定义测试成功" << endl;
	return 0;
}