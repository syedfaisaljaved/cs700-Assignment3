//
// Created by Faisal Javed on 17/10/22.
//

#pragma once

#include <iostream>
#include <vector>
#include "customer.h"
#include "transaction.h"

class Account {
protected:
    Customer customer;
    float balance;
    unsigned long account_number;
    std::vector<Transaction*> transaction;
public:
    void create_Account(Customer &, unsigned long );
    unsigned long get_account_number() const;
    float get_balance();
    Customer get_customer();
    void to_string();
    void set_customer(Customer &);
    void set_balance(float &);
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    virtual void add_interest() = 0;
};

class Savings_Account : public Account {
public:
    void deposit();
    void withdraw();
    void add_interest();

};

class Checking_Account : public Account {
public:
    void deposit();
    void withdraw();
    void add_interest();
};

