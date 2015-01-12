
#include "ACharacter.hpp"
#include "Player.hpp"

Player::Player() : ACharacter(3, 0, 3, 3)
{
	std::string *tsprite = new std::string[3];

	tsprite[0] = "- ";
	tsprite[1] = "}>";
	tsprite[2] = "- ";
	this->_hb.setWidth(1);
	this->_hb.setWidth(1);
	this->_hb.setWidth(1);
	this->_hb.setHeight(2);
	this->_sp.set(tsprite, 3);
	this->_mslOrigin.update(this->_hb.getWidth() + 1, this->_hb.getHeight() / 2 + 1);
}

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

bool			Player::_getInput(void)
{
	int			thisx;
	int			thisy;
	int			ch = getch();

	thisx = this->_pos.getX();
	thisy = this->_pos.getY();
	if (ch == KEY_UP)
	{
		thisy -= 1;
		this->_pos.update(thisx, thisy);
		return true;
	}
	if (ch == KEY_DOWN)
	{
		thisy += 1;
		this->_pos.update(thisx, thisy);
		return true;
	}
	if (ch == ' ')
	{
		this->fireMissile("4");
		return true;
	}
	return false;
}

void			Player::refresh(void)
{
	if (this->_getInput() && this->_speed == 0)
	{
		DisplaySprite::erase(this->_sp, this->_pos, AGameEntity::_window);
		this->_speed = this->_maxspeed;
		DisplaySprite::display(this->_sp, this->_pos, 4,AGameEntity::_window);
	}
	else
		this->_speed = (this->_speed - 1) <= 0 ? 0 : this->_speed - 1;
}

void			Player::fireMissile(std::string pattern)
{
	if (this->_frate == 0)
		Missile(this->_mslOrigin + this->_pos, 0, pattern);
	else
		this->_frate--;
}

