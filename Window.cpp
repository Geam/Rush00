/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:37:14 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/01/10 17:37:57 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ncurses.h>
#include "Window.hpp"

Window::Window(int const x, int const y) : _clock(0), _x(x), _y(y)
{
	std::cout << "[CONSTRUCT] Window "
		<< this->getX() << " " << this->getY() << std::endl;
}

Window::Window(Window const & src) : _clock(0)
{
	*this = src;
	std::cout << "[CONSTRUCT] Window"
		<< this->getX() << " " << this->getY() << std::endl;
}

Window::~Window( void )
{
	std::cout << "[DESTRUCTOR] Window" << std::endl;
	endwin();
}

Window &			Window::operator=(Window const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return *this;
}

// enables to save the terminal current color and restore them later (using the boolean save)
void    switchDefaultColors(bool save) {
	static short black[3];
	static short red[3];
	static short green[3];
	static short yellow[3];
	static short blue[3];
	static short magenta[3];
	static short cyan[3];
	static short white[3];

	if (save) {
		color_content(COLOR_BLACK, &black[0], &black[1], &black[2]);
		color_content(COLOR_RED, &red[0], &red[1], &red[2]);
		color_content(COLOR_GREEN, &green[0], &green[1], &green[2]);
		color_content(COLOR_YELLOW, &yellow[0], &yellow[1], &yellow[2]);
		color_content(COLOR_BLUE, &blue[0], &blue[1], &blue[2]);
		color_content(COLOR_MAGENTA, &magenta[0], &magenta[1], &magenta[2]);
		color_content(COLOR_CYAN, &cyan[0], &cyan[1], &cyan[2]);
		color_content(COLOR_WHITE, &white[0], &white[1], &white[2]);
	}
	else {
		init_color(COLOR_BLACK, black[0], black[1], black[2]);
		init_color(COLOR_RED, red[0], red[1], red[2]);
		init_color(COLOR_GREEN, green[0], green[1], green[2]);
		init_color(COLOR_YELLOW, yellow[0], yellow[1], yellow[2]);
		init_color(COLOR_BLUE, blue[0], blue[1], blue[2]);
		init_color(COLOR_MAGENTA, magenta[0], magenta[1], magenta[2]);
		init_color(COLOR_CYAN, cyan[0], cyan[1], cyan[2]);
		init_color(COLOR_WHITE, white[0], white[1], white[2]);
	}
}

void    initColors() {
	// init default color - TODO: later create different games color profiles
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_RED, 700, 0, 0);
	init_color(COLOR_GREEN, 0, 0, 700);
	init_color(COLOR_YELLOW, 700, 700, 0);
	init_color(COLOR_BLUE, 0, 0, 700);
	init_color(COLOR_MAGENTA, 700, 0, 700);
	init_color(COLOR_CYAN, 0, 400, 700);
	init_color(COLOR_WHITE, 700, 700, 700);
}

void    setColors(void) {
	// color support is required for this game
	if (!can_change_color()) {
		printw("ERROR: Your terminal can't change colors");
		getch();
		endwin(); // care, we are exiting the program. Is everything restored ?
		exit(1);
	}
	if (has_colors() == FALSE) {
		printw("ERROR: Your terminal does not support color\n");
		getch();
		endwin();
		exit(1);
	}

	start_color();
	switchDefaultColors(true);
	initColors();

	// init pairs : Here define our color pairs.
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_MAGENTA);

}

void				Window::initWindow(void)
{
	initscr();
	setColors();
	cbreak(); // or raw() of we want to catch all inputs including ctr-c, etc.
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	refresh();
}

void				Window::refreshWindow(void)
{
	refresh();
}

int					Window::getX(void) const
{
	return this->_x;
}

int					Window::getY(void) const
{
	return this->_y;
}

Window::Window( void ) : _clock(0)
{
	std::cout << "[CONSTRUCT] Window" << std::endl;
}

