

#include <iostream>

#include "MenuItemH.h"
#include "MenuH.h"
#include "MenuCommandH.h"
#include "BankH.h"



int main(int argc, char *argv[])
{
  //set up bank
  Bank mybank;
  // Setup the submenu first
  MenuItem *accountMenuItems[] = {
    new MenuCommand('1',"Balance Inquiry",[&mybank]()->bool {std::cout<<"not implemented"<<std::endl;return true;}),
    new MenuCommand('2',"Deposit",[&mybank]()->bool {std::cout<<"not implemented"<<std::endl;return true;}),
    new MenuCommand('3',"Withdrawal",[&mybank]()->bool {std::cout<<"not implemented"<<std::endl;return true;}), 
    new MenuCommand('b',"Back",[&mybank]()->bool {return false;})
  };

  Menu accountMenu(accountMenuItems,4,'3',"Account");

  // Then set up the main menu
  MenuItem *mainMenuItems[] = {
    new MenuCommand('1',"List Accounts",[&mybank]()->bool {mybank.listAccounts();return true;}), 
    new MenuCommand('2',"New Account",[&mybank]()->bool {mybank.newAccount();return true;}), 
    &accountMenu, 
    new MenuCommand('b',"Quit",[&mybank]()->bool {return false;})
  };

  Menu mainMenu(mainMenuItems,4,'0',"Main");

\  bool keepGoing = mainMenu.select();

 

  std::cout << "Done" << std::endl;
}
