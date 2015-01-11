
#include "Missile.hpp"

Missile::Missile(Position & pos, Hitbox hb, Sprite sp, Pattern pattern, int speed) : _pattern(pattern)
{

	this->_pos = pos;
	this->_hb = hb;
	this->_sp = sp;
	this->_dead = false;
	this->_speed = speed;
	this->_maxspeed = speed;
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
	return ;
}

Missile::Missile(Missile const & src) : _pattern(src.getPattern())
{
	*this = src;
	return ;
}

Missile::~Missile( void )
{
}

Missile &			Missile::operator=(Missile const & rhs)
{
	this->AGameEntity::operator=(rhs);
	this->_moveCtrl = rhs._moveCtrl;
	return (*this);
}

void				Missile::refresh(void)
{
	this->_moveCtrl.move();
}

void				Missile::destroy(void)
{
}

Pattern const &		Missile::getPattern( void ) const
{
	return (this->_pattern);
}
