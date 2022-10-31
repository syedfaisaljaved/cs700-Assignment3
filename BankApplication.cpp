
#include "BankApplication.h"
#include <iostream>
#include "bank.h"

using namespace std;

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