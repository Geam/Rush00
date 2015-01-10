#include<ncurses.h>
#include<iostream>
#include<unistd.h>

int main()
{
	initscr();  // Starts curses (initializes the data structures, starts //   with blank "curses screen", shows it.)
	//
	start_color(); // Starts the color part of curses (initializes stuff, etc... .)

	// Colors to draw need to be "declared". This "declares" that color_pair #1
	// is blue letters on a black background, and #2 is red on black
	init_pair(1,COLOR_BLUE, COLOR_BLACK);
	init_pair(2,COLOR_RED, COLOR_YELLOW);


	raw();      // Lets you read chars as they are typed (no need to wait for <ENTER>)
	// Disables interrupts such as ^C, ^S
	//   [cbreak() is like raw(), but ^C stops the program]

	nodelay(stdscr,true);  // Don't even wait for one char -- getch returns ERR if
	//    they didn't type anything yet

	noecho();   // Don't echo characters as they are typed

	curs_set(0); // 0=don't show cursor

	nonl();     // [no newline] Without this, ENTER key generates ^M\n
	// With nonl(), ENTER is just ^M (13)
	// The curses value KEY_ENTER is for "cooked" (not raw) mode.

	keypad(stdscr,true); // Read arrow keys (enables the "keypad" where they live)

	int ypos=LINES/2,  // LINES and COLS are globals maintained by curses for
		xpos=COLS/2;   // the screen size.
	int ymove=0, xmove=0; // velocity

	mvaddch(ypos,xpos,'O'|COLOR_PAIR(1)); // draw the ball
	// binary OR char with color pair to get color

	mvaddstr(0,20,"Curses Demo ball game"); // y,x coords. Use instead of cout

	refresh(); // ncurses won't show changes until you call this.

	// Box around title, to show off special chars (%man curs_addch):
	// They don't work quite right for me (the screen gets confused about how wide boxes are)
	move(0,19); addch(ACS_VLINE | COLOR_PAIR(2));
	move(1,19); addch(ACS_LLCORNER | COLOR_PAIR(2)); // mvaddch(...) is a shortcut
	mvaddch(1,41, ACS_LRCORNER|COLOR_PAIR(2));
	mvaddch(0,41,ACS_VLINE|COLOR_PAIR(2));
	for(int i=40;i>19;i--) { mvaddch(1,i,'-'|COLOR_PAIR(2)); }
	refresh();


	int ch; // curses uses int values, that won't fit in a char, for some
	// special events (see below.) You can read with a char if you don't care.

	ch=getch(); // curses read -- processes & returns those odd characters

	while(ch!='q' && ch!='Q')
	{
		if(KEY_RIGHT==ch) // curses constant generated by the right arrow
		{ if(xmove<2) xmove++; }
		if(KEY_LEFT==ch) { if(xmove>-2) xmove--; }
		if(KEY_UP==ch)   { if(ymove>-2) ymove--; }
		if(KEY_DOWN==ch) { if(ymove<2) ymove++; }

		if(KEY_RESIZE==ch) // resizing screen "types" this character
		{ if(ypos>=LINES) ypos=LINES-1;
			if(xpos>=COLS) ypos=COLS-1; }

			if(3==ch) // ^C is just a normal character
			{ xmove=ymove=0; }

			// Not part of ncurses. In unistd.h
			// Waits for that many microseconds:
			usleep(50);

			mvaddch(ypos,xpos,' '); // erase old ball
			xpos+=xmove; if(xpos>=COLS) { xpos=COLS-1; xmove*=-1; }
			if(xpos<0)     { xpos=0; xmove*=-1; }
			ypos+=ymove; if(ypos>=LINES) { ypos=LINES-1; ymove*=-1; }
			if(ypos<0)     { ypos=0; ymove*=-1; }
			mvaddch(ypos,xpos,'O'|COLOR_PAIR(1));
			refresh();

			ch=getch(); // ncurses function for reading
	}

	endwin();  // ends curses (resets screen to the way it was before
	//   the program ran. resets cursor type, ... .)
	return 0;
}
