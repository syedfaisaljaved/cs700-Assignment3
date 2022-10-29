//
// Created by Faisal Javed on 16/10/22.
//

#pragma once

#include "account.h"
#include <vector>

class Bank {
private:
    std::vector<Account*> account;
    std::string takeStringInput(const std::string& question);
    int takeIntegerInput(const std::string& question);
    Customer* getNewCustomerDetails();
    Account* get_account_number(unsigned long );


public:
    void add_accounts();

    void make_deposit();

    void make_withdrawal();

    void get_account();
};