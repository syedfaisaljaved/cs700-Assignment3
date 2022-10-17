#include <iostream>
#include "bank.h"

class Customer {
private:
    std::string name;
    std::string address;
    int age;
    int telephone_number;
    int customer_number;
public:
    void setName(std::string);
    void setAddress(std::string);
    void setAge(int);
    void setTelephoneNumber();
    void setCustomerNumber();

};

class Senior : public Customer {
private:
    const int SAVINGS_INTEREST = 0;
    const int CHECK_INTEREST = 0;
    const int CHECK_CHARGE = 0;
    const int OVERDRAFT_PENALTY = 0;
};

class Adult : public Customer {
private:
    const int SAVINGS_INTEREST = 0;
    const int CHECK_INTEREST = 0;
    const int CHECK_CHARGE = 0;
    const int OVERDRAFT_PENALTY = 0;
};

class Student : public Customer {
private:
    const int SAVINGS_INTEREST = 0;
    const int CHECK_INTEREST = 0;
    const int CHECK_CHARGE = 0;
    const int OVERDRAFT_PENALTY = 0;
};

class Account {
private:
    Customer customer;
    float balance;
    int account_number;
    Transactions transactions[];
public:
    Account();
    void create_Account();
    int get_account_number();
    float get_balance();
    Customer get_customer();
    void to_string();
    void set_customer();
    void set_balance();
};

class Savings_Account : public Account {
public:
    void deposit();
    void withdraw();
    void add_interest();

};

class Checking_Account : public Account {
public:
    void deposit();
    void withdraw();
    void add_interest();
};


class Bank {
private:
    Account account[];
public:
    void add_accounts();
    void make_deposit();
    void make_withdrawal();
    Account get_account();
};