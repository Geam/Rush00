
#include "Obstacle.hpp"

Obstacle::Obstacle(Obstacle const & src)
{
	*this = src;
}

Obstacle::~Obstacle( void )
{
}

Obstacle &		Obstacle::operator=(Obstacle const & rhs)
{
	AGameEntity::operator=(rhs);
	return *this;
}

void			Obstacle::refresh(void)
{
}

void			Obstacle::destroy(void)
{
}

Obstacle::Obstacle( void )
{
}

