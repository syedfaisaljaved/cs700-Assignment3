#include <iostream>
#include <iomanip>
#include "BankApplication.h"
#include "Date.h"
using namespace std;

int main() {
//    BankApplication bankApplication;
//    bankApplication.start();

    cout << right << setw(10) << "DEP" << "\t" << "2020-12-24"
        << setw(5) << "$ " << left << "2000.0" << right << setw(5) << "$ " << left << "3000.0" << endl;


    cout << right << setw(10) << "INT CR" << "\t" << "2020-12-24"
         << setw(5) << "$ " << left << "200.0" << right << setw(5) << "$ " << left << "30200.0";
    return 0;
}
