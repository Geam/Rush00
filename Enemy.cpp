#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int frate, int speed, std::string pattern) : ACharacter(x, y, frate, speed)
{
	const std::string tsprite[] = {
		"-<{"
	};
	std::cout << "[CONSTRUCT] Enemy" << std::endl;
	this->_pattern.set(pattern);
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
	this->_hb.setWidth(2);
	this->_hb.setHeight(0);
	this->_sp.set(tsprite, 1);
	return;
}

Enemy::Enemy(Enemy const & src) : ACharacter(src)
{
	*this = src;
	return;
}

Enemy::~Enemy( void )
{
	std::cout << "[DESTRUCT] Enemy" << std::endl;
	return;
}

Enemy &	Enemy::operator=(Enemy const & rhs)
{
	this->ACharacter::operator=(rhs);
	this->_pattern = rhs.getPattern();
	return *this;
}

void		Enemy::refresh(void)
{
	--(this->_speed);
	if (!this->_speed)
	{
		this->_speed = this->_maxspeed;
		this->_moveCtrl.move();
	}
}

Enemy::Enemy(void)
{
	return;
}
