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
    double amount;
    double balance;
    Date date;
public:
    Transaction(std::string transactionType, double amount, double balance, const Date& date) : transaction_type(std::move(transactionType)), amount(amount), balance(balance), date(date){}
    std::string to_string();
    double getAmount();
    double getBalance();
    Date getDate();
    std::string getTransactionType();
};