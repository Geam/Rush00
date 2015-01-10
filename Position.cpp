#include <iostream>
#include <sstream>
#include "Position.hpp"

Position::Position(int x, int y) : _x(x), _y(y){
	return;
}

Position::Position(Position const & src) : _x(src.getX()), _y(src.getY())
{
}

Position::~Position( void ){}

Position &	Position::operator=(Position const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return *this;
}

int			Position::getX(void) const{
	return (this->_x);
}

int			Position::getY(void) const {
	return (this->_y);
}

void		Position::update(int const x, int const y)
{
	this->_x = x;
	this->_y = y;
	return ;
}

std::string	Position::toString(void) const {
	std::stringstream	buff;

	buff << "Position: x = " <<this->_x <<"; y = "<< this->_y <<std::endl;
	return buff.str();
}

Position::Position(void)
{
}

std::ostream &	operator<<(std::ostream & o, Position const & rhs) {
	o << rhs.toString();
	return o;
}
