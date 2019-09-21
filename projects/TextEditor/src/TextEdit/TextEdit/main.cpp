#define PDC_DLL_BUILD 1
#include "curses.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
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

	WINDOW* win = newwin(1, 1, 1, 1);
	touchwin(win);
	wrefresh(win);

	//menu bar

	WINDOW* menuWin = newwin(3, num_cols-2, 0, 1); //newwin(lines, nlines, columns, ncols)
	box(menuWin, ACS_VLINE, ACS_HLINE); //small box window
	mvwaddstr(menuWin, 1, 1, "File   Edit   Options   Tools   Help");

	touchwin(menuWin);
	wrefresh(menuWin);


	//mapping out the status bar
	WINDOW* statusWin = newwin(3, num_cols-2, 26, 1); //lines, width, vertical, horizontal
	box(statusWin, ACS_VLINE, ACS_HLINE); //small box window
	mvwaddstr(statusWin, 1, 1, "File type: .txt	|	Lines:	0	|	TextEditor");

	touchwin(statusWin);
	wrefresh(statusWin);

	//text window
	WINDOW* textWin = newwin(num_rows - 6, num_cols-6, 3, 5);
	box(textWin, ACS_VLINE, ACS_HLINE);
	

	//mapping out the location of the line column counter
	WINDOW* lineWin = newwin(num_rows-8, 4, 3, 2); //lines, width, vertical, horizontal
	mvwaddstr(lineWin, 1, 1, " 1\n  2\n  3\n  4\n  5\n  6\n  7\n  8\n  9\n 10\n 11\n 12\n 13\n 14\n 15\n 16");

	touchwin(lineWin);
	wrefresh(lineWin);

	//reading from hello.txt
	string line;
	ifstream myfile("hello.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			mvwaddstr(textWin, 3, 5, line.c_str());
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	touchwin(textWin);
	wrefresh(textWin);
	//mapping out the menu bar
	//WINDOW* menuWin = newwin(3, num_cols-2, 0, 1); //newwin(lines, nlines, columns, ncols)

	//box(menuWin, ACS_VLINE, ACS_HLINE); //small box window
	//mvwaddstr(menuWin, 1, 1, "File   Edit   Options   Tools   Help");

	//touchwin(menuWin);
	//wrefresh(menuWin);
	//
	////mapping out the status bar
	//WINDOW* statusWin = newwin(3, num_cols-2, 26, 1); //lines, width, vertical, horizontal
	//box(statusWin, ACS_VLINE, ACS_HLINE); //small box window
	//mvwaddstr(statusWin, 1, 1, "File type: .txt	|	Lines:	0	|	Text Editor Milestone 1: A Location Map, WOOHOO!!!!");

	//touchwin(statusWin);
	//wrefresh(statusWin);

	////mapping out the location of the line column counter
	//WINDOW* lineWin = newwin(num_rows-8, 4, 3, 2); //lines, width, vertical, horizontal
	//box(lineWin, ' ', ' '); //small box window
	//mvwaddstr(lineWin, 1, 1, " 1\n  2\n  3\n  4\n  5\n  6\n  7\n  8\n  9\n 10\n 11\n 12\n 13\n 14\n 15\n 16");

	//touchwin(lineWin);
	//wrefresh(lineWin);

	//mvaddstr(4, 6, "  My first line of text.");

	char result = getch();

	//revert  back to normal console mode - turn things off
	nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	mvaddstr(0, 0, "Press any key to continue...");
	result = getch();

	endwin();

	return 0;
}