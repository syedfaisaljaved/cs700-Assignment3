//
// Created by Faisal Javed on 17/10/22.
//

#include "customer.h"
#include <iostream>

using namespace std;

void Customer::setAddress(string &customerAddress) {
    this->address = customerAddress;
}

void Customer::setName(string &customerName) {
    this->name = customerName;
}

void Customer::setTelephoneNumber(unsigned long &customerTelephoneNumber) {
    this->telephone_number = customerTelephoneNumber;
}

void Customer::setAge(int &customerAge) {
    this->age = customerAge;
}

void Customer::setCustomerNumber(unsigned long &customerNumber) {
    this->customer_number = customerNumber;
}

std::string Customer::getName() {
    return this->name;
}

std::string Customer::getAddress() {
    return this->address;
}

int Customer::getAge() {
    return this->age;
}

std::string Adult::getAccountType() {
    return "Adult";
}

std::string Senior::getAccountType() {
    return "Senior";
}

double Senior::getSavingsInterest() {
    return SAVINGS_INTEREST;
}

double Senior::getCheckingInterest() {
    return CHECKING_INTEREST;
}

double Senior::getCheckCharge() {
    return CHECK_CHARGE;
}

double Senior::getOverDraftPenalty() {
    return OVERDRAFT_PENALTY;
}

double Adult::getSavingsInterest() {
    return SAVINGS_INTEREST;
}

double Adult::getCheckingInterest() {
    return CHECKING_INTEREST;
}

double Adult::getCheckCharge() {
    return CHECK_CHARGE;
}

double Adult::getOverDraftPenalty() {
    return OVERDRAFT_PENALTY;
}

double Student::getSavingsInterest() {
    return SAVINGS_INTEREST;
}

double Student::getCheckingInterest() {
    return CHECKING_INTEREST;
}

double Student::getCheckCharge() {
    return CHECK_CHARGE;
}

double Student::getOverDraftPenalty() {
    return OVERDRAFT_PENALTY;
}

std::string Student::getAccountType() {
    return "Student";
}
