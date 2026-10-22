#include <ncurses.h>
#include <string>

using namespace std;

void curses_init()
{

  initscr(); //enables curses mode
  noecho(); //turns off echo in terminal
  cbreak(); // no need to press enter now
  keypad(stdscr, TRUE); //enables special keys 


}


int main(int argc, char* argv[])
{

  string fn = "";
  if (argc > 1) 
  {
    fn = argv[1];
  }

  curses_init();

  refresh();
  endwin();
  return 0;
}
