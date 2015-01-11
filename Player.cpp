
#include "ACharacter.hpp"
#include "Player.hpp"

Player::Player(Player const & src) : ACharacter(src)
{
	*this = src;
	return ;
}

Player::~Player( void )
{
}

Player &		Player::operator=(Player const & rhs)
{
	AGameEntity::operator=(rhs);
	this->_controler = rhs.getInputControler();
	return *this;
}

void			Player::destroy(void)
{
}

void			Player::refresh(void)
{
	int			thisx;
	int			thisy;

	thisx = this->_pos.getX();
	if (this->getInputControler().getInput() == 1)
	{
		thisy = this->_pos.getY() - 1;
		this->_pos.update(thisx, thisy);
	}
	if (this->getInputControler().getInput() == 2)
	{
		thisy = this->_pos.getY() + 1;
		this->_pos.update(thisx, thisy);
	}
	if (this->getInputControler().getInput() == 3)
		this->fireMissile("4");
}

Player::Player() : ACharacter(0, 0, 3, 3)
{
	const std::string tsprite[] = {
		"- ", "}>", "- ",
	};
	this->_hb.setWidth(1);
	this->_hb.setHeight(2);
	this->_sp.set(tsprite, 3);
}
