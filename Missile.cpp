
#include "Missile.hpp"

Missile::Missile(int x, int y, int speed, std::string pattern) : AGameEntity(x, y, speed)
{
	Console::log("=== Missile ===", 4);
	std::string *tsprite = new std::string[1];
	tsprite[0] = "+=-";
	this->_pattern.set(pattern);
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
	this->_hb.setWidth(0);
	this->_hb.setHeight(0);
	this->_sp.set(tsprite, 1);
	return ;
}

Missile::Missile(Position pos, int speed, std::string pattern) : AGameEntity(pos.getX(), pos.getY(), speed)
{
	Console::log("=== Missile ===", 4);
	std::string *tsprite = new std::string[1];
	tsprite[0] = "+=-";
	this->_pattern.set(pattern);
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
	this->_hb.setWidth(0);
	this->_hb.setHeight(0);
	this->_sp.set(tsprite, 1);
	return ;
}

Missile::Missile(Missile const & src) : AGameEntity(src)
{
	Console::log("Missile destruct", 2);
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
		DisplaySprite::erase(this->_sp, this->_pos, AGameEntity::_window);
		this->_moveCtrl.move();
		this->_checkOutOfBound();
		this->_speed = this->_maxspeed;
		DisplaySprite::display(this->_sp, this->_pos, 6,AGameEntity::_window);
	}
	else
		this->_speed--;
}

void		Missile::_checkOutOfBound()
{
	if (this->_pos.getX() <= -1 || this->_pos.getX() >= AGameEntity::_winX)
		this->_dead = true;
}

void				Missile::destroy(void)
{
}

Pattern const &		Missile::getPattern( void ) const
{
	return (this->_pattern);
}
