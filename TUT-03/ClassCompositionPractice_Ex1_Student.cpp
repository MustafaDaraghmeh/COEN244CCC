// Class Composition Practice Student. Class Course contains array of objects of class Student, created statically.
#include "Course.h"

int main() {

    // Sample students    
    Student s1(1, "Ric");
    Student s2(2, "Karen");
    Student s3(3, "Lee");

    // A course object	 
    Course c("COEN244", "Programming in C++");

    // Register students in the course c
    c.addStudent(s1);
    c.addStudent(s2);
    c.addStudent(s3);

    // List students
    c.listAllStudents();

    if (c.searchStudent(1))
        cout << "Student with id = 1 " << " is registered in " << c.getCode() << " " << c.getName() << endl;
    else
        cout << "Student with id = 1 " << " is not registered in " << c.getCode() << " " << c.getName() << endl;

    cout << endl;

    // Student 1 drops the course
    c.removeStudent(1);
    cout << endl;

    // List students
    c.listAllStudents();

    return 0;
}