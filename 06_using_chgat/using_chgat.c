#include <ncurses.h>

int main(int argc, char *argv[])
{
	int CUSTOM_COLOR_1 = 1;

	initscr();       /* Start curses mode */
	start_color();   /* Start color functionality */

	init_pair(CUSTOM_COLOR_1, COLOR_CYAN, COLOR_BLACK);
	printw("A Big String which I didn't care to type fully ");
	mvchgat(0, 0, -1, A_BLINK, CUSTOM_COLOR_1, NULL);

	/*
	 * First two parametrs specify the position at which to start
	 * Third parameter number of character to update. -1 means till
	 * end of line
	 * Fourth parameter is the normal attribute you wanted to give
	 * to the charecter
	 * Fifth is the color index. It is the index given during init_painr()
	 * use 0 id you didn't want color
	 * Sixth one is always NULL
	 */

	refresh();
	getch();
	endwin();        /* End curses mode */
	
	return(0);
}	
