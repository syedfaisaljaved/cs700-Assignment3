/*****************************
 * @name Module Name: Banking System Application.
 * @author Faisal Javed
 * @date 16th October, 2022
 * Purpose: CS-700 Assignment 3
 * Student ID: 200491169
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams. <br>
#include "bank.h" /// user-defined header @file bank.h to propagate declarations to code file. <br>
#include "Date.h" /// user-defined header @file Date.h to propagate declarations to code file. <br>
#include <algorithm> /// library defines a collection of functions especially designed to be used on ranges of element <br>

/**
 * 'namespace' is used to organise the names of program entities. <br>
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std. <br>
 * */
using namespace std;

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to add account. <br>
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - adds an account.
 * */
void Bank::add_accounts() {

    Customer *customer = getNewCustomerDetails();

    int customerAccountType = takeNumberInput<int>("Select:\n0: Checking\n1: Savings\n> ", "2");

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

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get new customer details. <br>
 *         @param [in] void
 *         @return [out] Customer*
 *         @post Post Condition - returns a customer class pointer object
 * */
Customer* Bank::getNewCustomerDetails() {
    string customerName = takeStringInput("Enter Customer Name> ", "NAME");
    string customerAddress = takeStringInput("Enter Customer Address> ", "NONE");
    int customerAge = takeNumberInput<int>("Enter Customer Age> ", "AGE");
    auto customerPhoneNumber = takeNumberInput<unsigned long>("Enter Customer Phone Number> ", "PHONE");


    Customer *customerBase;

    int selectedOption = takeNumberInput<int>("Select:\n0: Senior\n1: Adult\n2: Student\n>" , "3");

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

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to deposit amount to account. <br>
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - deposit amount to account.
 * */
void Bank::make_deposit() {

    auto accountNumber = takeNumberInput<unsigned long>("Enter Account Number> ", "ACCOUNT");

    auto amount = takeNumberInput<double>("Enter The Amount> ", "BASIC");

    Date date = takeDateInput("Enter the date yyyy-mm-dd> ");
    account[accountNumber]->deposit(amount,date);

}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to withdraw amount from account. <br>
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - withdraw amount from account.
 * */
void Bank::make_withdrawal() {
    auto accountNumber = takeNumberInput<unsigned long>("Enter Account Number> ", "ACCOUNT");

    auto amount = takeNumberInput<double>("Enter The Amount> ", "BASIC");

    Date date = takeDateInput("Enter the date yyyy-mm-dd> ");
    account[accountNumber]->withdraw(amount,date);
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the account details. <br>
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - returns account details
 * */
void Bank::get_account() {
    auto accountNumber = takeNumberInput<unsigned long>("Enter Account Number> ", "ACCOUNT");

    account[accountNumber]->to_string();
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to take a string input. <br>
 *         @param [in] question
 *         @param [in] validationType
 *         @return [out] string
 *         @pre Pre Condition - 2 strings are passed
 *         @post Post Condition - returns a string after taking an input.
 * */
string Bank::takeStringInput(const string &question, string validationType) {
    cout << question;
    string input;
    cin >> input;

    if(validationType == "NAME"){
        if (none_of(input.begin(), input.end(), [](const char &c) {
            return !(std::isalpha(c));
        })) {
            return input;
        } else {
            printHeader("Invalid input. It should all be characters");
            return takeStringInput(question, validationType);
        }
    } else {
        return input;
    }

}


/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to return T data type after taking input. <br>
 *         @param [in] question
 *         @param [in] validationType
 *         @return [out] T
 *         @pre Pre Condition - 2 strings are passed
 *         @post Post Condition - returns a T data type after taking an input.
 * */
template<typename T>
T Bank::takeNumberInput(const string &question, string validationType) {
    cout << question;
    T input;
    cin >> input;

    if (cin.good()) {
        if(validationType == "PHONE"){
            if(to_string(input).length() == 10){
                return input;
            } else {
                printHeader("Invalid phone number. Please enter 10 digit phone number.");
            }
        }
        else if(validationType == "AGE"){
            if(input >= 18){
                return input;
            } else {
                printHeader("You should be min. 18 years of age before opening an account.");
                return takeNumberInput<T>(question, validationType);
            }
        } else if(validationType == "2"){
            if(input < 2 && input > -1){
                return input;
            } else {
                printHeader("Wrong Selection. Try again from the given options.");
                return takeNumberInput<T>(question, validationType);
            }
        } else if(validationType == "3"){
            if(input < 3 && input > -1){
                return input;
            } else {
                printHeader("Wrong Selection. Try again from the given options.");
                return takeNumberInput<T>(question, validationType);
            }
        } else if(validationType == "ACCOUNT"){
            if(input < this->accountNumberIndex){
                return input;
            } else {
                printHeader("Account number doesn't exist.");
                return takeNumberInput<T>(question, validationType);
            }
        }
        else {
            return input;
        }
    } else {
        printHeader("Invalid input. Only numbers are allowed.");
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return takeNumberInput<T>(question, validationType);
}


/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to return a date after taking an input. <br>
 *         @param [in] question
 *         @return [out] Date
 *         @pre Pre Condition - a string is passed
 *         @post Post Condition - returns a Date object.
 * */
Date Bank::takeDateInput(const string &question) {
    cout << question;
    Date input;
    cin >> input;
    return input;
}


/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to print the input. <br>
 *         @param [in] output
 *         @return [out] void
 *         @pre Pre Condition - a string is passed
 *         @post Post Condition - prints to console.
 * */
void Bank::printHeader(const string& output) {
    cout << "\n********************************************************\n";
    cout << output << endl;
    cout << "********************************************************\n\n";
}
