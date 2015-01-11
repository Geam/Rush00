
#include "Game.hpp"

Game::Game( void )
{
	std::cout << "[CONSTRUCT] Game" << std::endl;
	return ;
}

Game::Game( Window const & win )
{
	this->_spawner.setWindow(win);
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
	this->_player.getInputController().readInput();
	if (this->_player.getInputController().getInput() == 0)
		this->_isQuit();
}

void				Game::refresh()
{
	this->_getInput();
	this->_spawner.refresh();
	this->_refreshGameEntity();
	CollisionChecker::checkCollision(*AGameEntity::getHead());
	this->_isOver();
	this->_deathCheck();
	return ;
}

