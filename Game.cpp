
#include "Game.hpp"

Game::Game( void )
{
	Console::log("[CONSTRUCT] Game", 4);
	return ;
}

Game::Game( Window const & win ) : _status(0)
{
	this->_spawner.setWindow(win);
	AGameEntity::setWindow(win);
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
	(void)current;
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

void				Game::_isQuit()
{
	if (this->_player.isQuit())
	{
		Console::log("YOU LEFT THE GAME.", 3);
		this->_status = 2;
	}
}

void				Game::_isOver()
{
	if (this->_player.isDead())
	{
		int			ch;
		Console::log("YOU DIED. LOSER.", 3);
		timeout(-1);
		do
		{
			ch = getch();
		}
		while (ch != 10);
		this->_status = 1;
	}
}

char				Game::getStatus() const
{
	return this->_status;
}

void				Game::refresh()
{
	this->_spawner.refresh();
	this->_refreshGameEntity();
	CollisionChecker::checkCollision(*AGameEntity::getHead());
	this->_isQuit();
	this->_isOver();
	if (!this->_status)
		this->_deathCheck();
	return ;
}

