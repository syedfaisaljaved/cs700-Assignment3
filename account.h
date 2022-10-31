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
    Customer* customer;
    double balance = 0;
    unsigned long account_number;
    std::vector<Transaction*> transaction;
    Transaction getLastTransaction();
public:
    void create_Account(Customer &, unsigned long &);
    unsigned long get_account_number() const;
    double get_balance() const;
    Customer* get_customer();
    void to_string();
    void set_customer(Customer &);
    void set_balance(double);
    virtual void deposit(double &, Date &) = 0;
    virtual void withdraw(double &, Date &) = 0;
    virtual void add_interest(Date &) = 0;
    void printHeader(const std::string&);

};

class Savings_Account : public Account {
public:
    void deposit(double &, Date &) override;
    void withdraw(double &, Date &) override;
    void add_interest(Date &) override;

};

class Checking_Account : public Account {
public:
    void deposit(double &, Date &) override;
    void withdraw(double &, Date &) override;
    void add_interest(Date &) override;
};

