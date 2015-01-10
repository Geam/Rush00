#include <ncurses.h>
#include "InputController.hpp"

InputController::InputController(InputController const & src)
{
	*this = src;
}

InputController::~InputController( void )
{
}

InputController &	InputController::operator=(InputController const & rhs)
{
}

void				InputController::readInput(char ch)
{
	if (ch == KEY_UP)
		this->_input = 1;
	else if (ch == KEY_DOWN)
		this->_input = 2;
	else if (ch == ' ')
		this->_input = 3;
	else if (ch == 27)
		this->_input = 0;
	return ;
}

int					InputController::getInput(void)
{
	return this->_input;
}

InputController::InputController( void )
{
}

