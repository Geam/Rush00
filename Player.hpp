#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "ACharacter.hpp"
#include "InputControler.hpp"

class Player : public ACharacter
{
	public:
		Player(Player const & src);
		~Player( void );
		Player &	operator=(Player const & rhs);

		virtual void	destroy(void);
		virtual void	refresh(void);

		InputControler	getInputControler(void);

	private:
		InputControler	_controler;
		Player(void);
};

#endif /* PLAYER_HPP */
