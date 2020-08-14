//use the source code from A9 solution
//cs 2024
//c++ programming
//Assignment 11
//xl597
//Xinci Liu

#include <iostream>
#include <vector>
#include <map>

#include "BankAccountH.h"

class Bank 
{
 public:
  Bank(){};
  void newAccount();
  void listAccounts();
  void selectAccount();
  BankAccount *getCurrentAccount(){return myCurrentAccount;};
  void setmAccounts(std::map<int, BankAccount *> myaccounts){mAccounts=myaccounts;};
  std::map<int, BankAccount *> getmAccounts(){return mAccounts;};

 private:
  // The only member variable is a vector of BankAccount pointers
  std::map<int, BankAccount *> mAccounts;  
  BankAccount *myCurrentAccount;
};
