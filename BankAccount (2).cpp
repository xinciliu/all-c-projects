//cs2024 
//Assignment 9 
//Xinci Liu
//xl597
//11/05/2019
//using c++11

#include "BankAccountH.h"

BankAccount::BankAccount()
{
  mBalance = 0;
}

//
// New constructor to set all three member variables
//
BankAccount::BankAccount(int acctNum, std::string name, int initialBalance)
{
  mBalance = 0;
  if (initialBalance > 0)
    mBalance = initialBalance;

  mAccountNumber = acctNum;
  mName = name;
}

//
// New getter to retrieve the account holder's name
//
std::string BankAccount::getName() 
{
  return mName;
}

//
// New getter to retrieve the account number
//
int BankAccount::getAccountNumber()
{
  return mAccountNumber;
}

int BankAccount::getBalance() 
{
  return mBalance;
}

void BankAccount::setBalance(int newBalance) 
{
  mBalance = 0;

  if (newBalance > 0) 
    mBalance = newBalance;
}

bool BankAccount::withdrawal(int amount) 
{
  if ((amount <= 0) || (amount > mBalance)) {
    return false;
  }

    mBalance -= amount;
    return true;
}

void BankAccount::deposit(int amount) 
{
  if (amount > 0) {
    mBalance += amount;
  }
}


