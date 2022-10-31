/*****************************
 * @name Module Name: Banking System Application.
 * @author Faisal Javed
 * @date 16th October, 2022
 * Purpose: CS-700 Assignment 3
 * Student ID: 200491169
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams. <br>
#include "BankApplication.h" /// user-defined header @file BankApplication.h to propagate declarations to code file. <br>
#include "bank.h" /// user-defined header @file bank.h to propagate declarations to code file. <br>

/**
 * 'namespace' is used to organise the names of program entities. <br>
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std. <br>
 * */
using namespace std;

/**
 * Module Name: Banking System Application. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 16th October, 2022 <br>
 * Purpose: Method to execute banking system program. <br>
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - banking system program is executed.
 * */
void BankApplication::startBankApplication() {
    bool exitProgram = false;
    Bank bank;
    while (!exitProgram) {
        int selectedOption;
        cout << "Select:" << endl << "0: Add Account" << endl << "1: Make Deposit" << endl << "2: Make Withdrawal"
             << endl << "3: Check Account" << endl << "4: Exit" << endl << "> ";
        cin >> selectedOption;

        switch (selectedOption) {
            case 0: {
                bank.add_accounts();
                break;
            }
            case 1: {
                bank.make_deposit();
                break;
            }
            case 2: {
                bank.make_withdrawal();
                break;
            }
            case 3: {
                bank.get_account();
                break;
            }
            case 4: {
                exitProgram = true;
                break;
            }
            default:
                cout << "\n********************************************************\n";
                cout << "Wrong Selection. Try again from the given options." << endl;
                cout << "********************************************************\n\n";
                break;
        }
    }
}