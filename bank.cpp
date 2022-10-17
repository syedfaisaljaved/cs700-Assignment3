#include "bank.h"

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

