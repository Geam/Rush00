
#include "Missile.hpp"

Missile::Missile(int x, int y, int speed, std::string pattern) : AGameEntity(x, y, speed)
{
	std::string tsprite[1] = { "-" };
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
	this->_moveCtrl.move();
}

void				Missile::destroy(void)
{
}

Pattern const &		Missile::getPattern( void ) const
{
	return (this->_pattern);
}
