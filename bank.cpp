#include <iostream>
#include "bank.h"
#include "Date.h"
#include <iostream>
#include <vector>


using namespace std;

void Bank::add_accounts() {

    Customer *customer = getNewCustomerDetails();
    cout << "Select:" << endl << "0: Checking" << endl << "1: Savings" << endl << "> ";

    int customerAccountType = takeIntegerInput("");

    vector<int> vec;

    unsigned long newAccountNumber = account.size();

    cout << "new acc number" << newAccountNumber << endl;
    switch (customerAccountType) {
        case 0: {
            Checking_Account checkingAccount;
            checkingAccount.create_Account(*customer, account.size());
            account.push_back(&checkingAccount);
            break;
        }
        case 1: {
            Savings_Account savingsAccount;
            savingsAccount.create_Account(*customer, account.size());
            account.push_back(&savingsAccount);
            break;
        }
        default:
            break;
    }

    cout << "Account " << account[account.size()-1]->get_account_number() << " Added" << endl;

}

Customer *Bank::getNewCustomerDetails() {
    string customerName = takeStringInput("Enter Customer Name> ");
    string customerAddress = takeStringInput("Enter Customer Address> ");
    int customerAge = takeIntegerInput("Enter Customer Age> ");
    int customerPhoneNumber = takeIntegerInput("Enter Customer Phone Number> ");


    Customer *customerBase;

    cout << "Select:" << endl << "0: Senior" << endl << "1: Adult" << endl << "2: Student" << endl << "> ";
    int selectedOption = takeIntegerInput("");

    switch (selectedOption) {
        case 0: {
            Senior seniorCustomer;
            seniorCustomer.setName(customerName);
            seniorCustomer.setAddress(customerAddress);
            seniorCustomer.setAge(customerAge);
            seniorCustomer.setTelephoneNumber(customerPhoneNumber);
            seniorCustomer.setCustomerNumber();
            customerBase = &seniorCustomer;
            break;
        }
        case 1: {
            Adult adultCustomer;
            adultCustomer.setName(customerName);
            adultCustomer.setAddress(customerAddress);
            adultCustomer.setAge(customerAge);
            adultCustomer.setTelephoneNumber(customerPhoneNumber);
            adultCustomer.setCustomerNumber();
            customerBase = &adultCustomer;
            break;
        }
        case 2: {
            Student studentCustomer;
            studentCustomer.setName(customerName);
            studentCustomer.setAddress(customerAddress);
            studentCustomer.setAge(customerAge);
            studentCustomer.setTelephoneNumber(customerPhoneNumber);
            studentCustomer.setCustomerNumber();
            customerBase = &studentCustomer;
            break;
        }
        default:
            break;
    }

    return customerBase;
}


void Bank::make_deposit() {

}

void Bank::make_withdrawal() {

}

void Bank::get_account() {

}

string Bank::takeStringInput(const string &question) {
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
    return takeStringInput(question);
}

int Bank::takeIntegerInput(const string &question) {
    cout << question;
    int input;
    cin >> input;

    if (!isdigit(input)) {
        return input;
    } else {
        cout << "invalid input. only numbers are allowed" << endl;
    }
    return takeIntegerInput(question);
}

Account *Bank::get_account_number(unsigned long accountIndex) {
    return account[accountIndex];
}
