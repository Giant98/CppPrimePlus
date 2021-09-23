#include <iostream>
using namespace std;

template <typename T>
void Swap(T& a, T& b);

template <typename T>
void Swap(T* a, T* b, int n);//实现Swap重载

template <typename T1,typename T2>
auto gt(T1 x, T2 y)-> decltype(x + y);//后置返回类型，用于不知道返回值类型的时候
/*
int main() {
	cout << int(001);
	return 0;
}
*/
template <typename T>
void Swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n) {
	T temp;
	for (int i = 0; i < n; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

template <typename T1, typename T2>
auto gt(T1 x, T2 y)-> decltype(x + y)
{
	return x + y;
}