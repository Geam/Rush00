/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interval.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:38:32 by afaucher          #+#    #+#             */
/*   Updated: 2015/01/10 15:38:51 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <ctime>
#include "Interval.hpp"

extern WINDOW *g_debug;

Interval::Interval( void ) : _initial(std::clock())
{
	Interval::_log("[CONSTRUCTED] Interval...", 4);
	return ;
}

Interval::Interval(Interval const & src)
{
	Interval::_log("[CONSTRUCTED] Interval...", 4);
	*this = src;
	return ;
}

Interval::~Interval( void )
{
	Interval::_log("[DESTRUCTED] Interval...", 2);
	return ;
}

Interval &	Interval::operator=(Interval const & rhs)
{
	this->_initial = rhs._initial;
	return *this;
}

std::string	Interval::toString() const
{
	std::ostringstream ostr;

	ostr << "Interval : Initial Value " << this->_initial << " Current Value " <<
		this->value() << std::endl;
	return ostr.str();
}

void			Interval::refresh()
{
	this->_initial = std::clock();
}

unsigned int	Interval::value() const
{
	return std::clock() - this->_initial;
}

std::ostream &	operator<<(std::ostream & o, Interval const & rhs)
{
	o << rhs.toString();
	return o;
}

void	Interval::_log(std::string message, int color) {
	int y, maxY, maxX;

	maxX = getmaxx(g_debug);
	maxY = getmaxy(g_debug);
	y = getcury(g_debug);
	if (y + 1 == maxY)
		y = 1;
	if (y == 0)
		y++;
	wattron(g_debug, COLOR_PAIR(color));
	mvwhline(g_debug, y, 1, ' ', maxX - 10);
	wmove(g_debug, y, 1);
	mvwprintw(g_debug, y, 1, message.c_str());
	wmove(g_debug, y + 1, 1);
	wattroff(g_debug, COLOR_PAIR(color));
}