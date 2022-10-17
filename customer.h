//
// Created by Faisal Javed on 17/10/22.
//

#pragma once

#include <iostream>

class Customer {
private:
    std::string name;
    std::string address;
    int age;
    int telephone_number;
    int customer_number;
public:
    void setName(std::string);

    void setAddress(std::string);

    void setAge(int);

    void setTelephoneNumber();

    void setCustomerNumber();

};

class Senior : public Customer {
private:
    const int SAVINGS_INTEREST = 0;
    const int CHECK_INTEREST = 0;
    const int CHECK_CHARGE = 0;
    const int OVERDRAFT_PENALTY = 0;
};

class Adult : public Customer {
private:
    const int SAVINGS_INTEREST = 0;
    const int CHECK_INTEREST = 0;
    const int CHECK_CHARGE = 0;
    const int OVERDRAFT_PENALTY = 0;
};

class Student : public Customer {
private:
    const int SAVINGS_INTEREST = 0;
    const int CHECK_INTEREST = 0;
    const int CHECK_CHARGE = 0;
    const int OVERDRAFT_PENALTY = 0;
};
