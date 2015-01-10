#include <ncurses.h>
#include <iostream>
#include "Screen.hpp"

Screen::Screen( void ) : _x(600), _y(400) {
	initscr();
	start_color();
	init_pair(1,COLOR_BLUE, COLOR_BLACK);
	init_pair(2,COLOR_RED, COLOR_BLACK);
	raw();      // Lets you read chars as they are typed (no need to wait for <ENTER>)
	noecho();
	curs_set(0); // 0=don't show cursor
	nonl();     // [no newline] Without this, ENTER key generates ^M\n
	keypad(stdscr,true); // Read arrow keys (enables the "keypad" where they live)
}

Screen::Screen(Screen const & src) : _x(src._x), _y(xrc._y)
{
	initscr();
	start_color();
	init_pair(1,COLOR_BLUE, COLOR_BLACK);
	init_pair(2,COLOR_RED, COLOR_BLACK);
	raw();      // Lets you read chars as they are typed (no need to wait for <ENTER>)
	noecho();
	curs_set(0); // 0=don't show cursor
	nonl();     // [no newline] Without this, ENTER key generates ^M\n
	keypad(stdscr,true); // Read arrow keys (enables the "keypad" where they live)
}

Screen::~Screen( void ) {
	endwin();
}

Screen &	Screen::operator=(Screen const & src){
	this->_x = src._x;
	this->_y = src._y;
	return *this;
}

void		Screen::display(AEntity const & src)
{
}

void		Screen::putElem(int const x, int const y, char const c, int color) {
	mvaddch(y, x, c | COLOR_PAIR(color));
}

