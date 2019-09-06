#define PDC_DLL_BUILD 1
#include "curses.h"
#include <string>
using namespace std;

unsigned char border_char = 254;

int main(void)
{
	WINDOW* main_window = nullptr;
	//dimensions
	int num_rows = 0;
	int num_cols = 0;

	//initialize screen, begin curses mode
	main_window = initscr();

	//take up most of the screen
	int window_y = getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	int window_x = getmaxyx(main_window, num_rows, num_cols);

	//turn off key echo
	noecho();
	//nodelay(main_window, TRUE); //refreshes screen
	keypad(main_window, TRUE); //turns on keypad
	curs_set(0); //no blinking cursor

	//FUN STUFF HAPPENS HERE

	for (int i = 0; i < num_cols; i++)
	{
		//top border
		//mvaddch(0, i, ACS_DIAMOND);

		//bottom border
		mvaddch(num_rows - 1, i, ACS_DIAMOND);
	}
	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 0, ACS_DIAMOND);

		//right column
		mvaddch(i, num_cols - 1, ACS_DIAMOND);
	}

	//tells curses to draw
	refresh();

	//draw small box
	initscr();

<<<<<<< HEAD
	WINDOW* win = newwin(3, num_cols-2, 0, 1); //newwin(row, columns, y position, x position)

	box(win, '|', '-'); //small box window
	mvwaddstr(win, 1, 1, "File   Edit   Options   Tools   Help");

	touchwin(win);
	wrefresh(win);
	// end of small box
=======
	WINDOW* win = newwin(5, num_cols-10, 23, 6); //newwin(row, columns, y position, x position)

	box(win, '|', '-');
	touchwin(win);
	wrefresh(win);
>>>>>>> b4966fbeadebfe2fccecc8616d366d74d50f2900

	char result = getch();

	//revert  back to normal console mode - turn things off
	nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	mvaddstr(0, 0, "Press any key to continue...");
	result = getch();

	
	endwin();


}