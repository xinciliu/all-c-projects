//cs2024 
//Assignment 9 
//Xinci Liu
//xl597
//11/05/2019
//using c++11

#include <iostream>

class BankAccount {
 public:
  BankAccount();

  // Modified constructor that takes three arguments as per the assignment 
  BankAccount(int acctNum, std::string name, int initialBalance);

  int getBalance();
  void setBalance(int newBalance);
  int getAccountNumber();
  std::string getName();
  bool withdrawal(int amount);
  void deposit(int amount);

 private:
  int mBalance;
  int mAccountNumber;  // New member variable to store the account number
  std::string mName;   // New member variable to store the account holder's name
};
