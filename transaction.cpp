/*****************************
 * @name Module Name: Banking System Application.
 * @author Faisal Javed
 * @date 16th October, 2022
 * Purpose: CS-700 Assignment 3
 * Student ID: 200491169
 ****************************/

#include <iomanip> /// library that controls reading from and writing to the standard streams. <br>
#include <sstream> /// library that allows performing insertion, extraction, and other operations for parsing inputs and converting strings to numbers, and vice-versa. <br>
#include "transaction.h" /// user-defined header @file transaction.h to propagate declarations to code file. <br>


/**
 * 'namespace' is used to organise the names of program entities. <br>
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std. <br>
 * */
using namespace std;

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the string in a formatted fashion. <br>
 *         @param [in] void
 *         @return [out] string
 *         @post Post Condition - return a string
 * */
string Transaction::to_string() {
     /// creating an object of @c ostringstream class to stream the string into different variables.
    std::ostringstream oss;
    /**
     * using @c left keyword to left-align the data. <br>
     * using @c right keyword to right-align the data. <br>
     * using @c setw to have a well-formatted output with spacing of the specified width. <br>
     * */
    cout << right << setw(10) << this->getTransactionType() << "\t" << this->getDate()
         << setw(5) << "$ " << left << this->getAmount() << right << setw(5) << "$ " << left << this->getBalance()
         << endl;
    /// return a string
    return oss.str();
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the balance. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns balance
 * */
double Transaction::getBalance() {
    /// return the value
    return this->balance;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the amount. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns amount
 * */
double Transaction::getAmount() {
    /// return the value
    return amount;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the date. <br>
 *         @param [in] void
 *         @return [out] Date
 *         @post Post Condition - returns date
 * */
Date Transaction::getDate() {
    /// return the value
    return this->date;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the transaction type. <br>
 *         @param [in] void
 *         @return [out] string
 *         @post Post Condition - returns transaction type
 * */
std::string Transaction::getTransactionType() {
    /// return the value
    return this->transaction_type;
}

