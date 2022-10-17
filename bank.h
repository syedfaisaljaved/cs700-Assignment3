//
// Created by Faisal Javed on 16/10/22.
//

#pragma once

#include "account.h"

class Bank {
private:
    Account account[];
public:
    void add_accounts();

    void make_deposit();

    void make_withdrawal();

    Account get_account();
};