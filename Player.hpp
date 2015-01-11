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
		Player &	operator=(Player const & rhs);

		virtual void	destroy(void);
		virtual void	refresh(void);

		InputController & getInputControler(void) const;

	private:
		InputController	_controler;
};

#endif /* PLAYER_HPP */
