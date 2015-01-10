
#include "ACharacter.hpp"
#include "Player.hpp"

Player::Player(Player const & src) : ACharacter(src)
{
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
	if (this->getInputControler().getInput() = 1)
	{
		thisy = this->_pos.getY() - 1;
		this->_pos.update(thisx, thisy);
	}
	if (this->getInputControler().getInput() = 2)
	{
		thisy = this->_pos.getY() + 1;
		this->_pos.update(thisx, thisy);
	}
	if (this->getInputControler().getInput() = 3)
		this->fireMissile();
}

Player::Player(void)
{
}

