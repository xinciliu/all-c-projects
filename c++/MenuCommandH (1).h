//use the source code from A9 solution
//cs 2024
//c++ programming
//Assignment 11
//xl597
//Xinci Liu

#ifndef _MENU_COMMAND_H_
#define _MENU_COMMAND_H_

#include <iostream>
#include <functional>
#include "MenuItemH.h"

class MenuCommand : public MenuItem 
{
 public:
  // The constructor takes the standard commandChar and title, but also
  // takes a function pointer of the function to execute when the command is selected
  MenuCommand(char commandChar,std::string title,std::function<bool()> f);

  // Declaration of the two member function we must override
  bool select();
  void display();

 private:
  // The sole member variable is the function pointer of the function to call
  // when this item is selected
  std::function<bool()> functionPtr;
};


#endif
