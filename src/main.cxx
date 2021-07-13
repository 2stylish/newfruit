#include <ncurses.h>
#include <cstdbool>
#include <iostream>
#include <nlohmann/json.hpp>

// THINK: perhaps we could make it so projects started with etr have a name
#define cmvwprintw(screen, y, x, attrnum, format, ...) \
  attron(COLOR_PAIR(attrnum));                         \
  mvwprintw(screen, y, x, format, ##__VA_ARGS__);      \
  attroff(COLOR_PAIR(attrnum));
#define amvwprintw(screen, y, x, attrnum, format, ...) \
  attron(attrnum);                                     \
  mvwprintw(screen, y, x, format, ##__VA_ARGS__);      \
  attroff(attrnum);

enum colours {
  GREEN1 = 1,
  BAR,
  TEXTBAR,
};

int main(void) {
  int maxx, maxy;
  int xpos, ypos;
  int ch;

  initscr();                     // start curses
  getmaxyx(stdscr, maxy, maxx);  // get info of terminal

  if (has_colors() == TRUE) {  // check color support
    start_color();             // start color mode
    use_default_colors();      // get transparency if avail

    init_pair(2, COLOR_WHITE, -1);
    init_pair(GREEN1, 46, -1);
    init_pair(BAR, 60, -1);
    init_pair(TEXTBAR, -1, 60);
    //    wbkgd(stdscr, COLOR_PAIR(2));
  }

  noecho();     // no showing the chars
  cbreak();     // line buffering disabled
  curs_set(0);  // set cursor visibility O_O 8=D

  keypad(stdscr, TRUE);  // allow arrow keys and f's in main window

  wborder(stdscr, ' ', '|', '=', '=', '+', '+', '+',
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

  mvchgat(1, 1, -1, A_STANDOUT, BAR, NULL);

  cmvwprintw(stdscr, 1, 1, TEXTBAR, "lmfao");
  refresh();

  int i = 0;

  while ((ch = getch()) != 'q') {
    if (is_term_resized(maxy, maxx)) {
      i++;
      clear();
      wborder(stdscr, ' ', '|', '=', '=', '+', '+', '+',
              '+');  // add border to default screen
    }
    getmaxyx(stdscr, maxy,
             maxx);  // get info of terminal
                     // we do this after because otherwise the is_term_resized
                     // would give us true everytime
    getyx(stdscr, ypos, xpos);
    //    cmvwprintw(stdscr, 2, 2, GREEN1, "cursor pos y: %d x: %d", i, maxx);
    mvchgat(1, 1, -1, A_STANDOUT, BAR, NULL);
    // mvchgat(1, 1, -1, A_NORMAL, 1, NULL);
    mvwprintw(stdscr, 2, 1, "hehe");
    cmvwprintw(stdscr, 1, 1, TEXTBAR, "lmfao");
    refresh();
  }

  endwin();  // end curses

  std::cout << "row: " << maxx << "\ncolumn: " << maxy << std::endl;
}
