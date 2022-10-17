//
// Created by Faisal Javed on 17/10/22.
//

#pragma once

#include <iostream>
#include "Date.h"


class Transaction {
private:
    std::string transaction_type;
    float amount_balance;
    Date date;
public:
    void to_string();
};