// Class composition. Class Rectangle uses two objects of the class Point. 
//The objects are declared statically.
#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;   // x coordinate
    double y;   // y coordinate

public:
    Point();                            // constructor
    void setPoint(double, double);      // sets x, y
    double getX() const;                // returns x
    double getY() const;                // returns y
    void print() const;                 // prints information about point 
};

Point::Point() {
    x = 0.0;
    y = 0.0;
}

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
private: 	    // A rectangle has two points, i.e., two objects of class Point
    Point p1;   // The first point
    Point p2;   // The second point

public:
    Rectangle(); // constructor
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
    // Nothing to do because Point contructor will be called
}

void Rectangle::setRectangle(double x1, double y1, double x2, double y2) {
    p1.setPoint(x1, y1);
    p2.setPoint(x2, y2);
}

double Rectangle::getX1()  const {
    return p1.getX();
}

double Rectangle::getY1()  const {
    return p1.getY();
}

double Rectangle::getX2()  const {
    return p2.getX();
}

double Rectangle::getY2()  const {
    return p2.getY();
}

double Rectangle::area() const {
    return fabs(p1.getX() - p2.getX()) * fabs(p1.getY() - p2.getY());
}

double Rectangle::perimeter() const {
    return 2 * fabs(p1.getX() - p2.getX()) + 2 * fabs(p1.getY() - p2.getY());
}

void Rectangle::print() const {
    cout << "Point 1: ";
    p1.print();
    cout << "Point 2: ";
    p2.print();
}

int main() {
    Rectangle r; // This will create an object of class Rectangle and

    r.setRectangle(10.5, 30.4, 23, 10.0);

    // Test the other functions
    cout << "The area is: " << r.area() << endl;
    cout << "The perimeter is: " << r.perimeter() << endl;
    cout << "Information about the rectangle: " << endl;
    r.print();

    return 0;
}