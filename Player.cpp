
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
	this->_controller = rhs._controller;
	return *this;
}

void			Player::_getInput(void)
{
	int			thisx;
	int			thisy;

	thisx = this->_pos.getX();
	if (InputController::getInput() == 1)
	{
		thisy = this->_pos.getY() - 1;
		this->_pos.update(thisx, thisy);
	}
	if (InputController::getInput() == 2)
	{
		thisy = this->_pos.getY() + 1;
		this->_pos.update(thisx, thisy);
	}
	if (InputController::getInput() == 3)
		this->fireMissile("4");
}

void			Player::refresh(void)
{
	if (this->_speed == 0)
	{
		DisplaySprite::erase(this->_sp, this->_pos, AGameEntity::_window);
		this->_getInput();
		this->_speed = this->_maxspeed;
		DisplaySprite::display(this->_sp, this->_pos, 4,AGameEntity::_window);
	}
	else
		this->_speed--;
}

void			Player::fireMissile(std::string pattern)
{
	if (this->_frate == 0)
		Missile(this->_mslOrigin + this->_pos, 0, pattern);
	else
		this->_frate--;
}

Player::Player() : ACharacter(0, 0, 3, 3)
{
	const std::string tsprite[] = {
		"- ", "}>", "- ",
	};
	this->_hb.setWidth(1);
	this->_hb.setHeight(2);
	this->_sp.set(tsprite, 3);
	this->_mslOrigin.update(this->_hb.getWidth() + 1, this->_hb.getHeight() / 2 + 1);
}
