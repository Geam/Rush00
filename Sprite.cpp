
#include "Sprite.hpp"

Sprite::Sprite(std::string sprite[])
{
	this->_sprite[] = sprite[];
}

Sprite::Sprite(Sprite const & src)
{
	this->_sprite[] = src.get();
}

Sprite::~Sprite( void )
{
}

Sprite &	Sprite::operator=(Sprite const & rhs)
{
	this->_sprite[] = rhs.get();
	return *this;
}

std::string		*Sprite::get() const
{

}

Sprite::Sprite( void )
{
}

