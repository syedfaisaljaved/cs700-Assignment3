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

#include "account.h" /// user-defined header @file account.h to propagate declarations to code file. <br>
#include <vector> /// library called vectors are sequence containers representing arrays that can change in size.
#include <algorithm> /// library defines a collection of functions especially designed to be used on ranges of element <br>

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Bank which contains variables, methods.
 *          @var Account* account
 *          @var unsigned long accountNumberIndex
 *          @var unsigned long customerNumberIndex
 *          @fn takeStringInput
 *          @fn takeDateInput
 *          @fn takeNumberInput
 *          @fn getNewCustomerDetails
 *          @fn printHeader
 * */
class Bank {
private:
    /**
     * @brief Account pointer object.
     * */
    Account *account[100];
    /**
     * @brief unsigned long variable declaration.
     * */
    unsigned long accountNumberIndex = 0;
    /**
     * @brief unsigned long variable declaration.
     * */
    unsigned long customerNumberIndex = 0;
    /**
     * @brief method taking 2 params.
     * */
    std::string takeStringInput(const std::string &question, std::string validationType);
    /**
     * @brief method taking 1 param.
     * */
    Date takeDateInput(const std::string &question);
    /**
     * @brief method taking 2 params.
     * */
    template<typename T>
    T takeNumberInput(const std::string &, std::string);
    /**
     * @brief method taking no params.
     * */
    Customer *getNewCustomerDetails();
    /**
     * @brief method taking 1 param.
     * */
    void printHeader(const std::string&);

public:
    /**
     * @brief method taking no params.
     * */
    void add_accounts();
    /**
     * @brief method taking no params.
     * */
    void make_deposit();
    /**
     * @brief method taking no params.
     * */
    void make_withdrawal();
    /**
     * @brief method taking no params.
     * */
    void get_account();

};