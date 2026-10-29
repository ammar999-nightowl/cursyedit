#include "Editor.h"

#include <iostream>
#include <fstream>
#include <sstream> //if you are not on c++ 11 or new  versions


// file system logic now !!


Editor::Editor()
{
  x=0;y=0;mode='n';
  status = "normal mode";
  filename = "null_file";

  /* initialize buffer and append Line to prevent seg fault  . 
   */

  buff = new Buffer();
  buff->appendLine("");


}

Editor::Editor(string fn)
{
  x=0;y=0;mode='n';
  status = "normal mode";
  filename = fn;

  buff = new Buffer();
  ifstream infile(fn.c_str());
  if(infile.is_open())
  {
    while(!infile.eof())
    {
      string temp;
      getline(infile, temp);
      buff->appendLine(temp);

    }
  }
  else
  {
    cerr << "cannot open file :'" << fn << "'\n";
    buff->appendLine("");
  }
}

void Editor::updateStatus()
{
  switch(mode)
  {
    case 'n':
      //normal ahh mode
      status = "normal mode";
      break;
    case 'i':
      //insert shit mode
      status = "insert mode";
      break;
    case 'x':
      //exit the dih .
      status = "Exiting...";
      break;
  }
  status += "\tCOL: " + tos(x) + "\tRAW: " + tos(y);
}

string Editor::tos(int i)
{
  stringstream ss;
  ss << i;
  return ss.str();

}

void Editor::handleInput(int c)
{
  switch(c)
  {
    case KEY_LEFT:
      moveLeft();
      return;
    case KEY_RIGHT:
      moveRight();
      return;
    case KEY_UP:
      moveUp();
      return;
    case KEY_DOWN:
      moveDown();
      return;
  }
  switch(mode)
  {
    case 'n':
      switch(c)
      {
        case 'x':
          mode = 'x'; //exit mode
          break;
        case 'i':
          mode = 'i'; //enter mode or input mode
          break;
        case 's':
          mode = 's'; //file saving mode
          break;
      }
      break;
    case 'i':
      switch(c)
      {
        case 27:
          //alt/esc key btw
          mode = 'n';
          break;
        case 127:
        case KEY_BACKSPACE:
          //backspace key btw
          if (x == 0 && y > 0)
          {
            x = buff->lines[y-1].length();
            //bring the line down 
            buff->lines[y-1] += buff->lines[y];
            //deletes the current line
            deleteLine();
            moveUp();
          }
          else
          {
            //remove a character
            buff->lines[y].erase(--x, 1);

          }
          break;
        case KEY_DC:
          //delete key btw
          if(x == buff->lines[y].length() && y != buff->lines.size() - 1)
          {
            //bring the line down
            buff->lines[y] += buff->lines[y+1];
            //delete the line
            deleteLine(y+1);
          }
          else
          {
            buff->lines[y].erase(x, 1);

          }
          break;
        case KEY_ENTER:
        case 10:
          //TODO enter key logic
      }
  }
}

