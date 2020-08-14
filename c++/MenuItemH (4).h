//use the source code from A9 solution
//cs 2024
//c++ programming
//Assignment 11
//xl597
//Xinci Liu

#ifndef _MENUITEM_H_
#define _MENUITEM_H_

#include <iostream>

class MenuItem {
 public:

  MenuItem(char commandChar,std::string title){
  mCommandCharacter = commandChar;
  mTitle = title;  
};

  // The  pure virtual functions below define our "interface" for being a "MenuItem"
  virtual bool select() = 0;
  virtual void display() = 0;

  // We should only need a public getter for command char
  // We could add one for title if ever needed
  char getCommandChar() { return mCommandCharacter; }

 protected:
  // These are inherited by all derived classes
  // Every MenuItem will have a command character and a title
  char mCommandCharacter;
  std::string mTitle;
};


#endif
