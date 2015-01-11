#include <ncurses.h>
#include "InputController.hpp"

// {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, ' '};
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

void				InputController::readInput(char ch) {
	int keys[KEYS_LENGTH] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, ' '};

	for (int i = 0; i < KEYS_LENGTH; i++) {
		if (ch == keys[i]) {
			// ici, déclencher les bons événements
			break;
		}
	}
}

int					InputController::getInput(void)
{
	return this->_input;
}

InputController::InputController( void )
{
}

