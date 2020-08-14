//cs2024 
//Assignment 9 
//Xinci Liu
//xl597
//11/05/2019
//using c++11

#include <iostream>
#include <vector>

#include "BankAccountH.h"

class Bank 
{
 public:
  void newAccount();
  void listAccounts();

  void cleanup();
 private:
  // The only member variable is a vector of BankAccount pointers
  std::vector<BankAccount *> mAccounts;  
};
