/*****************************
 * @name Module Name: Banking System Application.
 * @author Faisal Javed
 * @date 16th October, 2022
 * Purpose: CS-700 Assignment 3
 * Student ID: 200491169
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams. <br>
#include "account.h" /// user-defined header @file account.h to propagate declarations to code file. <br>

/**
 * 'namespace' is used to organise the names of program entities. <br>
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std. <br>
 * */
using namespace std;

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the account number. <br>
 *         @param [in] void
 *         @return [out] unsigned long
 *         @post Post Condition - returns the account number value.
 * */
unsigned long Account::get_account_number() const {
    /// return value
    return account_number;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the balance value.
 * */
double Account::get_balance() const {
    /// return value
    return this->balance;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] void
 *         @return [out] Customer
 *         @post Post Condition - returns the customer object.
 * */
Customer *Account::get_customer() {
    /// return value
    return this->customer;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in,out] void
 *         @return [out] void
 *         @post Post Condition - prints variables to the console in a formatted manner.
 * */
void Account::to_string() {
    /// print to console
    cout << "Account: " << this->get_account_number() << endl
         << "Owner: " << this->get_customer()->getName() << endl
         << "Type of customer: " << this->get_customer()->getAccountType() << endl
         << "Balance: " << this->get_balance() << endl;
    for (Transaction *eachTransac: this->transaction) {
        cout << eachTransac->to_string() << endl;
    }
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] customer
 *         @return [out] void
 *         @pre Pre Condition - Customer class object is passed
 *         @post Post Condition - sets the memory address of a class object to class customer data member.
 * */
void Account::set_customer(Customer &customer) {
    /// set value
    this->customer = &customer;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] balance
 *         @return [out] void
 *         @pre Pre Condition - a double value is passed
 *         @post Post Condition - sets the balance to the class balance data member
 * */
void Account::set_balance(double balance) {
    /// set value
    this->balance += balance;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] customer
 *         @param [in] accountNumber
 *         @return [out] void
 *         @pre Pre Condition - a double value and an object is passed
 *         @post Post Condition - calls a function, sets a value and prints to console
 * */
void Account::create_Account(Customer &customer, unsigned long &accountNumber) {
    /// create account
    this->set_customer(customer);
    this->account_number = accountNumber;
    cout << "Account " << this->get_account_number() << " Added" << endl;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] void
 *         @return [out] Transaction
 *         @post Post Condition - returns an object
 * */
Transaction Account::getLastTransaction() {
    /// return value
    return *this->transaction[this->transaction.size() - 1];
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] amount
 *         @param [in] date
 *         @return [out] void
 *         @pre Pre Condition - a double value and an object is passed
 *         @post Post Condition - sets a value and prints to console
 * */
void Savings_Account::deposit(double &amount, Date &date) {
    /// make deposit
    this->set_balance(amount);
    this->transaction.push_back(new Transaction("DEP", amount, this->get_balance(), date));
    cout << "\tDeposit in " << this->get_account_number() << " amount: $" << amount << " on " << date
         << " new balance: $" << this->get_balance() << endl;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] amount
 *         @param [in] date
 *         @return [out] void
 *         @pre Pre Condition - a double value and an object is passed
 *         @post Post Condition - sets many values and prints to console
 * */
void Savings_Account::withdraw(double &amount, Date &date) {
    /// withdraw money
    if (amount > this->get_balance()) {
        /// overdraft penalty
        double overDraftPenalty = this->get_customer()->getOverDraftPenalty();
        this->set_balance(-overDraftPenalty);
        this->transaction.push_back(new Transaction("OVRDFT PENALTY", overDraftPenalty, this->get_balance(), date));

        printHeader("Insufficient Balance. You have been charged overdraft penalty.");
        return;
    }

    this->add_interest(date);
    this->set_balance(-amount);
    this->transaction.push_back(new Transaction("WD", amount, this->get_balance(), date));

    cout << "\tWithdraw from " << this->get_account_number() << " amount: $" << amount << " on " << date
         << " new balance: $" << this->get_balance() << endl;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] date
 *         @return [out] void
 *         @pre Pre Condition - an object is passed
 *         @post Post Condition - calls functions to perform desired operations
 * */
void Savings_Account::add_interest(Date &date) {
    /// calc interest
    long dateDiff = date - this->getLastTransaction().getDate();
    double interest = this->get_balance() * this->get_customer()->getSavingsInterest() * (dateDiff/365.0);
    this->set_balance(interest);
    this->transaction.push_back(new Transaction("INT CR", interest, this->get_balance(), date));
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] amount
 *         @param [in] date
 *         @return [out] void
 *         @pre Pre Condition - a double value and an object is passed
 *         @post Post Condition - sets a value and prints to console
 * */
void Checking_Account::deposit(double &amount, Date &date) {
    /// make deposit
    this->set_balance(amount);
    this->transaction.push_back(new Transaction("DEP", amount, this->get_balance(), date));
    cout << "\tDeposit in " << this->get_account_number() << " amount: $" << amount << " on " << date
         << " new balance: $" << this->get_balance() << endl;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] amount
 *         @param [in] date
 *         @return [out] void
 *         @pre Pre Condition - a double value and an object is passed
 *         @post Post Condition - sets many values and prints to console
 * */
void Checking_Account::withdraw(double &amount, Date &date) {
    /// withdraw money
    if (amount > this->get_balance()) {
        /// overdraft penalty
        double overDraftPenalty = this->get_customer()->getOverDraftPenalty();
        this->set_balance(-overDraftPenalty);
        this->transaction.push_back(new Transaction("OVR PNTY", overDraftPenalty, this->get_balance(), date));

        printHeader("Insufficient Balance. You have been charged overdraft penalty.");
        return;
    }

    this->add_interest(date);
    this->set_balance(-amount);
    this->transaction.push_back(new Transaction("WD", amount, this->get_balance(), date));

    double checkingCharge = this->get_customer()->getCheckCharge();
    this->set_balance(-checkingCharge);
    this->transaction.push_back(new Transaction("CHK CHG", checkingCharge, this->get_balance(), date));

    cout << "\tWithdraw from " << this->get_account_number() << " amount: $" << amount << " on " << date
         << " new balance: $" << this->get_balance() << endl;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] date
 *         @return [out] void
 *         @pre Pre Condition - an object is passed
 *         @post Post Condition - calls functions to perform desired operations
 * */
void Checking_Account::add_interest(Date &date) {
    /// calc interest
    long dateDiff = date - this->getLastTransaction().getDate();
    double interest = this->get_balance() * this->get_customer()->getCheckingInterest() * (dateDiff/365.0);
    this->set_balance(interest);
    this->transaction.push_back(new Transaction("INT CR", interest, this->get_balance(), date));
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] output
 *         @return [out] void
 *         @pre Pre Condition - a const string is passed
 *         @post Post Condition - prints to console
 * */
void Account::printHeader(const string& output) {
    /// print to console
    cout << "\n********************************************************\n";
    cout << output << endl;
    cout << "********************************************************\n\n";
}