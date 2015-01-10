#include <iostream>
#include "ACharacter.hpp"


ACharacter::ACharacter(int frate, int maxfrate, int speed, int maxspeed) : AGameEntity(....), _frate(frate), _maxfrate(maxfrate), _speed(speed), _maxspeed(speed)
{
	std::cout << "[CONSTRUCTED] ACharacter" << std::endl;
	return;	
}

ACharacter::ACharacter(ACharacter const & src) : AGameEntity(src)
{
	return ;
}

ACharacter::~ACharacter( void )
{
	std::cout << "[DESTRUCT] ACharacter" << std::endl;
	return;
}

ACharacter &	ACharacter::operator=(ACharacter const & rhs)
{
	this->_frate = rhs.getFireRate();
	this->_maxfrate = rhs.getMaxFireRate();
	this->_speed = rhs.getSpeed();
	this->_maxspeed = rhs.getMaxSpeed();
	return *this;
}

Missile	const&	ACharacter::fireMissile(std::string pattern)
{
	return Missile(this->_pos.getX(),this->_pos.getY(), pattern, *this);
}

int				ACharacter::getFireRate() const
{
	return this->_frate;
}

int				ACharacter::getMaxFireRate() const
{
	return this->_maxfrate;
}

int				ACharacter::getSpeed() const
{
	return this->_maxfrate;
}

int				ACharacter::getMaxSpeed() const
{
	return this->_maxspeed;
}

ACharacter::ACharacter( void )
{
	return;
}
