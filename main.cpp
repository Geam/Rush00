#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include "Window.hpp"
#include "Interval.hpp"
#include "Fps.hpp"
#include "Position.hpp"
#include "DisplaySprite.hpp"

WINDOW *g_debug = NULL;

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
	init_color(COLOR_GREEN, 0, 700, 0);
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
	init_pair(4, COLOR_GREEN, COLOR_BLACK);

}

void				init(void)
{
	initscr();
	setColors();
	cbreak(); // or raw() of we want to catch all inputs including ctr-c, etc.
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	refresh();
}

int					main(void)
{
	// Primary variables
	DisplaySprite		displayService;
	int					i, row, col;
	std::stringstream	buff;

	// Screen init
	init();
	getmaxyx(stdscr, col, row);

	// Windows variables
	Window 				game(0, 0, col / 5 * 4, row);
	Window				debug(0, col / 5 * 4, col / 5, row);
	displayService.display("Game", Position(1, 0), 3, game.getWindow());
	displayService.display("Debug", Position(1, 0), 3, debug.getWindow());

	g_debug = debug.getWindow();

	// Secondary variables
	Fps					fps;
	Interval			itv;

	i = 0;
	while (1)
	{
		buff.str(std::string());
		buff.clear();
		game.refreshWindow();
		while (itv.value() < CLOCKS_PER_SEC / 60);
		buff << "FPS: " << fps.get();
		refresh();
		displayService.display(buff.str(), Position(row - 8, 1), 2, debug.getWindow());
		wrefresh(game.getWindow());
		wrefresh(debug.getWindow());
		i++;
		fps.update();
		itv.refresh();
	}
//	win.switchDefaultColors(false); //TODO: en faire une fonction membre de Window
}
