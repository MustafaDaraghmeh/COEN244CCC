#include <iostream>
#include <fstream>

#include<string>
using namespace std;

template <typename T>
class Array {
private:
    T* ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
    std::string getString();
};

template <typename T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

template <typename T>
std::string Array<T>::getString() {
    std::string temp = "";
    for (int i = 0; i < size; i++)
         temp += std::to_string(*(ptr + i)) + ",";
    return temp;
}

void fun(std::string _s){
std::string s = _s;
std::string delimiter = ",";
//std::string token = s.substr(0, s.find(delimiter));

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);

    double v = std::stod(token);
    int c = std::stoi(token);

    std::cout << token << std::endl;
    //s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    std::string s1 = a.getString();

    double arr2[5] = { 1.1, 2.8, 0.3, 7.4, 0.5 };
    Array<double> b(arr2, 5);
    b.print();
    std::string s2 = b.getString();

    //fun(s2);

    // Create and open a text file
    ofstream MyFile("filename.txt");

    // Write to the file
    MyFile << s1 <<endl;
    MyFile << s2 <<endl;
    // Close the file
    MyFile.close();

    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        cout << myText;
    }

    // Close the file
    MyReadFile.close();

    return 0;
}