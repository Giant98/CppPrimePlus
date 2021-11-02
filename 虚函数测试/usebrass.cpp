#include<iostream>
#include<string>
#include"brass.h"
const int CLIENTS = 5;

int main() {
	using std::cout;
	using std::endl;
	//��������ָ��
	std::auto_ptr<double>pd(new double);
	std::unique_ptr<double>pdu(new double);
	std::shared_ptr<std::string>pss(new std::string);
	Brass* p_clients[CLIENTS];//ָ��Brass��ָ�����飬����ָ��Brass����Ҳ����ָ��BrassPlus����
	//���޷�����BrassPlus�������������ݣ�����ͨ����Ա�������ʵ�
	p_clients[0] = new Brass{ "Harry",112233,1500 };
	p_clients[1] = new Brass{ "Harry2",112233,1500 };
	p_clients[2] = new Brass{ "Harry3",112233,1500 };
	p_clients[3] = new BrassPlus{ "Harry",112233,1500, 800,0.1 };
	p_clients[4] = new BrassPlus{ "Harry",112233,1500,350,0.12 };
	//cout << p_clients[4]->maxLoan;���ܷ���BrassPlus���������
	for (int i = 0; i < CLIENTS; i++) {
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++) {
		delete p_clients[i];
	}


	//������ģ��
	Stack<std::string>S;
	if (S.isEmpty())cout << "ģ�������ɳɹ�" << endl;

	//�����з����Ͳ�������ģ��
	ArrayTP<int, 5>A(5);
	if(A[4]==5)	cout << "�����зǲ�����ģ���������Գɹ�" << endl;
	ArrayTP<int, 4>A_4 = change<int,4>(A);
	if(A[3]==5) cout << "�зǲ�����ģ���ඨ����Գɹ�" << endl;
	return 0;
}