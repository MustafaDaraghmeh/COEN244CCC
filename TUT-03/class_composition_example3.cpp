// Class composition. Class Rectangle uses two objects of the class Point. 
//The objects are declared dynamically.

#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;   // x coordinate
    double y;   // y coordinate

public:
    Point();                            // constructor
    Point(double,double);                            // 
    void setPoint(double, double);      // sets x, y
    double getX() const;                // returns x
    double getY() const;                // returns y
    void print() const;                 // prints information about point 
};

Point::Point() {
    x = 0.0;
    y = 0.0;
}
Point::Point(double a, double b) :x(a), y(b) {}

void Point::setPoint(double a, double b) {
    x = a;
    y = b;
}

double Point::getX()  const {
    return x;
}

double Point::getY()  const {
    return y;
}

void Point::print() const {
    cout << "Point: " << x << " " << y << endl;
}

class Rectangle
{
private: 	 // A rectangle has two points, i.e., two objects of class Point
    Point* p1;   // The first point
    Point* p2;   // The second point

public:
    Rectangle(); // constructor
    Rectangle(double, double, double, double);
    Rectangle(const Rectangle&); // copy constructor
    ~Rectangle();  // destructor to free memore pointed to by p1 and p2 

    void setRectangle(double, double, double, double); // sets x1, y1, x2, y2
    double getX1() const;       // returns x1 
    double getY1() const;       // returns y1
    double getX2() const;       // returns x2
    double getY2() const;       // returns y2
    double area() const;        // computes the area of the rectangle
    double perimeter() const;   // computes the perimeter of the rectangle
    void print() const;         // prints information about the rectangle
};

Rectangle::Rectangle() {
    cout << "Constrcutor Rectangle() is called." << endl;
    // You need to create objecs of Point 
    p1 = new Point();
    p2 = new Point();
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
{
    p1 = new Point(x1, y1);
    p2 = new Point(x2, y2);
}

Rectangle::Rectangle(const Rectangle& r) {
    cout << "Copy Constrcutor Rectangle(....) is called." << endl;
    p1 = new Point();
    p1->setPoint(r.getX1(), r.getY1());

    p2 = new Point();
    p2->setPoint(r.getX2(), r.getY2());
}

Rectangle::~Rectangle() {
    cout << "Destructor of Rectangle is called." << endl;
    delete p1;
    delete p2;
}

void Rectangle::setRectangle(double x1, double y1, double x2, double y2) {
    p1->setPoint(x1, y1);
    p2->setPoint(x2, y2);
}

double Rectangle::getX1()  const {
    return p1->getX();
}

double Rectangle::getY1()  const {
    return p1->getY();
}

double Rectangle::getX2()  const {
    return p2->getX();
}

double Rectangle::getY2()  const {
    return p2->getY();
}

double Rectangle::area() const {
    return fabs(p1->getX() - p2->getX()) * fabs(p1->getY() - p2->getY());
}

double Rectangle::perimeter() const {
    return 2 * fabs(p1->getX() - p2->getX()) + 2 * fabs(p1->getY() - p2->getY());
}

void Rectangle::print() const {
    cout << "Point 1: ";
    p1->print();
    cout << "Point 2: ";
    p2->print();
}

int main() {

    cout << "Test 1: Create object of Rectangle statically" << endl;
    Rectangle r1;
    r1.setRectangle(10.5, 30.4, 23, 10.0);
    cout << "The area is: " << r1.area() << endl;
    cout << "The perimeter is: " << r1.perimeter() << endl;
    cout << "Information about the rectangle: " << endl;
    r1.print();
    cout << endl;

    cout << "Test 2: Create object of Rectangle dynamically" << endl;
    Rectangle* r2;
    r2 = new Rectangle();
    r2->setRectangle(5.8, 36.2, 22.5, 15.0);
    r2 = new Rectangle();
    r2->setRectangle(5.5, 36.2, 22.5, 15.0);
    cout << "The area is: " << r2->area() << endl;
    cout << "The perimeter is: " << r2->perimeter() << endl;
    cout << "Information about the rectangle: " << endl;
    r2->print();
    delete r2;

    cout << "Test 3: Create object of Rectangle by calling copy constructor" << endl;
    Rectangle r3 = r1;
    r3.print();
    Rectangle* r4= new Rectangle(5.5, 36.2, 22.5, 15.0);
    r4->print();

    return 0;
}