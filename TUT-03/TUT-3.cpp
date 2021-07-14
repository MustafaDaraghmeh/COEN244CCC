// TUT-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Example program
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    Employee(){
        std::cout << "default Employee constructor is called\n";
        name = "";
        address = "";
        salary = 0.0f;
    }

    Employee(std::string nm, std::string add, float sal){
        std::cout << "regualr Employee constructor is called\n";
        name = nm;
        address = add;
        salary = sal;
    }
    
    Employee(const Employee & emp) {
        this->name = emp.name;
        this->address = emp.address;
        this->salary = emp.salary;
    }

    ~Employee(){
        std::cout << "destructor Employee is called\n";
    }

    void print(){
        std::cout << name << "\n" << address << "\n" << salary << "\n";

    }

//TODO: add getters and setters to the private memebers 
private:
    std::string name;
    std::string address;
    float salary;
};
class CompanyModel {
public:
    CompanyModel() : cname(""), age(0){}
    CompanyModel(string _name,int _age) {
        cname = _name;
        age = _age;
    }
    CompanyModel(const CompanyModel& cm) {
        this->cname = cm.cname;
        this->age = cm.age;
    }
    void print() {
        cout <<"************ " <<cname << " ************" << endl;
    }
private:
    string cname;
    int age;
};

class Company {
public:
    Company() :max_emp(10), utilizedLocation(0),data(){
        tbl_emp = new Employee[max_emp];
    }
    Company(string _name, int _age, int containerSize) : data(_name,_age),max_emp(containerSize), utilizedLocation(0) {
        tbl_emp = new Employee[max_emp];
    }
    Company(const Company& anotherContainer) 
        :data(anotherContainer.data),max_emp(anotherContainer.max_emp),
        utilizedLocation(anotherContainer.utilizedLocation){
        tbl_emp = new Employee[max_emp];
        for (int i = 0; i < utilizedLocation; i++)
            tbl_emp[i] = anotherContainer.tbl_emp[i];
    }
    ~Company() {
        delete[] tbl_emp;
    }
    // Adds 
    void addEmployee(const Employee& e) {
        if (utilizedLocation < max_emp) {
            tbl_emp[utilizedLocation] = e;
            utilizedLocation++;
        }
        else {
            std::cout << "Out of memory,  locations are exceeded " << std::endl;
        }
        return;
    }
    // Adds 
    void addEmployee(const Employee* e) {
        if (utilizedLocation < max_emp) {
            tbl_emp[utilizedLocation] = *e;
            utilizedLocation++;
        }
        else {
            std::cout << "Out of memory,  locations are exceeded " << std::endl;
        }
        return;
    }
    void print() {
        data.print();
        for (int i = 0; i < utilizedLocation; i++) {
            tbl_emp[i].print();
        }
    }
private:
    Employee* tbl_emp;
    const size_t max_emp;
    int utilizedLocation;
    CompanyModel data;
};

int main() {
    Company c1("FB",15,10);
    c1.addEmployee(new Employee("00000", "332 rue Dezery", 9000));
    Employee *emp0=new Employee("ali1", "332 rue Dezery", 9000);
    c1.addEmployee(*emp0);
    emp0 = nullptr;
    emp0 = new Employee("ali2", "333 rue Dezery", 3333);
    c1.addEmployee(*emp0);
    emp0 = nullptr;
    c1.addEmployee(Employee("al3", "332 rue Dezery", 9000));
    c1.addEmployee(Employee("ali4", "332 rue Dezery", 9000));
    c1.addEmployee(Employee("ali5", "332 rue Dezery", 9000));
    c1.addEmployee(Employee("ali6", "332 rue Dezery", 9000));
    c1.addEmployee(Employee("ali7", "332 rue Dezery", 9000));
    c1.print();
    Company c2=c1;
    c2.print();
    Employee emp;
    emp.print();
    Employee emp2("Sarah", "111 Sainte Catherine", 2000);
    emp2.print();
    
    size_t max{ 10 };
    int utilizedLocation = 0;
    
    Employee* tbl_emp=new Employee[max];
    
    if (utilizedLocation < max) {
        tbl_emp[utilizedLocation]= Employee("Ahmad", "443 rue Dezery", 5000);
        utilizedLocation++;
    }
    if (utilizedLocation < max) {
        tbl_emp[utilizedLocation] = Employee("mustafa", "312 rue Dezery", 7000);
        utilizedLocation++;
    }
    if (utilizedLocation < max) {
        tbl_emp[utilizedLocation] = Employee("ali", "444 rue Dezery", 4000);
        utilizedLocation++;
    }
    for (int i = 0; i < utilizedLocation; i++) {
        tbl_emp[i].print();
    }

    size_t max2{ 10 };
    int utilizedLocation2 = 0;
    Employee** tbl_emp2 = new Employee*[max2];

    if (utilizedLocation2 < max2) {
        tbl_emp2[utilizedLocation2] = new Employee("Ahmad", "111 rue Dezery", 8000);
        utilizedLocation2++;
    }
    if (utilizedLocation2 < max2) {
        tbl_emp2[utilizedLocation2] = new Employee("mustafa", "222 rue Dezery", 7000);
        utilizedLocation2++;
    }
    if (utilizedLocation2 < max2) {
        tbl_emp2[utilizedLocation2] = new Employee("ali", "333 rue Dezery", 9000);
        utilizedLocation2++;
    }
    for (int i = 0; i < utilizedLocation2; i++) {
        tbl_emp2[i]->print();
    }
}
