#include <ncurses.h>
#include <cstdbool>
#include <iostream>

// THINK: perhaps we could make it so projects started with etr have a name

enum colours {
  GREEN1 = 1,
};

int main(void) {
  int maxx, maxy;
  int xpos, ypos;
  int ch;

  initscr();                     // start curses
  getmaxyx(stdscr, maxy, maxx);  // get info of terminal

  if (has_colors() == TRUE) {  // check color support
    start_color();             // start color mode
    init_pair(GREEN1, 46, COLOR_BLACK);
  }

  noecho();     // no showing the chars
  cbreak();     // line buffering disabled
  curs_set(1);  // set cursor visibility O_O 8=D

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

  attron(A_STANDOUT);
  //  attron(A_REVERSE);
  mvwprintw(stdscr, 1, 1, "lmfao");
  mvchgat(1, 1, -1, A_STANDOUT, GREEN1, NULL);
  refresh();
  //  attroff(A_REVERSE);
  attroff(A_STANDOUT);

  while ((ch = getch()) != 'q') {
    getyx(stdscr, ypos, xpos);
    attron(COLOR_PAIR(GREEN1));
    mvwprintw(stdscr, 0, 0, "cursor pos y: %d x: %d", maxy, maxx);
    // mvchgat(1, 1, -1, A_NORMAL, 1, NULL);
    attroff(COLOR_PAIR(GREEN1));
    refresh();
  }

  endwin();  // end curses

  std::cout << "row: " << xpos << "\ncolumn: " << ypos << std::endl;
}

