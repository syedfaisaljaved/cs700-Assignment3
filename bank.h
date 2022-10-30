//
// Created by Faisal Javed on 16/10/22.
//

#pragma once

#include "account.h"
#include <vector>

class Bank {
private:
    Account* account[100];
    std::string takeOnlyCharInput(const std::string& question);
    template<typename T>
    T takeStringInput(const std::string& question);
    template<typename T>
    T takeNumberInput(const std::string &);
    Customer* getNewCustomerDetails();
    unsigned long accountNumberIndex = 0;
    unsigned long customerNumberIndex = 0;


public:
    void add_accounts();

    void make_deposit();

    void make_withdrawal();

    void get_account();

};