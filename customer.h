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

#include <iostream> /// user-defined header @file customer.h to propagate declarations to code file.

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Customer which contains variables, methods.
 *          @var string name
 *          @var string address
 *          @var int age
 *          @var unsigned long telephone_number
 *          @var unsigned long customer_number
 *          @fn setName
 *          @fn setAddress
 *          @fn setAge
 *          @fn getName
 *          @fn getAddress
 *          @fn getAge
 *          @fn getAccountType
 *          @fn getSavingsInterest
 *          @fn getCheckingInterest
 *          @fn getCheckCharge
 *          @fn getOverDraftPenalty
 *          @fn setTelephoneNumber
 *          @fn setCustomerNumber
 * */
class Customer {
protected:
    /// declaring data members;
    std::string name;
    std::string address;
    int age;
    unsigned long telephone_number;
    unsigned long customer_number;

public:

    /// declaring member functions.
    void setName(std::string &);

    void setAddress(std::string &);

    void setAge(int &);

    std::string getName();

    std::string getAddress();

    int getAge();

    virtual std::string getAccountType()=0;
    virtual double getSavingsInterest()=0;
    virtual double getCheckingInterest()=0;
    virtual double getCheckCharge()=0;
    virtual double getOverDraftPenalty()=0;

    void setTelephoneNumber(unsigned long &);

    void setCustomerNumber(unsigned long &);

};

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Senior which inherits @class Customer which contains variables, methods.
 *          @var const double SAVINGS_INTEREST
 *          @var const double CHECKING_INTEREST
 *          @var const double CHECK_CHARGE
 *          @var const double OVERDRAFT_PENALTY
 *          @fn getAccountType
 *          @fn getSavingsInterest
 *          @fn getCheckingInterest
 *          @fn getCheckCharge
 *          @fn getOverDraftPenalty
 * */
class Senior : public Customer {
public:
    /// declaring data members;
    const double SAVINGS_INTEREST = 0.04;		// annual rate
    const double CHECKING_INTEREST = 0.01;      // annual rate. Yes! this is interest rate for the checking account.
    const double CHECK_CHARGE = 0.01;           // cents for withdrawal
    const double OVERDRAFT_PENALTY = 25.0;      // dollar

    /// declaring member functions.
    std::string getAccountType() override;
    double getSavingsInterest() override;
    double getCheckingInterest() override;
    double getCheckCharge() override;
    double getOverDraftPenalty() override;

};

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Adult which inherits @class Customer which contains variables, methods.
 *          @var const double SAVINGS_INTEREST
 *          @var const double CHECKING_INTEREST
 *          @var const double CHECK_CHARGE
 *          @var const double OVERDRAFT_PENALTY
 *          @fn getAccountType
 *          @fn getSavingsInterest
 *          @fn getCheckingInterest
 *          @fn getCheckCharge
 *          @fn getOverDraftPenalty
 * */
class Adult : public Customer {
public:
    /// declaring data members;
    const double SAVINGS_INTEREST = 0.03;		// annual rate
    const double CHECKING_INTEREST = 0.01;       // annual rate. Yes! this is interest rate for the checking account.
    const double CHECK_CHARGE = 0.03;            // cents for withdrawal
    const double OVERDRAFT_PENALTY = 25.0;       // dollar

    /// declaring member functions.
    std::string getAccountType() override;
    double getSavingsInterest() override;
    double getCheckingInterest() override;
    double getCheckCharge() override;
    double getOverDraftPenalty() override;
};

/**
 * <br><br> Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class Student which inherits @class Customer which contains variables, methods.
 *          @var const double SAVINGS_INTEREST
 *          @var const double CHECKING_INTEREST
 *          @var const double CHECK_CHARGE
 *          @var const double OVERDRAFT_PENALTY
 *          @fn getAccountType
 *          @fn getSavingsInterest
 *          @fn getCheckingInterest
 *          @fn getCheckCharge
 *          @fn getOverDraftPenalty
 * */
class Student : public Customer {
public:
    /// declaring data members;
    const double SAVINGS_INTEREST = 0.04; 		// annual rate
    const double CHECKING_INTEREST = 0.01;		// annual rate. Yes! this is interest rate for the checking account.
    const double CHECK_CHARGE = 0.02; 			// cents for withdrawal
    const double OVERDRAFT_PENALTY = 25.0; 	// dollar

    /// declaring member functions.
    std::string getAccountType() override;
    double getSavingsInterest() override;
    double getCheckingInterest() override;
    double getCheckCharge() override;
    double getOverDraftPenalty() override;
};
