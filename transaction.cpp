/*****************************
 * @name Module Name: Banking System Application.
 * @author Faisal Javed
 * @date 16th October, 2022
 * Purpose: CS-700 Assignment 3
 * Student ID: 200491169
 ****************************/

#include "transaction.h"
#include <utility>
#include <iomanip>
#include <sstream>

using namespace std;

string Transaction::to_string() {
    std::ostringstream oss;
    cout << right << setw(10) << this->getTransactionType() << "\t" << this->getDate()
         << setw(5) << "$ " << left << this->getAmount() << right << setw(5) << "$ " << left << this->getBalance() << endl;
    return oss.str();
}

double Transaction::getBalance() {
    return this->balance;
}

double Transaction::getAmount() {
    return amount;
}

Date Transaction::getDate() {
    return this->date;
}

std::string Transaction::getTransactionType() {
    return this->transaction_type;
}

