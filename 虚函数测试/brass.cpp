#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);
Brass::Brass(const string& s, long an, double bal) {
	fullName = s;
	acctNum = an;
	balance = bal;
}
void Brass::ViewAcct()const {
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client:" << fullName << endl;
	cout << "Account Number:" << acctNum << endl;
	cout << "Balance:" << balance << endl;
	restore(initialState, prec);//还原初始格式
}
//派生类构造函数用初始化列表方式初始化基类私有数据
BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r) :Brass(s, an, bal) {
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : Brass(ba) {
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct()const {
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct();
	cout << "Maximum loan:" << maxLoan << endl;
	cout << "Owed to bank:" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate:" << 100 * rate << "%\n";
	restore(initialState, prec);//还原初始格式
}

format setFormat() {
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}
void restore(format f, precis p) {
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}