#include <ncurses.h>
#include <ctime>
#include "Interval.hpp"

Interval::Interval( void ) : _initial(std::clock())
{
	Console::log("[CONSTRUCTED] Interval...", 4);
	return ;
}

Interval::Interval(Interval const & src)
{
	Console::log("[CONSTRUCTED] Interval...", 4);
	*this = src;
	return ;
}

Interval::~Interval( void )
{
	Console::log("[DESTRUCTED] Interval...", 2);
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

