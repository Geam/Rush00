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


int					InputController::getInput(void)
{
	int				ch;
	int				res = -1;

	ch = getch();
	switch (ch)
	{
		case 27:
			res = 0;
			break ;
		case ' ':
			res = 1;
			break ;
		case KEY_UP:
			res = 2;
			break ;
		case KEY_DOWN:
			res = 3;
			break ;
	}
	return res;
}

InputController::InputController( void )
{
}

