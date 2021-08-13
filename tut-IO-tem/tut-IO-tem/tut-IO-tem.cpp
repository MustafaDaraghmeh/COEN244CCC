// Example 1: Saving students' grades in a file

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Data {
public:
    int id;
    string name;
    float grade;
};

void read2() {
    int id;
    string name;
    float grade;

    ifstream inFile;
    inFile.open("grades.txt", ios::in); // opens file grades.txt

    // checks if file is opened properly
    if (!inFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    // Go through file 
    cout << "Print file info:" << endl;
    inFile >> id >> name >> grade;  // reads information from a file
    while (!inFile.eof()) {
        cout << id << " " << name << " " << grade << endl;
        inFile >> id >> name >> grade;  // reads information from a file
    }

    inFile.clear();    // clears eof bit
    inFile.seekg(0, ios::beg); // moves pointer to beginning of file

    cout << "\nGo through the file another time:" << endl;
    // Go through the file again.
    inFile >> id >> name >> grade;  // reads information from a file

    while (!inFile.eof()) {
        cout << id << " " << name << " " << grade << endl;
        inFile >> id >> name >> grade;  // reads information from a file
    }

    inFile.close();
}
void read() {

    Data _data;
        ifstream inFile;
        inFile.open("grades.txt", ios::in); // opens file grades.txt

        // checks if file is opened properly
        if (!inFile) {
            cerr << "File could not be opened" << endl;
            exit(EXIT_FAILURE);
        }

        inFile >> _data.id >> _data.name >> _data.grade;  // reads information from a file

        while (!inFile.eof()) {

            cout << _data.id << " " << _data.name << " " << _data.grade << endl; ///cout << _data <<endl;

            inFile >> _data.id >> _data.name >> _data.grade;  // reads information from a file

        }

        inFile.close();

}
int main() {
    int id;
    string name;
    float grade;

    ofstream outFile("grades.txt", ios::out); // opens file grades.txt 

    // checks if file is opened properly
    if (!outFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter student information:" << endl;

    cout << "Student id (-1 to exit): ";
    cin >> id;

    while (id != -1) {
        cout << "Student name: ";
        cin >> name;
        cout << "Student grade: ";
        cin >> grade;

        outFile << id << " " << name << " " << grade << endl;  // Writes information to a file

        cout << "Student id (-1 to exit): ";
        cin >> id;
    }

    outFile.close();

    return 0;
}