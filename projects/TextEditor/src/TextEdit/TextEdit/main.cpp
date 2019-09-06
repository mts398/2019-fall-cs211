#define PDC_DLL_BUILD 1
#include "curses.h"
#include <string>
using namespace std;

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

	//===========MAIN_WINDOW BORDERS=========
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
	//========================================

	//tells curses to draw
	refresh();

	//===========draw small box===========

	WINDOW* win = newwin(3, num_cols-2, 0, 1); //newwin(row, columns, y position, x position)

	box(win, '|', '-'); //small box window
	mvwaddstr(win, 1, 1, "File   Edit   Options   Tools   Help");

	touchwin(win);
	wrefresh(win);
	//=============end of small box===========

	//==========TEXT BOX========

	//WINDOW* textWin = nullptr;
	//double textRow = num_rows/2;
	//double textCol = num_cols/2;

	//for (int i = 0; i < textCol; i++)
	//{
	//	//top border
	//	mvaddch(0, i, ACS_DIAMOND);

	//	//bottom border
	//	mvaddch(textRow - 1, i, ACS_DIAMOND);
	//}
	//for (int i = 0; i < textRow; i++)
	//{
	//	//left column
	//	mvaddch(i, 0, ACS_DIAMOND);

	//	//right column
	//	mvaddch(i, textCol - 1, ACS_DIAMOND);
	//}
	//
	//char msg[] = "Enter a string: ";
	//char str[80];

	//getmaxyx(textWin, textRow, textCol);
	//mvprintw(textRow / 2, (textRow - strlen(msg)) / 2, "%s", msg);


	//==================================

	char result = getch();

	//revert  back to normal console mode - turn things off
	nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	mvaddstr(0, 0, "Press any key to continue...");
	result = getch();

	endwin();

	return 0;
}