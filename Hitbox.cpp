
#include "Hitbox.hpp"

Hitbox::Hitbox( void ) {}

Hitbox::Hitbox(int w, int h ) : _wth(w), _hei(h) {
}

Hitbox::Hitbox(Hitbox const & src) : _wth(src.getWidth()), _hei(src.getHeight())
{
	return ;
}

Hitbox::~Hitbox( void )
{
}

Hitbox &	Hitbox::operator=(Hitbox const & src) {
	this->_wth = src.getWidth();
	this->_hei = src.getHeight();
	return *this;
}

int				Hitbox::getWidth() const
{
	return this->_wth;
}

int				Hitbox::getHeight() const
{
	return this->_hei;
}

