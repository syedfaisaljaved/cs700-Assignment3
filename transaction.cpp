//
// Created by Faisal Javed on 17/10/22.
//

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

