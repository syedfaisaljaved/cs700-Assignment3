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
    int customer_number = 0;
public:
    void setName(std::string &);

    void setAddress(std::string &);

    void setAge(int &);

    void setTelephoneNumber(int &);

    void setCustomerNumber();

};

class Senior : public Customer {
private:
    const float SAVINGS_INTEREST = 0.04;
    const float CHECK_INTEREST = 0.01;
    const float CHECK_CHARGE = 0.01;
    const float OVERDRAFT_PENALTY = 25.0;
};

class Adult : public Customer {
private:
    const float SAVINGS_INTEREST = 0.03;
    const float CHECK_INTEREST = 0.01;
    const float CHECK_CHARGE = 0.03;
    const float OVERDRAFT_PENALTY = 25.0;
};

class Student : public Customer {
private:
    const float SAVINGS_INTEREST = 0.04;
    const float CHECK_INTEREST = 0.01;
    const float CHECK_CHARGE = 0.02;
    const float OVERDRAFT_PENALTY = 25.0;
};
