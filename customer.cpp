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

