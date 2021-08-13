#include<iostream>
using namespace std;

template<class T = int, class U = char>
class A {
	T x;
	U y;
public:
	A() { cout << "Constructor Called" << endl; }
};

int main() {
	A<> a;
	A<int , int> c;

	A<char, char> f;

	A<int, double> b;

	return 0;
}
