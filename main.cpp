/*****************************
 * @name Module Name: Banking System Application.
 * @author Faisal Javed
 * @date 16th October, 2022
 * Purpose: CS-700 Assignment 3
 * Student ID: 200491169
 ****************************/

/**
 * @file arraySorting.h
 * @brief user-defined header file section1/arraySorting.h to propagate declarations to code file.
 * */
#include "BankApplication.h"

/*****************************
 * Module Names: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: main() Function serves as the starting point for program execution.
 *          It has no arguments and returns 0 if the program is executed successfully. <br>
 *          @param [in] void
 *          @return [out] int
 *          @post Post Condition - int is returned.
 ****************************/
int main() {
    /// program execution starts here.

    BankApplication bankApplication; /// creating object of class @c BankApplication
    bankApplication.startBankApplication(); /// calling @a startBankApplication to run the banking application.

    return 0; /// returns 0 if the program is executed successfully because main() has a return type of integer.

/// program terminates here.
}
