#ifndef EDITOR_H
#define EDITOR_H

#include <ncurses.h>
#include "Buffer.h"

class Editor
{
private:
  int x, y;
  char mode;
  Buffer* buff;
  string status, filename;

  //for those who are old
  string tos(int);

  //cursor movement
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

  void deleteLine();
  void deleteLine(int);

  void saveFile();

public:
  Editor(); // normal constructor
  Editor(string); //constructor accepting file name

  char getMode() {return mode;} 

  void handleInput(int); //handles keyboard input 
  void printBuff();
  void printStatusLine(); //prints status line like nvim
  void updateStatus(); //updates the status line . text
};

#endif
