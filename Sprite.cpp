#include <iostream>
#include <sstream>
#include "Sprite.hpp"

Sprite::Sprite(std::string sprite[], int y)
{
	for (int i = 0; i < y; i++)
		this->_sprite[i] = sprite[i];
	this->_y = y;
}

Sprite::Sprite(Sprite const & src)
{
	std::string const *	tmp;

	this->_y = src.getY();
	tmp = src.get();
	for (int i = 0; i < this->_y; i++)
		this->_sprite[i] = tmp[i];
}

Sprite::~Sprite( void )
{
}

Sprite &	Sprite::operator=(Sprite const & rhs)
{
	std::string const *	tmp;

	this->_y = rhs.getY();
	tmp = rhs.get();
	for (int i = 0; i < this->_y; i++)
		this->_sprite[i] = tmp[i];
	return *this;
}

std::string		*Sprite::get(void)
{
	return this->_sprite;
}

int				Sprite::getY(void) const
{
	return this->_y;
}

std::string		Sprite::toString(void) const {
	std::stringstream	buff;

	buff << "Sprite size: " <<this->_y <<"and it looks like: " <<std::endl;
	for (int i = 0; i < this->_y; i++)
		buff << this->_sprite[i] <<std::endl;
	return buff.str();
}

Sprite::Sprite( void )
{
}

std::ostream &	operator<<(std::ostream & o, Sprite const & rhs) {
	o << rhs.toString();
	return o;
}
