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

#include <iostream> /// library that controls reading from and writing to the standard streams.
#include "Date.h" /// user-defined header @file Date.h to propagate declarations to code file.

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Account which contains variables, methods and Constructors.
 *          @var string transaction_type
 *          @var double amount
 *          @var double balance
 *          @var Date date
 *          @fn to_string
 *          @fn getAmount
 *          @fn getBalance
 *          @fn getDate
 *          @fn getTransactionType
 * */
class Transaction {
private:
    /// declaring data members;
    std::string transaction_type;
    double amount;
    double balance;
    Date date;
public:
    /// declaring member functions.
    /**
     * @brief explicit Constructor taking 1 param
     * @param [in] int
     * @return [out] void
     * @pre Pre Condition - a string, 2 double and a Date object is passed
     * @post Post Condition - values are set to the respective variables.
     * */
    Transaction(std::string transactionType, double amount, double balance, const Date& date) : transaction_type(std::move(transactionType)), amount(amount), balance(balance), date(date){}
    std::string to_string();
    double getAmount();
    double getBalance();
    Date getDate();
    std::string getTransactionType();
};