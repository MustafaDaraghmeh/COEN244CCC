// Friend functions
#include <iostream>
using namespace std;

class Rectangle {
private:
	int width;
	int height;

public:
	Rectangle(int, int); 	  // Constructor        
	~Rectangle() {};	      // Destructor

	int computeArea();	      // Compute area

	// the function duplicate can access the non-public 	
	// members of Rectangle    		

	friend Rectangle duplicate(Rectangle);
};

Rectangle::Rectangle(int a, int b) {
	width = a;  height = b;
}

int Rectangle::computeArea() {
	return width * height;
}

// Note: this function is not a member function of Rectangle

Rectangle duplicate(Rectangle inputRec) {
	Rectangle recResult(inputRec.width, inputRec.height);
	return recResult;
}

int main() {
	Rectangle recta(2, 3);
	Rectangle rectb(0, 0);

	rectb = duplicate(recta);

	cout << rectb.computeArea() << '\n';

	return 0;
}

