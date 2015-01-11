
#include "Missile.hpp"

Missile::Missile(int x, int y, int speed, std::string pattern) : AGameEntity(x, y, speed)
{
	std::string *tsprite = new std::string[1];
	tsprite[0] = "-";
	this->_pattern.set(pattern);
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
	this->_hb.setWidth(0);
	this->_hb.setHeight(0);
	this->_sp.set(tsprite, 1);
	return ;
}

Missile::Missile(Position pos, int speed, std::string pattern) : AGameEntity(pos.getX(), pos.getY(), speed)
{
	std::string *tsprite = new std::string[1];
	tsprite[0] = "-";
	this->_pattern.set(pattern);
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
	this->_hb.setWidth(0);
	this->_hb.setHeight(0);
	this->_sp.set(tsprite, 1);
	return ;
}

Missile::Missile(Missile const & src) : AGameEntity(src)
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
	if (this->_speed == 0)
	{
		this->_moveCtrl.move();
		this->_speed = this->_maxspeed;
	}
	else
		this->_speed--;
}

void				Missile::destroy(void)
{
}

Pattern const &		Missile::getPattern( void ) const
{
	return (this->_pattern);
}
