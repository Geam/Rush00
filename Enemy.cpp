#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int frate, int speed, std::string pattern) : ACharacter(x, y, frate, speed)
{
	std::string *tsprite = new std::string[1];
	Console::log("[CONSTRUCT] Enemy", 4);
	tsprite[0] = "<{";
	this->_pattern.set(pattern);
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
	this->_hb.setWidth(2);
	this->_hb.setHeight(0);
	this->_sp.set(tsprite, 1);
	this->_mslOrigin.update(this->_hb.getWidth() + 1, this->_hb.getHeight() / 2 + 1);
	Enemy::enemyCount++;
	return;
}

Enemy::Enemy(Enemy const & src) : ACharacter(src)
{
	*this = src;
	Enemy::enemyCount++;
	return;
}

Enemy::~Enemy( void )
{
	Console::log("[DESTRUCT] Enemy", 4);
	Enemy::enemyCount--;
	return;
}

Enemy &	Enemy::operator=(Enemy const & rhs)
{
	this->ACharacter::operator=(rhs);
	this->_pattern = rhs._pattern;
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

void		Enemy::fireMissile(std::string pattern)
{
	if (this->_frate == 0)
		Missile(this->_mslOrigin + this->_pos, 0, pattern);
	else
		this->_frate--;
}

Enemy::Enemy(void)
{
	return;
}

int			Enemy::enemyCount = 0;
