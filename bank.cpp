#include <iostream>
#include "bank.h"
#include "Date.h"
#include <iostream>
#include <vector>


using namespace std;

void Bank::add_accounts() {

    Customer *customer = getNewCustomerDetails();
    cout << "Select:" << endl << "0: Checking" << endl << "1: Savings" << endl << "> ";

    int customerAccountType = takeNumberInput<int>("");

    switch (customerAccountType) {
        case 0: {
            account[accountNumberIndex] = new Checking_Account();
            account[accountNumberIndex]->create_Account(*customer, accountNumberIndex);
            break;
        }
        case 1: {
            account[accountNumberIndex] = new Savings_Account();
            account[accountNumberIndex]->create_Account(*customer, accountNumberIndex);

            break;
        }
        default:
            break;
    }

    accountNumberIndex++;
}

Customer* Bank::getNewCustomerDetails() {
    string customerName = takeOnlyCharInput("Enter Customer Name> ");
    string customerAddress = takeStringInput<string>("Enter Customer Address> ");
    int customerAge = takeNumberInput<int>("Enter Customer Age> ");
    auto customerPhoneNumber = takeNumberInput<unsigned long>("Enter Customer Phone Number> ");


    Customer *customerBase;

    cout << "Select:" << endl << "0: Senior" << endl << "1: Adult" << endl << "2: Student" << endl << "> ";
    int selectedOption = takeNumberInput<int>("");

    switch (selectedOption) {
        case 0: {
            customerBase = new Senior();
            break;
        }
        case 1: {
            customerBase = new Adult();
            break;
        }
        case 2: {
            customerBase = new Student();
            break;
        }
    }

    customerBase->setName(customerName);
    customerBase->setAddress(customerAddress);
    customerBase->setAge(customerAge);
    customerBase->setTelephoneNumber(customerPhoneNumber);
    customerBase->setCustomerNumber(this->customerNumberIndex);

    this->customerNumberIndex++;

    return customerBase;
}


void Bank::make_deposit() {

    auto accountNumber = takeNumberInput<unsigned long>("Enter Account Number> ");

    while(true){
        if(accountNumber <= this->accountNumberIndex){
            break;
        }
        cout << "account number doesnt exist" << endl;
    }

    auto amount = takeNumberInput<double>("Enter The Amount> ");

    Date date = takeStringInput<Date>("Enter the date yyyy-mm-dd> ");
    account[accountNumber]->deposit(amount,date);

}

void Bank::make_withdrawal() {
    auto accountNumber = takeNumberInput<unsigned long>("Enter Account Number> ");

    while(true){
        if(accountNumber <= this->accountNumberIndex){
            break;
        }
        cout << "account number doesnt exist" << endl;
    }

    auto amount = takeNumberInput<double>("Enter The Amount> ");

    Date date = takeStringInput<Date>("Enter the date yyyy-mm-dd> ");
    account[accountNumber]->withdraw(amount,date);
}

void Bank::get_account() {

}

string Bank::takeOnlyCharInput(const string &question) {
    cout << question;
    string input;
    cin >> input;

    if (none_of(input.begin(), input.end(), [](const char &c) {
        return !(std::isalpha(c) || c == ' ');
    })) {
        return input;
    } else {
        cout << "invalid input. only numbers letters are allowed" << endl;
    }
    return takeOnlyCharInput(question);
}

template<typename T>
T Bank::takeNumberInput(const string &question) {
    cout << question;
    T input;
    cin >> input;

    if (!isdigit(input)) {
        return input;
    } else {
        cout << "invalid input. only numbers are allowed" << endl;
    }
    return takeNumberInput<T>(question);
}

template<typename T>
T Bank::takeStringInput(const string &question) {
    cout << question;
    T input;
    cin >> input;

    return input;
}
