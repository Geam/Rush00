#include <iostream>
#include <ncurses.h>
#include "Window.hpp"
#include "Interval.hpp"
#include "Fps.hpp"
#include "DisplaySprite.hpp"

int					main(void)
{
	Window			win(200,80);
	Interval		itv;
	Fps				fps;
	int				i;
	std::stringstream buff;

	i = 0;
	win.initWindow();
	while (1)
	{
		buff.str(std::string());
		buff.clear();
		win.refreshWindow();
		while (itv.value() < CLOCKS_PER_SEC / 60);
		buff << "FPS: " << fps.get();

		attron(COLOR_PAIR(2));
		mvprintw(0, 0, buff.str().c_str());
		attroff(COLOR_PAIR(2));
		i++;
		fps.update();
		itv.refresh();
	}
//	win.switchDefaultColors(false); //TODO: en faire une fonction membre de Window
}
