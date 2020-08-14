//cs2024 
//Assignment 9 
//Xinci Liu
//xl597
//11/05/2019
//using c++11

#ifndef _MENUITEM_H_
#define _MENUITEM_H_

#include <iostream>

class MenuItem {
 public:
  // We define the constructor here because it's simple
  // and it saves us from needing a MenuItem.cpp file
  MenuItem(char commandChar,std::string title){
  mCommandCharacter = commandChar;
  mTitle = title;  
};

  // Pure virtual functions that define the "interface"
  // for a MenuItem
  virtual bool select() = 0;
  virtual void display() = 0;

  // We'll need to have a getter to retrieve the command char
  char getCommandChar() { return mCommandCharacter; }

 protected:
  char mCommandCharacter;
  std::string mTitle;
};


#endif
