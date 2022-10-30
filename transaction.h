//
// Created by Faisal Javed on 17/10/22.
//

#pragma once

#include <iostream>
#include <utility>
#include "Date.h"


class Transaction {
private:
    std::string transaction_type;
    float amount_balance;
    Date date;
public:
    Transaction(std::string transactionType, float amount, const Date& date) : transaction_type(std::move(transactionType)), amount_balance(amount), date(date){}
    void to_string();
};