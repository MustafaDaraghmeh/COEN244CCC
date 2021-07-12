#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Account {
public:
    Account();
    Account(double, const char*);
    Account(const Account&);
    ~Account();

    int getBalance() const;
    void setBalance(double b);

    char* getOwner() const;
    void setOwner(const char* ow);
    void print() const;
private:
    double balance;
    char* owner;
};

Account::Account(const Account& a) {
    cout << "Copy Constructor Account(const Account&) is called" << endl;
    balance = a.getBalance();
    owner = new char[strlen(a.getOwner()) + 1];
    strcpy_s(owner, strlen(a.getOwner()) + 1, a.getOwner());
}

int Account::getBalance() const {
    return balance;
}

void Account::setBalance(double b) {
    balance = b;
}

char* Account::getOwner() const {
    return owner;
}

void Account::setOwner(const char* ow) {
    owner = new char[strlen(ow) + 1];
    strcpy_s(owner, strlen(ow) + 1, ow);
}

void Account::print() const
{
    cout << "Name: " << this->getOwner() << ",\t Balance: " << this->getBalance() << endl;
}

Account::Account() {
    cout << "Constructor Account() is called" << endl;
    balance = 0.0;
    owner = nullptr;
}

Account::Account(double b, const char* ow) { 
    cout << "Constructor Account(double, const char*) is called" << endl;
    balance = b;
    owner = new char[strlen(ow) + 1]; 
     //for (int i = 0; i < strlen(ow) + 1; i++) owner[i] = ow[i];
    strcpy_s(owner, strlen(ow) + 1,ow);
}

Account::~Account() {
    delete owner;
}

int main() {
    Account a1;
    a1.setBalance(1000);
    a1.setOwner("Account#01");
    a1.print();

    Account a2(2000, "Account#00002");
    a2.print();
    a2.setOwner("Account#02");
    a2.setBalance(5000);
    a2.print();

    Account* a3 = new Account();
    a3->setOwner("Account#03");
    a3->setBalance(6000);
    a3->print();

    Account* a4 = new Account(15000, "Account#04");
    a4->print();
    
    Account* a5 = new Account(*a4);
    a5->print();
    a5->setOwner("Account#05");
    a5->print();
    
    //delete a4;
    cout << "------------------------------------------" << endl;
    const int n=6;
    Account* accounts = new Account[n];
    accounts[0] = a1;
    accounts[1] = a2;
    accounts[2] = *a3;
    accounts[3] = *a4;
    accounts[4] = *a5;
    accounts[5] = *new Account(14000, "Account#06");

    for(int j=0;j<n;j++)
        accounts[j].print();
    accounts[4].setBalance(1000000);

    for (int j = 0; j < n; j++)
        accounts[j].print();
    cout << "------------------------------------------" << endl;
    Account** accounts_d = new Account*[n];
    accounts_d[0] = new Account(14000, "Account#06");
    accounts_d[1] = a5;

    accounts_d[0]->print();
    accounts_d[1]->print();

    a5->setBalance(50000);

    accounts_d[1]->print();
    return 0;
}