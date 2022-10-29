//
// Created by Faisal Javed on 17/10/22.
//

#include "customer.h"
#include <iostream>

using namespace std;

void Customer::setAddress(string &customerAddress) {
    address = customerAddress;
}

void Customer::setName(string &customerName) {
    name = customerName;
}

void Customer::setTelephoneNumber(int &customerTelephoneNumber) {
    telephone_number = customerTelephoneNumber;
}

void Customer::setAge(int &customerAge) {
    age = customerAge;
}

void Customer::setCustomerNumber() {
    customer_number = customer_number+1;
}

