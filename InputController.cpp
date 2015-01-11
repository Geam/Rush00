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
	(void)rhs;
	return *this;
}

void				InputController::readInput(void)
{
	int				ch;

	ch = getch();
	switch (ch)
	{
		case 27:
			this->_input = 0;
			break ;
		case ' ':
			this->_input = 1;
			break ;
		case KEY_UP:
			this->_input = 2;
			break ;
		case KEY_DOWN:
			this->_input = 3;
			break ;
	}
}

int					InputController::getInput(void)
{
	return this->_input;
}

InputController::InputController( void ) : _input(-1)
{
}

