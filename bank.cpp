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

    /// getting the new customer object with filled details
    Customer *customer = getNewCustomerDetails();

    /// taking input to select type of account
    int customerAccountType = takeNumberInput<int>("Select:\n0: Checking\n1: Savings\n> ", "2");

    /// switch case to create the type of account based on selection
    switch (customerAccountType) {
        case 0: {
            /// creating a checking account
            account[accountNumberIndex] = new Checking_Account();
            account[accountNumberIndex]->create_Account(*customer, accountNumberIndex);
            break;
        }
        case 1: {
            /// creating a savings account
            account[accountNumberIndex] = new Savings_Account();
            account[accountNumberIndex]->create_Account(*customer, accountNumberIndex);

            break;
        }
        default:
            break;
    }
    /// incrementing account index
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
    /// taking input for name
    string customerName = takeStringInput("Enter Customer Name> ", "NAME");
    /// taking input for address
    string customerAddress = takeStringInput("Enter Customer Address> ", "NONE");
    /// taking input for age
    int customerAge = takeNumberInput<int>("Enter Customer Age> ", "AGE");
    /// taking input for phone number
    auto customerPhoneNumber = takeNumberInput<unsigned long>("Enter Customer Phone Number> ", "PHONE");

    /// creating customer object
    Customer *customerBase;

    /// taking input for account type
    int selectedOption = takeNumberInput<int>("Select:\n0: Senior\n1: Adult\n2: Student\n>" , "3");

    /// switch case for creating account type based on selection
    switch (selectedOption) {
        case 0: {
            /// creating a account for senior
            customerBase = new Senior();
            break;
        }
        case 1: {
            /// creating a account for adult
            customerBase = new Adult();
            break;
        }
        case 2: {
            /// creating a account for student
            customerBase = new Student();
            break;
        }
    }

    /// setting name
    customerBase->setName(customerName);
    /// setting address
    customerBase->setAddress(customerAddress);
    /// setting age
    customerBase->setAge(customerAge);
    /// setting phone
    customerBase->setTelephoneNumber(customerPhoneNumber);
    /// setting customer number
    customerBase->setCustomerNumber(this->customerNumberIndex);

    /// incrementing customer number index
    this->customerNumberIndex++;

    /// returning the customer object
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

    /// taking input for account number
    auto accountNumber = takeNumberInput<unsigned long>("Enter Account Number> ", "ACCOUNT");

    /// taking input for amount
    auto amount = takeNumberInput<double>("Enter The Amount> ", "BASIC");

    /// taking input for date
    Date date = takeDateInput("Enter the date yyyy-mm-dd> ");

    /// depositing money to account
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

    /// taking input for account number
    auto accountNumber = takeNumberInput<unsigned long>("Enter Account Number> ", "ACCOUNT");

    /// taking input for amount
    auto amount = takeNumberInput<double>("Enter The Amount> ", "BASIC");

    /// taking input for date
    Date date = takeDateInput("Enter the date yyyy-mm-dd> ");

    /// depositing money to account
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

    /// taking input for account number
    auto accountNumber = takeNumberInput<unsigned long>("Enter Account Number> ", "ACCOUNT");

    /// printing account details
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

    /// taking input
    cout << question;
    string input;
    cin >> input;

    /// if validation is for name then accept only letters
    if(validationType == "NAME"){
        if (none_of(input.begin(), input.end(), [](const char &c) {
            return !(std::isalpha(c));
        })) {
            /// return input
            return input;
        } else {
            /// show error is symbols or digits are entered
            printHeader("Invalid input. It should all be characters");
            /// take input again
            return takeStringInput(question, validationType);
        }
    } else {
        /// return input
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
    /// taking input
    cout << question;
    T input;
    cin >> input;

    /// if no char is entered it will pass
    if (cin.good()) {
        /// validate phone
        if(validationType == "PHONE"){
            if(to_string(input).length() == 10){
                return input;
            } else {
                printHeader("Invalid phone number. Please enter 10 digit phone number.");
            }
        }
        /// validate phone
        else if(validationType == "AGE"){
            if(input >= 18){
                return input;
            } else {
                printHeader("You should be min. 18 years of age before opening an account.");
                return takeNumberInput<T>(question, validationType);
            }
        }
        /// validate 2 options
        else if(validationType == "2"){
            if(input < 2 && input > -1){
                return input;
            } else {
                printHeader("Wrong Selection. Try again from the given options.");
                return takeNumberInput<T>(question, validationType);
            }
        }
        /// validate 3 options
        else if(validationType == "3"){
            if(input < 3 && input > -1){
                return input;
            } else {
                printHeader("Wrong Selection. Try again from the given options.");
                return takeNumberInput<T>(question, validationType);
            }
        }
        /// validate account number
        else if(validationType == "ACCOUNT"){
            if(input < this->accountNumberIndex){
                return input;
            } else {
                printHeader("Account number doesn't exist.");
                return takeNumberInput<T>(question, validationType);
            }
        }
        else {
            /// return input
            return input;
        }
    } else {
        /// print header with appropiate text
        printHeader("Invalid input. Only numbers are allowed.");
    }

    /// clear if error occurs
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /// recursive call
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
