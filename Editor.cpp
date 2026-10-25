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

// TODO add input handler
