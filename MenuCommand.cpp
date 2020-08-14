//cs2024 
//Assignment 9 
//Xinci Liu
//xl597
//11/05/2019
//using c++11

#include <iostream>

#include "MenuCommandH.h"

//
// The MenuCommand constructor is simple... it just needs to pass the commandChar
// and title parameters down to the MenuItem constructor (using constructor delegation)
MenuCommand::MenuCommand(char commandChar,std::string title,std::function<bool()> fn) : MenuItem(commandChar,title)
{mCommandCharacter=commandChar;
mTitle=title;
mfn=fn;
};

//
// Select is called when the user actually enters the command character
// for this MenuCommand 
//
bool MenuCommand::select()
{
  // If the title of this command is "Back" or "Quit" return FALSE
  // to signal that we should back out of whatever menu is presenting
  // this command.    This is a hack;  we'll have a better solution
  // for this in A9
  //if (mTitle == "Back" || mTitle == "Quit")
    //return false;
  //check whether mfn is NULL
  if (mfn!=NULL) {return mfn();};
  // We're not really implementing functionality now, just echo the
  // the name of the command.    We'll show you how to add functionality
  // to be executed when this command is selected in A9
  std::cout << "You selected: " << mTitle << "!!!" << std::endl;

  // We return "true" to signal to whatever menu is presenting us that 
  // they should continue to present the menu and allow the user to make
  // another choice
  return true;
}

void MenuCommand::display()
{
  std::cout << mCommandCharacter << "> " << mTitle << std::endl;
}
