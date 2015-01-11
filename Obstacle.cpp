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
	std::cout << "[CONSTRUCT] Obstacle" << std::endl;
	*this = src;
}

Obstacle::~Obstacle( void )
{
	std::cout << "[DESTRUCT] Obstacle" << std::endl;
}

Obstacle &		Obstacle::operator=(Obstacle const & rhs)
{
	AGameEntity::operator=(rhs);
	return *this;
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
	std::cout << "[CONSTRUCT] Obstacle" << std::endl;
}

