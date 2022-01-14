#include <iostream>
#include <vector>
using namespace std;

//√∞≈›≈≈–Ú
template<typename T>
void bubble_sort(vector<T> &v) {
	for (int i = 0; i < v.size()-1; i++) {
		for (int j = 0; j < v.size()-1-i; j++) {
			if (v[j] > v[j+1]) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}


//øÏÀŸ≈≈–Ú
template<typename T>
T Partition(vector<T>& v, T low, T high) {
	T temp = v[low];
	while (low < high) {
		while (low < high && v[high] >= temp)high--;
		v[low] = v[high];
		while (low < high && v[low] <= temp)low++;
		v[high] = v[low];
	}
	v[low] = temp;
	return low;
}
template<typename T>
void quick_sort(vector<T>& v,T low,T high) {
	if (low < high) {
		T p = Partition(v, low, high);
		quick_sort(v, low, p - 1);
		quick_sort(v, p + 1, high);
	}
}

//÷ÿ‘ÿ<<
template<typename T>
ostream& operator<<(ostream& out, const vector<T>&v) {
	out << "{";
	if (v.size() == 0) {
		out << "}";
		return out;
	}
	out << v[0];
	for (int i = 1; i < v.size(); i++) {
		out << ","<< v[i] ;
	}
	out << "}";
	return out;
}
int main()
{
	cout << "base:"<< endl;
	vector<int>A = { 3,1,4,2,5 };
	cout << A << endl;

	cout << "bubble_sort:" << endl;
	bubble_sort(A);
	cout << A << endl;

	A = { 3,1,4,2,5 };
	cout << "quick_sort:" << endl;
	quick_sort(A,0,int(A.size()-1));
	cout << A << endl;
}