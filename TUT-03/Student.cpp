#include "Student.h"

// Default constructor
Student::Student() {
    id = 0;
    name = "";
}

// Regular constructor
Student::Student(int id1, string name1) {
    id = id1;
    name = name1;
}

// Returns student id
int Student::getID() const {
    return id;
}

// Returns student name
string Student::getName() const {
    return name;
}

// Changes student name
void Student::setName(string name1) {
    name = name1;
}

// Prints student info
void Student::print() const {
    cout << "Student: " << name << " " << id << endl;
}
