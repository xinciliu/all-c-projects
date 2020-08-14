//use the source code from A9 solution
//cs 2024
//c++ programming
//Assignment 11
//xl597
//Xinci Liu

#include <iostream>
#include <fstream>
#include "MenuItemH.h"
#include "MenuH.h"
#include "MenuCommandH.h"
#include "BankH.h"
#include "BankAccountH.h"

typedef std::map<int,BankAccount *>::value_type IDRecord;
typedef std::map<int,BankAccount *>::iterator   IDRecordIterator;

// These functions are from A5
bool doListAccounts(Bank &b)
{
  b.listAccounts();
  return true;
}

bool doNewAccount(Bank &b)
{
  b.newAccount();
  return true;
}

bool doSelectAccount(Bank &b)
{
  b.selectAccount();
  return true;
}

bool ShowActiveAccount(Bank &b)
{ BankAccount *current=b.getCurrentAccount();
  std::cout<<"Selected Account Number:"<<(*current).getAccountNumber()<<std::endl;
  return true;
}

bool doBankInquiry(Bank &b)
{
  BankAccount *current=b.getCurrentAccount();
  std::cout<<"Balance is: "<<(*current).getBalance()<<std::endl;
  return true;
}

bool doBankDeposit(Bank &b)
{
  BankAccount *current=b.getCurrentAccount();
  int x;
  std::cout<<"How much do you want to deposit: ";
  std::cin>>x;
  (*current).deposit(x);
  return true;
}

bool doBankWithdraw(Bank &b)
{
  BankAccount *current = b.getCurrentAccount();
  int x;
  std::cout<<"How much do you want to withdraw: ";
  std::cin>>x;
  (*current).withdrawal(x);
  return true;
}

int main(int argc, char *argv[])
{
  // Declare a Bank instance
  Bank myBank;
  //initial myaccounts in Bank
  std::map<int,BankAccount *> myAccounts;
  //first open the file to read in exit bank account
  std::ifstream in("bankaccount.txt");
  if (in){
    while(!in.eof()){
      char buffer[80];
      in.getline(buffer,80);
      int accountnumber=atoi(buffer);
      in.getline(buffer,80);
      std::string accountname;
      accountname=buffer;
      in.getline(buffer,80);
      int accountamount=atoi(buffer);
      BankAccount *ba=new BankAccount(accountnumber,accountname,accountamount);
      if (ba !=NULL){
        if((*ba).getName()!=""){
        int accountnumber = (*ba).getAccountNumber();
        IDRecord rec(accountnumber,ba);
        myAccounts.insert(rec);}
      }
    }
  }
  //set the myaccounts (the accountlist) we generated before as mAccounts for myBank
  myBank.setmAccounts(myAccounts);

  auto newBankInquiry = [&myBank]()->bool { doBankInquiry(myBank); return true;  };
  auto newBankDeposit = [&myBank]()->bool { doBankDeposit(myBank); return true;  };
  auto newBankWithdrawal = [&myBank]()->bool { doBankWithdraw(myBank); return true;  };
  // Build our Menu structure
  MenuItem *accountMenuItems[] = {
    new MenuCommand('1',"Balance Inquiry",newBankInquiry),
    new MenuCommand('2',"Deposit",newBankDeposit),
    new MenuCommand('3',"Withdrawal",newBankWithdrawal), 
    new MenuCommand('b',"Back",[]()->bool { return false; })};

  // Build the accounts menu
  Menu accountMenu(accountMenuItems,4,'5',"Account");

  // store lambdas in auto variables just for convenience
  auto listAccountsLambda = [&myBank]()->bool { doListAccounts(myBank); return true;  };
  auto newAccountLambda = [&myBank]()->bool { doNewAccount(myBank); return true;  };
  auto newSelectLambda = [&myBank]()->bool { doSelectAccount(myBank); return true;  };
  auto newShowAccount=[&myBank]()->bool { ShowActiveAccount(myBank); return true;  };
  
  MenuItem *mainMenuItems[] = {
    new MenuCommand('1',"List Accounts",listAccountsLambda),
    new MenuCommand('2',"New Account",newAccountLambda), 
    new MenuCommand('3',"Select Account",newSelectLambda),
    new MenuCommand('4',"Show Active Account",newShowAccount),
    &accountMenu, 
    new MenuCommand('b',"Quit",[]()->bool { return false; })};

  // Build the main menu
  Menu mainMenu(mainMenuItems,6,'0',"Main");

  // Kick the whole thing off by calling select() on the main menu
  mainMenu.select();
  std::cout << "Done" << std::endl;

  //write all the BankAccount in myBank to the text file
  std::ofstream out("bankaccount.txt",std::ios::out);
  if(out.is_open()){
    std::map<int, BankAccount *> allAccounts=myBank.getmAccounts();
    for(IDRecordIterator p1=allAccounts.begin();p1!=allAccounts.end();p1++){
      int AccountNumber=p1 ->first;
      BankAccount *b=p1 ->second;
      if((*b).getName()!=""){
      out<<AccountNumber<<std::endl;
      out<<(*b).getName()<<std::endl;
      out<<(*b).getBalance()<<std::endl;
      }
    }
  }

}
