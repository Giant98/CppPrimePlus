#include <iostream>
#include <vector>
using namespace std;
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
}