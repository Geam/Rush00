
#include "Game.hpp"

Game::Game( void )
{
	Console::log("[CONSTRUCT] Game", 4);
	return ;
}

Game::Game(Game const & src)
{
	Console::log("[CONSTRUCT] Game", 4);
	*this = src;
	return ;
}

Game::~Game( void )
{
	Console::log("[DESTRUCT] Game", 4);
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

