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
#include <vector> /// library called vectors are sequence containers representing arrays that can change in size.
#include "customer.h" /// user-defined header @file customer.h to propagate declarations to code file.
#include "transaction.h" /// user-defined header @file transaction.h to propagate declarations to code file.

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Account which contains variables, methods.
 *          @var Customer* customer
 *          @var double balance
 *          @var unsigned long account_number
 *          @var vector<Transaction*> transaction
 *          @fn getLastTransaction
 *          @fn create_Account
 *          @fn get_account_number
 *          @fn get_balance
 *          @fn to_string
 *          @fn set_customer
 *          @fn set_balance
 *          @fn deposit
 *          @fn withdraw
 *          @fn add_interest
 *          @fn printHeader
 * */
class Account {
protected:
    /**
     * @brief Customer pointer object.
     * */
    Customer* customer;
    /**
     * @brief double variable assigned value 0.
     * */
    double balance = 0;
    /**
     * @brief unsigned long variable declaration.
     * */
    unsigned long account_number;
    /**
     * @brief vector of data type Transaction pointer object.
     * */
    std::vector<Transaction*> transaction;
    /**
     * @brief method taking no params and returning Transaction class object.
     * */
    Transaction getLastTransaction();

public:
    /**
     * @brief method taking 2 params.
     * */
    void create_Account(Customer &, unsigned long &);
    /**
     * @brief const method taking no params.
     * */
    unsigned long get_account_number() const;
    /**
     * @brief const method taking no params.
     * */
    double get_balance() const;
    /**
     * @brief method taking no params and returning a Customer class pointer object.
     * */
    Customer* get_customer();
    /**
     * @brief method taking no params.
     * */
    void to_string();
    /**
     * @brief method taking 1 params.
     * */
    void set_customer(Customer &);
    /**
     * @brief method taking 1 params.
     * */
    void set_balance(double);
    /**
     * @brief pure virtual method taking 2 params.
     * */
    virtual void deposit(double &, Date &) = 0;
    /**
     * @brief pure virtual method taking 2 params.
     * */
    virtual void withdraw(double &, Date &) = 0;
    /**
     * @brief pure virtual method taking 1 param.
     * */
    virtual void add_interest(Date &) = 0;
    /**
     * @brief method taking 1 param.
     * */
    void printHeader(const std::string&);
};

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Savings_Account which inherits @class Account which contains variables, methods and constructors.
 *          @fn deposit
 *          @fn withdraw
 *          @fn add_interest
 * */
class Savings_Account : public Account {
public:
    /**
     * @brief method taking 2 params.
     * */
    void deposit(double &, Date &) override;
    /**
     * @brief method taking 2 params.
     * */
    void withdraw(double &, Date &) override;
    /**
     * @brief method taking 1 param.
     * */
    void add_interest(Date &) override;

};

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Checking_Account which inherits @class Account which contains variables, methods and constructors.
 *          @fn deposit
 *          @fn withdraw
 *          @fn add_interest
 * */
class Checking_Account : public Account {
public:
    /**
     * @brief method taking 2 params.
     * */
    void deposit(double &, Date &) override;
    /**
     * @brief method taking 2 params.
     * */
    void withdraw(double &, Date &) override;
    /**
     * @brief method taking 1 param.
     * */
    void add_interest(Date &) override;
};

