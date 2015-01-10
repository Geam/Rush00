#include "AGameEntity.hpp"

AGameEntity::AGameEntity(int x, int y, int wdth, int hgth, int speed, int maxspeed, Sprite const & sprite) :
	_pos(Position(x, y)), _hb(Hitbox(wdth, hgth)), _sp(sprite), _speed(speed), _maxspeed(maxspeed), _dead(false),
	_index(AGameEntity::_nb_inst++)
{
	std::cout << "[CONSTRUCT] Game Entity" << std::endl;
	return ;
}

AGameEntity::AGameEntity(AGameEntity const & src) :
	_pos(Position(src._pos)), _hb(Hitbox(src._hb)), _sp(src._sp), _speed(src._speed), _maxspeed(src._maxspeed), _dead(false), _index(AGameEntity::_nb_inst++)
{
	std::cout << "[CONSTRUCT] Game Entity" << std::endl;
	return ;
}

AGameEntity::~AGameEntity( void )
{
	std::cout << "[DESTRUCT] Game Entity" << std::endl;
	return ;
}

AGameEntity &			AGameEntity::operator=(AGameEntity const & rhs)
{
	this->_pos = rhs._pos;
	this->_hb = rhs._hb;
	this->_sp = rhs._sp;
	this->_dead = rhs._dead;
	this->_speed = rhs._speed;
	this->_maxspeed = rhs._maxspeed;
	return *this;
}

Position const &				AGameEntity::getPosition(void) const
{
	return this->_pos;
}

Hitbox const &				AGameEntity::getHitbox(void) const
{
	return this->_hb;
}

Sprite const &				AGameEntity::getSprite(void) const
{
	return this->_sp;
}

int						AGameEntity::getSpeed() const
{
	return this->_speed;
}

std::string				AGameEntity::toString(void) const
{
	std::stringstream	ostr;

	ostr << "Game Entity (" << this->_index << ") has position : " << this->_pos
		<< ", hitbox : " << this->_hb << ", sprite : " << this->_sp
		<< ", dead : " << this->_dead << ", speed : " << this->_speed
		<< ", speedmax " << this->_maxspeed << "." << std::endl;
	return ostr.str();
}

std::ostream &			operator<<(std::ostream & o, AGameEntity const & rhs)
{
	o << rhs.toString();
	return o;
}

unsigned int _nb_inst = 0;
