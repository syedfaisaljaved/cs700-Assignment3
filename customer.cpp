/*****************************
 * @name Module Name: Banking System Application.
 * @author Faisal Javed
 * @date 16th October, 2022
 * Purpose: CS-700 Assignment 3
 * Student ID: 200491169
 ****************************/

#include "customer.h" /// user-defined header @file customer.h to propagate declarations to code file.
#include <iostream> /// library that controls reading from and writing to the standard streams.

/**
 * 'namespace' is used to organise the names of program entities. <br>
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std. <br>
 * */
using namespace std;

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to set the customer address. <br>
 *         @param [in] customerAddress
 *         @return [out] void
 *         @pre Pre Condition - a string is passed.
 *         @post Post Condition - sets the customer address.
 * */
void Customer::setAddress(string &customerAddress) {
    /// sets the value
    this->address = customerAddress;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to set the customer name. <br>
 *         @param [in] customerName
 *         @return [out] void
 *         @pre Pre Condition - a string is passed.
 *         @post Post Condition - sets the customer name.
 * */
void Customer::setName(string &customerName) {
    /// sets the value
    this->name = customerName;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to set the customer telephone number. <br>
 *         @param [in] customerTelephoneNumber
 *         @return [out] void
 *         @pre Pre Condition - an unsigned long is passed.
 *         @post Post Condition - sets the customer telephone number.
 * */
void Customer::setTelephoneNumber(unsigned long &customerTelephoneNumber) {
    /// sets the value
    this->telephone_number = customerTelephoneNumber;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to set the customer age. <br>
 *         @param [in] customerAge
 *         @return [out] void
 *         @pre Pre Condition - a integer is passed.
 *         @post Post Condition - sets the customer age.
 * */
void Customer::setAge(int &customerAge) {
    /// sets the value
    this->age = customerAge;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to set the customer number. <br>
 *         @param [in] customerNumber
 *         @return [out] void
 *         @pre Pre Condition - an unsigned long is passed.
 *         @post Post Condition - sets the customer number.
 * */
void Customer::setCustomerNumber(unsigned long &customerNumber) {
    /// sets the value
    this->customer_number = customerNumber;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer name. <br>
 *         @param [in] void
 *         @return [out] string
 *         @post Post Condition - returns the customer name.
 * */
std::string Customer::getName() {
    /// return the value
    return this->name;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer address. <br>
 *         @param [in] void
 *         @return [out] string
 *         @post Post Condition - returns the customer address.
 * */
std::string Customer::getAddress() {
    /// return the value
    return this->address;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer age. <br>
 *         @param [in] void
 *         @return [out] string
 *         @post Post Condition - returns the customer age.
 * */
int Customer::getAge() {
    /// return the value
    return this->age;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer account type. <br>
 *         @param [in] void
 *         @return [out] string
 *         @post Post Condition - returns the customer account type.
 * */
std::string Adult::getAccountType() {
    /// return the value
    return "Adult";
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer account type. <br>
 *         @param [in] void
 *         @return [out] string
 *         @post Post Condition - returns the customer account type.
 * */
std::string Senior::getAccountType() {
    /// return the value
    return "Senior";
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer account type. <br>
 *         @param [in] void
 *         @return [out] string
 *         @post Post Condition - returns the customer account type.
 * */
std::string Student::getAccountType() {
    /// return the value
    return "Student";
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer savings interest. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer savings interest.
 * */
double Senior::getSavingsInterest() {
    /// return the value
    return SAVINGS_INTEREST;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer checking interest. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer checking interest.
 * */
double Senior::getCheckingInterest() {
    /// return the value
    return CHECKING_INTEREST;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer check charge. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer check charge.
 * */
double Senior::getCheckCharge() {
    /// return the value
    return CHECK_CHARGE;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer overdraft penalty. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer overdraft penalty.
 * */
double Senior::getOverDraftPenalty() {
    /// return the value
    return OVERDRAFT_PENALTY;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer savings interest. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer savings interest.
 * */
double Adult::getSavingsInterest() {
    /// return the value
    return SAVINGS_INTEREST;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer checking interest. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer checking interest.
 * */
double Adult::getCheckingInterest() {
    /// return the value
    return CHECKING_INTEREST;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer check charge. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer check charge.
 * */
double Adult::getCheckCharge() {
    /// return the value
    return CHECK_CHARGE;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer overdraft penalty. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer overdraft penalty.
 * */
double Adult::getOverDraftPenalty() {
    /// return the value
    return OVERDRAFT_PENALTY;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer savings interest. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer savings interest.
 * */
double Student::getSavingsInterest() {
    /// return the value
    return SAVINGS_INTEREST;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer checking interest. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer checking interest.
 * */
double Student::getCheckingInterest() {
    /// return the value
    return CHECKING_INTEREST;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer check charge. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer check charge.
 * */
double Student::getCheckCharge() {
    /// return the value
    return CHECK_CHARGE;
}

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to get the customer overdraft penalty. <br>
 *         @param [in] void
 *         @return [out] double
 *         @post Post Condition - returns the customer overdraft penalty.
 * */
double Student::getOverDraftPenalty() {
    /// return the value
    return OVERDRAFT_PENALTY;
}
