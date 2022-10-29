cmake_minimum_required(VERSION 3.23)
project(cs700_assignment3)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs700_assignment3 main.cpp bank.cpp bank.h Date.cpp Date.h customer.cpp customer.h transaction.cpp transaction.h account.cpp account.h BankApplication.cpp BankApplication.h)
