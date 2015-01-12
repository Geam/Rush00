#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "ACharacter.hpp"
#include "InputController.hpp"

class Player : public ACharacter
{
	public:
		Player(void);
		Player(Player const & src);
		~Player( void );
		Player &					operator=(Player const & rhs);

		virtual void				refresh(void);
		virtual void				fireMissile(std::string pattern);

	private:
		InputController				_controller;
		bool						_getInput();
};

#endif /* PLAYER_HPP */
