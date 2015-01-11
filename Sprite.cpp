#include <iostream>
#include <sstream>
#include "Sprite.hpp"

Sprite::Sprite(std::string *sprite, int y) : _sprite(sprite), _y(y)
{
	std::cout << "[CONSTRUCTED] Sprite" << std::endl;
	return ;
}

Sprite::Sprite(Sprite const & src)
{
	std::cout << "[CONSTRUCTED] Sprite" << std::endl;
	*this = src;
	return ;
}

Sprite::~Sprite( void )
{
	std::cout << "[DESTRUCTED] Sprite" << std::endl;
	delete this->_sprite;
	return ;
}

Sprite &	Sprite::operator=(Sprite const & rhs)
{
	this->_sprite = rhs._sprite;
	this->_y = rhs._y;
}

std::string		*Sprite::get(void) const
{
	return this->_sprite;
}

int				Sprite::getY(void) const
{
	return this->_y;
}

std::string		Sprite::toString(void) const {
	std::stringstream	buff;

	buff << "Sprite size: " <<this->_y <<"and it looks like: " << std::endl;
	for (int i = 0; i < this->_y; i++)
		buff << this->_sprite[i] <<std::endl;
	return buff.str();
}

Sprite::Sprite( void ) : _sprite(NULL), _y(0)
{
	std::cout << "[CONSTRUCTED] Sprite" << std::endl;
	return ;
}

std::ostream &	operator<<(std::ostream & o, Sprite const & rhs) {
	o << rhs.toString();
	return o;
}
