//
// Created by Faisal Javed on 17/10/22.
//

#include "account.h"

unsigned long Account::get_account_number() const {
    return account_number;
}

float Account::get_balance() {
    return balance;
}

Customer Account::get_customer() {
    return customer;
}

void Account::to_string() {

}

void Account::set_customer(Customer &customer1) {
    customer = customer1;
}

void Account::set_balance(float &bal) {
    balance = bal;
}

void Account::create_Account(Customer &customer, unsigned long accountNumber) {
    set_customer(customer);
    account_number = accountNumber;
}

void Savings_Account::deposit() {

}

void Savings_Account::withdraw() {

}

void Savings_Account::add_interest() {

}

void Checking_Account::deposit() {

}

void Checking_Account::withdraw() {

}

void Checking_Account::add_interest() {

}
