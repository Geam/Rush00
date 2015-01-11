
#include "Game.hpp"

Game::Game( void )
{
	std::cout << "[CONSTRUCT] Game" << std::endl;
	return ;
}

Game::Game(Game const & src)
{
	std::cout << "[CONSTRUCT] Game" << std::endl;
	*this = src;
	return ;
}

Game::~Game( void )
{
	std::cout << "[DESTRUCT] Game" << std::endl;
}

Game &	Game::operator=(Game const & rhs)
{
	(void)rhs;
	return *this;
}

void				Game::_refreshGameEntity()
{
	AGameEntity		*current;

	current = AGameEntity::getHead();
	while (current)
	{
		current->refresh();
		current = current->getNext();
	}
}

void				Game::_deathCheck()
{
	AGameEntity		*current;
	AGameEntity		*save;

	current = AGameEntity::getHead();
	while (current)
	{
		save = current->getNext();
		if (current->isDead())
			delete current;
		current = save;
	}
}

void				Game::refresh()
{
	this->_refreshGameEntity();
	CollisionChecker::checkCollision(*AGameEntity::getHead());
	this->_deathCheck();
	return ;
}

