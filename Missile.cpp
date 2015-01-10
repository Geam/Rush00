
#include "Missile.hpp"

Missile::Missile(Position & pos, Hitbox hb, Sprite sp, Pattern pattern, ACharacter const & owner, int speed) : _pattern(pattern), _owner(owner)
{
	this->_pos = pos;
	this->_hb = hb;
	this->_sp = sp;
	this->_dead = false;
	this->_speed = speed;
	this->_maxspeed = speed;
	return ;
}

Missile::Missile(Missile const & src) : _pattern(src.getPattern()), _owner(src.getOwner())
{
	this->_pos = src._pos;
	this->_hb = src._hb;
	this->_sp = src._sp;
	this->_dead = src._dead;
	this->_speed = src._speed;
	this->_maxspeed = src._maxspeed;
	return ;
}

Missile::~Missile( void )
{
}

Missile &			Missile::operator=(Missile const & rhs)
{
	this->_pos = rhs._pos;
	this->_hb = rhs._hb;
	this->_sp = rhs._sp;
	this->_dead = rhs._dead;
	this->_speed = rhs._speed;
	this->_maxspeed = rhs._maxspeed;
	return (*this);
}

void				Missile::refresh(void)
{
}

void				Missile::destroy(void)
{
}

Pattern &			Missile::getPattern( void ) const
{
	return (this->_pattern);
}

ACharacter const &	Missile::getOwner( void ) const
{
	return (this->_owner);
}
