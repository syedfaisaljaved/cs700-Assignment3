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
    float balance = 0;
    unsigned long account_number;
    std::vector<Transaction*> transaction;
public:
    void create_Account(Customer &, unsigned long &);
    unsigned long get_account_number() const;
    float get_balance();
    Customer* get_customer();
    void to_string();
    void set_customer(Customer &);
    void set_balance(float &);
    virtual void deposit(float &, Date &) = 0;
    virtual void withdraw(float &) = 0;
    virtual void add_interest() = 0;
};

class Savings_Account : public Account {
public:
    void deposit(float &, Date &) override;
    void withdraw(float &) override;
    void add_interest() override;

};

class Checking_Account : public Account {
public:
    void deposit(float &, Date &) override;
    void withdraw(float &) override;
    void add_interest() override;
};

