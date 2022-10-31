/*****************************
 * @name Module Name: Banking System Application.
 * @author Faisal Javed
 * @date 16th October, 2022
 * Purpose: CS-700 Assignment 3
 * Student ID: 200491169
 ****************************/

/**
  * Code placed here is included only once per translation unit.
  * '#pragma once' is non-standard preprocessor directive intended for implementing compiler-specific preprocessor instructions.
  * It's purpose is to replace the include guards that you use in header files to avoid multiple inclusion.
  * */
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