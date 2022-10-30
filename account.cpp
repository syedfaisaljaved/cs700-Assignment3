#include <iostream>
#include <sstream>
#include "account.h"

using namespace std;

unsigned long Account::get_account_number() const {
    return account_number;
}

double Account::get_balance() const {
    return balance;
}

Customer *Account::get_customer() {
    return customer;
}

string Account::to_string() {
    std::ostringstream oss;
    oss << "Account: " << this->get_account_number()
        << "\nOwner: " << this->get_customer()->getName()
        << "\nType of customer: " << this->get_customer()->getAccountType()
        << "\nBalance: " << this->get_balance();
    for(const auto transaction : this->transaction){
        oss << transaction->to_string() << "\n";
    }
    return oss.str();
}

void Account::set_customer(Customer &customer1) {
    customer = &customer1;
}

void Account::set_balance(double bal) {
    balance += bal;
}

void Account::create_Account(Customer &customer, unsigned long &accountNumber) {
    this->set_customer(customer);
    this->account_number = accountNumber;
    cout << "Account " << this->get_account_number() << " Added" << endl;
}

Transaction Account::getLastTransaction() {
    return *this->transaction[this->transaction.size() - 1];
}

void Savings_Account::deposit(double &amount, Date &date) {
    this->set_balance(amount);
    this->transaction.push_back(new Transaction("DEP", amount, this->get_balance(), date));
    cout << "\tDeposit in " << this->get_account_number() << transaction.back()->to_string() << endl;
}

void Savings_Account::withdraw(double &amount, Date &date) {
    if (amount > this->get_balance()) {
        /// overdraft penalty
        return;
    }

    this->add_interest(date);
    this->set_balance(-amount);
    this->transaction.push_back(new Transaction("WD", amount, this->get_balance(), date));
    cout << "\tWithdraw from " << this->get_account_number() << transaction.back()->to_string() << endl;
}

void Savings_Account::add_interest(Date &date) {
    double interest = this->get_balance() * this->get_customer()->SAVINGS_INTEREST *
                      (double) (date - this->getLastTransaction().getDate());
    this->set_balance(interest);
    this->transaction.push_back(new Transaction("INT CR", interest, this->get_balance(), date));
}

void Checking_Account::deposit(double &amount, Date &date) {
    this->set_balance(amount);
    this->transaction.push_back(new Transaction("DEP", amount, this->get_balance(), date));
    cout << "\tDeposit in " << this->get_account_number() << " amount: $" << amount << " on " << date
         << " new balance: $" << this->get_balance() << endl;
}

void Checking_Account::withdraw(double &amount, Date &date) {
    if (amount > this->get_balance()) {
        /// overdraft penalty
        return;
    }

    this->add_interest(date);
    this->set_balance(-amount);
    this->transaction.push_back(new Transaction("WD", amount, this->get_balance(), date));
    cout << "\tWithdraw from " << this->get_account_number() << transaction.back()->to_string() << endl;
}

void Checking_Account::add_interest(Date &date) {
    double interest = this->get_balance() * this->get_customer()->CHECKING_INTEREST *
                      (double) (date - this->getLastTransaction().getDate());
    this->set_balance(interest);
    this->transaction.push_back(new Transaction("INT CR", interest, this->get_balance(), date));
}
