//use the source code from A9 solution
//cs 2024
//c++ programming
//Assignment 11
//xl597
//Xinci Liu

#include "BankH.h"
#include <map>
//
// Prompt the user for account number, customer name and initial balance,
// then dynamically allocate a new BankAccount instance and store in the vector
// Try to create map 
typedef std::map<int,BankAccount *>::value_type IDRecord;
typedef std::map<int,BankAccount *>::iterator   IDRecordIterator;
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
    //find out the account number
    int accountnumber = (*ba).getAccountNumber();
    // Store in map
    IDRecord rec(accountnumber,ba);
    mAccounts.insert(rec);

  }
}


//
// List out account information for every account in the vector
//
void Bank::listAccounts()
{
  std::cout << std::endl;
  std::cout << "ACCT# : NAME : BALANCE" << std::endl;
  int total=mAccounts.size();
  // Iterate through map and print out info for each BankAccount
  for(IDRecordIterator p1= mAccounts.begin();p1 != mAccounts.end();p1++)
  {
    int AccountNumber=p1 ->first;
    BankAccount *b=p1 ->second;
    std::cout<<AccountNumber<<" : "<<(*b).getName()<<" : "<<(*b).getBalance()<<std::endl;
  }

  std::cout << std::endl;
}
//add a select account function
void Bank::selectAccount(){
  int x;
  std::cout<<"Enter an account number to select:"<<std::endl;
  std::cin>>x;
  //sign the variable of current account
  IDRecordIterator p = mAccounts.find(x);
  myCurrentAccount=(*p).second;
};


