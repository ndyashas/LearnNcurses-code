/* pager functionality by Joseph Spainhour  spainhou@bellsouth.net */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char *argv[])
{
	char ch, prev;
	int row, col;
	prev = EOF;
	FILE *fp;
	int x, y;

	if (argc != 2) {
		printf("Usage: %s <a C file>\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL) {
		perror("Cannot open input file\n");
		exit(1);
	}

	initscr();                                           /* Start curses mode */
	getmaxyx(stdscr, row, col);                          /* find boundaries of the screen */

	while ((ch = fgetc(fp)) != EOF) {                    /* Read till the end of the file */
		getyx(stdscr, y, x);                         /* Get the current curser position */

		if (y == (row-1)) {                          /* We are at the of the screen */
			printw("<-Press any Key->");         /* Tell the user to press any key */
			getch();
			clear();                             /* Clear the screen */
			move(0, 0);                          /* Start from the beginning of the screen */
		}

		if (prev == '/' && ch == '*') {              /* if it is "/*" */
			attron(A_BOLD | A_BLINK);                      /* then switch on bold mode */
			getyx(stdscr, y, x);
			move(y, x-1);
			printw("%c%c", '/', ch);             /* Clear previous print and print now with bold */
		}

		else
			printw("%c", ch);
		refresh();

		if (prev == '*' && ch == '/')                /* At the end of a comment */
			attroff(A_BOLD | A_BLINK);                     /* Switch off bold */

		prev = ch;
			
	}

	endwin();                                            /* End of curses mode */
	fclose(fp);
	
	return(0);
}
