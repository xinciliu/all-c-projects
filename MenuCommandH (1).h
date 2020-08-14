//cs2024 
//Assignment 9 
//Xinci Liu
//xl597
//11/05/2019
//using c++11
//add a pointer to MenuCommand

#ifndef _MENU_COMMAND_H_
#define _MENU_COMMAND_H_

#include <iostream>
#include "MenuItemH.h"

class MenuCommand : public MenuItem 
{
 public:
  // A MenuCommand takes a command character and title
  MenuCommand(char commandChar,std::string title,std::function<bool()> fn);

  // Declare the methods we must implement if we derive from MenuItem
  bool select();
  void display();
  private:
  std::function<bool()> mfn;
};


#endif
