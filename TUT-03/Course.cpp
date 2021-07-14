#include "Course.h"

// Default constructor    
Course::Course() {
    code = "";
    name = "";
    students = new Student[20];  // We assume a maximum of 20 students; This value could be declared as a constant
    numStudents = 0;
}

// Regular constructor
Course::Course(string code1, string name1) {
    code = code1;
    name = name1;
    students = new Student[20];
    numStudents = 0;
}

// Copy constructor
Course::Course(const Course& c) {
    code = c.code;
    name = c.name;
    students = new Student[20];
    numStudents = c.numStudents;
    for (int i = 0; i < numStudents; i++)
        students[i] = c.students[i];
}

// Destructor 
Course::~Course() {
    delete[] students;
}

string Course::getCode() const {
    return code;
}

string Course::getName() const {
    return name;
}

// Register a student in a course
void Course::addStudent(const Student& s) {
    if (numStudents < 20) {
        students[numStudents] = s;
        numStudents++;
    }
    else {
        cout << "Student: " << s.getID() << " cannot be added – number of students exceeded " << endl;
    }
    return;
}

// Removes a student from a course
void Course::removeStudent(int studID) {
    // We need to search for studID first
    for (int i = 0; i < numStudents; i++) {
        if (students[i].getID() == studID) {
            // We need to shift the  elements of the array
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1]; //shifts the elements of the array
            }
            numStudents--;
            return;
        }
    }
    cout << "Student " << studID << " cannot be found!" << endl;
}

// Displays all students of a course
void Course::listAllStudents()  const {
    for (int i = 0; i < numStudents; i++)
        students[i].print();
}

// Searches if a student is registered
bool Course::searchStudent(int studID) const {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].getID() == studID)
            return true;
    }
    return false;
}

