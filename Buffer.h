#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <vector>

using namespace std;

class Buffer
{
public:
  Buffer();

  vector<string> lines;

  /*some helper funcs*/
  void insertLine(string, int);
  void appendLine(string);
  void removeLine(int);

  /* substitute all tabs in string for 4 spaces 
  * so tabs wont screw everything up*/
  string remTabs(string);

};

#endif
