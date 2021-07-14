// Class composition. Class Account and Owner. Objects of Accounts are created statically

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNum;      // Account number
    double balance;      // Account balance

public:
    Account();	                     // Default constructor    
    Account(int, double);            // Regular constructor
    Account(const Account&);         // Copy constructor
    ~Account();                      // Destructor

    int getAccountNumber() const;    // Returns account number 
    double withdrawal(double);       // Makes a withdrawal
    double deposit(double);          // Makes a deposit
    void setBalance(double);         // Sets the balance
    double getBalance() const;       // Returns the balance
};

// Default constructor
Account::Account() {
    accountNum = 0;
    balance = 0;
}

// Regular constructor
Account::Account(int an, double b) : accountNum(an), balance(b) {}

// Copy constructor
Account::Account(const Account& a) : accountNum(a.accountNum), balance(a.balance){}

// Destructor
Account::~Account() {
    // We do not need nothing
}

// Returns account number
int Account::getAccountNumber() const {
    return accountNum;
}

// Makes a withdrawal
double Account::withdrawal(double amount) {
    if (balance >= amount)
        balance = balance - amount;
    else
        cout << "Insufficient funds" << endl;
    return balance;
}

// Makes a deposit (assume amount is positive)
double Account::deposit(double amount) {
    balance = balance + amount;
    return balance;
}

// Sets the balance (we may not need this since we can change balance through withdrawal and deposit functions)
void Account::setBalance(double b) {
    balance = b;
}

// Returns the balance
double Account::getBalance() const {
    return balance;
}


class Owner {
private:
    int id;      // Owner id
    string name; // Owner name 

    // We omitted other owner's infor for simplicity

    Account* accounts;     // List of accounts of this person (10 accounts max)
    int numAccounts;        // The current number of accounts held  by this owner                   

public:
    Owner();	            // Default constructor    
    Owner(int, string);     // Initializes attributes of Owner with user input
    Owner(const Owner&);    // Copy constructor
    ~Owner();               // Destructor needed is Owner contains pointers

    /* Getters and setter */
    int getID() const;
    string getName() const;

    /* Subsystem that manages arrays */

    void addAccount(const Account&);        // Adds an account to the person
    void removeAccount(int);                // Removes an account
    void listAllAccounts() const;	        // Displays all accounts of the person
    bool searchAccount(int) const;          // Searches if the account number entered is an account of this person
};


// Default constructor    
Owner::Owner() {
    id = 0;
    name = "";
    accounts = new Account[10];
    numAccounts = 0;
}

// Initializes attributes of Owner
Owner::Owner(int id1, string name1) {
    id = id1;
    name = name1;
    accounts = new Account[10];
    numAccounts = 0;
}

// Copy constructor
Owner::Owner(const Owner& anotherOwner) {
    name = anotherOwner.name;
    accounts = new Account[10];
    numAccounts = anotherOwner.numAccounts;
    for (int i = 0; i < numAccounts; i++)
        accounts[i] = anotherOwner.accounts[i];
}

// Destructor 
Owner::~Owner() {
    delete[] accounts;
}

int Owner::getID() const {
    return id;
}

string Owner::getName() const {
    return name;
}

// Adds an account to the person
void Owner::addAccount(const Account& a) {
    if (numAccounts < 10) {
        accounts[numAccounts] = a;
        numAccounts++;
    }
    else {
        cout << "Account: " << a.getAccountNumber() << " cannot be added – number of  accounts exceeded " << endl;
    }
    return;
}

// Removes an account using account number
void Owner::removeAccount(int acct) {
    // We need to search for acct first
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].getAccountNumber() == acct) {
            // We need to shift the  elements of the array
            for (int j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1]; //shifts the elements of the array
            } 
            numAccounts--;
            return;
        }
    }
    cout << "Account " << acct << " cannot be found!" << endl;
}

// displays all accounts of the person
void Owner::listAllAccounts()  const {
    for (int i = 0; i < numAccounts; i++)
        cout << "Account:  " << accounts[i].getAccountNumber() << endl;
}

// Searches if the account number entered is an account of this person
bool Owner::searchAccount(int accountNum) const {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].getAccountNumber() == accountNum)
            return true;
    }
    return false;
}


int main() {

    Account a1(11111, 500.00);
    Account a2(22222, 900.00);
    Account a3(33333, 1500.00);

    Owner o1(100, "Ric");
    Owner o2(200, "Karen");

    o1.addAccount(a1);
    o1.addAccount(a2);
    cout << o1.getName() << "'s accounts:" << endl;
    o1.listAllAccounts();

    if (o1.searchAccount(11111))
        cout << o1.getName() << " is the owner of Account 11111" << endl;
    else
        cout << o1.getName() << " is not the owner of Account 11111" << endl;

    cout << endl;

    o1.removeAccount(11111);
    cout << o1.getName() << "'s new accounts:" << endl;
    o1.listAllAccounts();

    cout << endl;

    o2.addAccount(a3);
    cout << o2.getName() << "'s accounts:" << endl;
    o2.listAllAccounts();

    return 0;
}