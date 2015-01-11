#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int x, int y, std::string pattern) : ACharacter(3, 5, 1, 2)
{
	std::cout << "[CONSTRUCT] Enemy" << std::endl;
	this->_pos.update(x, y);
	this->_pattern = Pattern(pattern);
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
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
	this->ACharacter::operator=();
	this->_pattern = rhs.getPattern();
}

void		Enemy::destroy(void)
{
	return;
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
