// Friend classes

#include <iostream>
using namespace std;

class A {
	friend class B;  // All B’s functions are A’s friends

private:
	int i;     // private member of A

public:
	A(int x) {
		i = x;
	}
};

class B {
public:
	B() { }
	void print(A& a) {
		// B can access A’s private members
		cout << "B can access the private member i: " << a.i;
	}
};

int main() {

	A a(10);
	B b;

	//Note that B can access A’s private member

	b.print(a);

	return 0;
}