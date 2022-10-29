//
// Created by Faisal Javed on 22/10/22.
//

#include "BankApplication.h"
#include <iostream>
#include <algorithm>
#include "customer.h"
#include "account.h"
#include "bank.h"

using namespace std;

void BankApplication::start() {
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
                break;
        }
    }
}