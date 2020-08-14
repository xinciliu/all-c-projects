//cs2024 
//Assignment 9 
//Xinci Liu
//xl597
//11/05/2019
//using c++11

#include "BankH.h"

//
// Prompt the user for account number, customer name and initial balance,
// then dynamically allocate a new BankAccount instance and store in the vector
//
void Bank::newAccount() 
{
  std::string name;
  int accountNumber;
  int openingBalance;

  // Prompt the user
  std::cout << "NEW ACCOUNT:  " << std::endl;
  std::cout << "ENTER ACCOUNT NUMBER:  ";
  std::cin >> accountNumber;
  std::cout << "ENTER ACCOUNT NAME:    ";
  std::cin >> name;
  std::cout << "ENTER OPENING BALANCE: ";
  std::cin >> openingBalance;

  // Dynamically allocate new BankAccount
  BankAccount *ba = new BankAccount(accountNumber,name,openingBalance);

  // Make sure allocation succeeded
  if (ba != NULL) {
    // Store in vector
    mAccounts.push_back(ba);
  }
}


//
// List out account information for every account in the vector
//
void Bank::listAccounts()
{
  std::cout << std::endl;
  std::cout << "ACCT# : NAME : BALANCE" << std::endl;

  // Iterate through vector and print out info for each BankAccount
  for (BankAccount *account : mAccounts)
    {
      std::cout << account->getAccountNumber() << " : " << account->getName() << " : " << account->getBalance() << std::endl;
    }
  std::cout << std::endl;
}



//
// BONUS -- Cleanup pointers
//
void Bank::cleanup() 
{
  // Iterate through vector and delete each pointer found
  for (BankAccount *ba : mAccounts)
    {
      delete ba;
    }
}
