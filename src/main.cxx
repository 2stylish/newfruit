#include <ncurses.h>
#include <cstdbool>
#include <iostream>

// THINK: perhaps we could make it so projects started with etr have a name

int main(void) {
  int row, column;
  int ch;

  initscr();             // start curses
                         //  if (has_colors() == TRUE) {  // check color support
                         //    start_color();             // start color mode
                         //  }
  keypad(stdscr, TRUE);  // allow arrow keys and f's in main window

  wborder(stdscr, ' ', ' ', '=', '=', '+', '+', '+',
          '+');  // add border to default screen
  /* The parameters taken are
   * 1. win: the window on which to operate
   * 2. ls: character to be used for the left side of the window
   * 3. rs: character to be used for the right side of the window
   * 4. ts: character to be used for the top side of the window
   * 5. bs: character to be used for the bottom side of the window
   * 6. tl: character to be used for the top left corner of the window
   * 7. tr: character to be used for the top right corner of the window
   * 8. bl: character to be used for the bottom left corner of the window
   * 9. br: character to be used for the bottom right corner of the window
   */
  getmaxyx(stdscr, column, row);
  mvwprintw(stdscr, 1, 1, "lmfao");
  refresh();
  getch();

  std::cout << row << column << std::endl;

  endwin();  // end curses
}

