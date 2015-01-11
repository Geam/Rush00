#include <iostream>
#include "Obstacle.hpp"

Obstacle::Obstacle(int x, int y, int spe) : AGameEntity(x, y, spe)
{
	std::string tsprite[] = { "#" };
	this->_hb.setWidth(0);
	this->_hb.setHeight(0);
	this->_sp.set(tsprite, 1);
}

Obstacle::Obstacle(Obstacle const & src) : AGameEntity(src)
{
	Console::log("[CONSTRUCT] Obstacle", 4);
	*this = src;
}

Obstacle::~Obstacle( void )
{
	Console::log("[DESTRUCT] Obstacle", 4);
}

Obstacle &		Obstacle::operator=(Obstacle const & rhs)
{
	AGameEntity::operator=(rhs);
	return *this;
}

void			Obstacle::collidesWith(AGameEntity const & ge)
{
	(void)ge;
	return ;
}

void			Obstacle::refresh(void)
{
	int			thisx;
	int			thisy;

	thisx = this->_pos.getX();
	thisy = this->_pos.getY();
	if (this->getSpeed() > 0)
	{
		this->_speed--;
		return ;
	}
	this->_speed = this->_maxspeed;
	this->_pos.update(--thisx, thisy);
}

void			Obstacle::destroy(void)
{
	this->_dead = 1;
}

Obstacle::Obstacle( void )
{
	Console::log("[CONSTRUCT] Obstacle", 4);
}

