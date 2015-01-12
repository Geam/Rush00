
#include "Game.hpp"

Game::Game( void )
{
	Console::log("[CONSTRUCT] Game", 4);
	return ;
}

Game::Game( Window const & win )
{
	this->_spawner.setWindow(win);
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
	std::cout << "You left the game." << std::endl;
	exit(0);
}

void				Game::_isOver()
{
	if (this->_player.isDead())
	{
		int			ch;
		std::cout << "You died. Loser." << std::endl;
		timeout(-1);
		do
		{
			ch = getch();
		}
		while (ch != 10);
		exit(0);
	}
}

void				Game::_getInput()
{
	if (InputController::getInput() == 0)
		this->_isQuit();
}

void				Game::refresh()
{
	this->_getInput();
	this->_spawner.refresh();
	this->_refreshGameEntity();
//	CollisionChecker::checkCollision(*AGameEntity::getHead());
//	this->_isOver();
//	this->_deathCheck();
	return ;
}

