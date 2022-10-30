#include <iostream>
#include "account.h"

using namespace std;

unsigned long Account::get_account_number() const {
    return account_number;
}

float Account::get_balance() {
    return balance;
}

Customer* Account::get_customer() {
    return &customer;
}

void Account::to_string() {
    cout << "account to string" << endl;
}

void Account::set_customer(Customer &customer1) {
    customer = customer1;
}

void Account::set_balance(float &bal) {
    balance += bal;
}

void Account::create_Account(Customer &customer, unsigned long &accountNumber) {
    this->set_customer(customer);
    this->account_number = accountNumber;
    cout << "Account " << this->get_account_number() << " Added" << endl;
}

void Savings_Account::deposit(float &amount, Date &date) {
    this->set_balance(amount);
    this->transaction.push_back(new Transaction("DEP",amount, date));
    cout << "Deposit in " << this->get_account_number() << " amount: $" << amount << " on " << date << " new balance: $" << this->get_balance() << endl;
}

void Savings_Account::withdraw(float &amount) {

}

void Savings_Account::add_interest() {

}

void Checking_Account::deposit(float &amount, Date &date) {
    this->set_balance(amount);
    this->transaction.push_back(new Transaction("DEP",amount, date));
    cout << "Deposit in " << this->get_account_number() << " amount: $" << amount << " on " << date << " new balance: $" << this->get_balance() << endl;
}

void Checking_Account::withdraw(float &amount) {

}

void Checking_Account::add_interest() {
    cout << "add interest" << endl;
}
