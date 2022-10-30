//
// Created by Faisal Javed on 17/10/22.
//

#pragma once

#include <iostream>

class Customer {
protected:
    std::string name;
    std::string address;
    int age;
    unsigned long telephone_number;
    unsigned long customer_number;

public:

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

class Senior : public Customer {
public:
    const double SAVINGS_INTEREST = 0.04;		// annual rate
    const double CHECKING_INTEREST = 0.01;      // annual rate. Yes! this is interest rate for the checking account.
    const double CHECK_CHARGE = 0.01;           // cents for withdrawal
    const double OVERDRAFT_PENALTY = 25.0;      // dollar

    std::string getAccountType() override;
    double getSavingsInterest() override;
    double getCheckingInterest() override;
    double getCheckCharge() override;
    double getOverDraftPenalty() override;

};

class Adult : public Customer {
public:
    const double SAVINGS_INTEREST = 0.03;		// annual rate
    const double CHECKING_INTEREST = 0.01;       // annual rate. Yes! this is interest rate for the checking account.
    const double CHECK_CHARGE = 0.03;            // cents for withdrawal
    const double OVERDRAFT_PENALTY = 25.0;       // dollar

    std::string getAccountType() override;
    double getSavingsInterest() override;
    double getCheckingInterest() override;
    double getCheckCharge() override;
    double getOverDraftPenalty() override;
};

class Student : public Customer {
public:
    const double SAVINGS_INTEREST = 0.04; 		// annual rate
    const double CHECKING_INTEREST = 0.01;		// annual rate. Yes! this is interest rate for the checking account.
    const double CHECK_CHARGE = 0.02; 			// cents for withdrawal
    const double OVERDRAFT_PENALTY = 25.0; 	// dollar

    std::string getAccountType() override;
    double getSavingsInterest() override;
    double getCheckingInterest() override;
    double getCheckCharge() override;
    double getOverDraftPenalty() override;
};
