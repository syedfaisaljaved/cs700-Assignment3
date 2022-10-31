#include <iostream>
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

void Account::to_string() {
    cout << "Account: " << this->get_account_number() << endl
         << "Owner: " << this->get_customer()->getName() << endl
         << "Type of customer: " << this->get_customer()->getAccountType() << endl
         << "Balance: " << this->get_balance() << endl;
    for (Transaction *eachTransac: this->transaction) {
        cout << eachTransac->to_string() << endl;
    }
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
    cout << "\tDeposit in " << this->get_account_number() << " amount: $" << amount << " on " << date
         << " new balance: $" << this->get_balance() << endl;
}

void Savings_Account::withdraw(double &amount, Date &date) {
    if (amount > this->get_balance()) {
        /// overdraft penalty
        double overDraftPenalty = this->get_customer()->getOverDraftPenalty();
        this->set_balance(-overDraftPenalty);
        this->transaction.push_back(new Transaction("OVRDFT PENALTY", overDraftPenalty, this->get_balance(), date));

        cout << "Insufficient Balance. You have been charged overdraft penalty." << endl;
        return;
    }

    this->add_interest(date);
    this->set_balance(-amount);
    this->transaction.push_back(new Transaction("WD", amount, this->get_balance(), date));

    cout << "\tWithdraw from " << this->get_account_number() << " amount: $" << amount << " on " << date
         << " new balance: $" << this->get_balance() << endl;
}

void Savings_Account::add_interest(Date &date) {
    long dateDiff = date - this->getLastTransaction().getDate();
    double interest = this->get_balance() * this->get_customer()->getCheckingInterest() * (dateDiff/365.0);
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
        double overDraftPenalty = this->get_customer()->getOverDraftPenalty();
        this->set_balance(-overDraftPenalty);
        this->transaction.push_back(new Transaction("OVRDFT PENALTY", overDraftPenalty, this->get_balance(), date));

        cout << "Insufficient Balance. You have been charged overdraft penalty." << endl;
        return;
    }

    this->add_interest(date);
    this->set_balance(-amount);
    this->transaction.push_back(new Transaction("WD", amount, this->get_balance(), date));

    double checkingCharge = this->get_customer()->getCheckCharge();
    this->set_balance(-checkingCharge);
    this->transaction.push_back(new Transaction("CHKCHG", checkingCharge, this->get_balance(), date));

    cout << "\tWithdraw from " << this->get_account_number() << " amount: $" << amount << " on " << date
         << " new balance: $" << this->get_balance() << endl;
}

void Checking_Account::add_interest(Date &date) {
    long dateDiff = date - this->getLastTransaction().getDate();
    double interest = this->get_balance() * this->get_customer()->getCheckingInterest() * (dateDiff/365.0);
    this->set_balance(interest);
    this->transaction.push_back(new Transaction("INT CR", interest, this->get_balance(), date));
}
