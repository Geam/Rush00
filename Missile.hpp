#ifndef MISSILE_HPP
# define MISSILE_HPP

# include <string>
# include "ACharacter.hpp"
# include "AGameEntity.hpp"
# include "Pattern.hpp"

class Missile : public AGameEntity
{
	public:
								Missile(Position & pos, Hitbox hb, Sprite sp, Pattern pattern, ACharacter const & owner, int speed);
								Missile(Missile const & src);
								~Missile( void );
		Missile &				operator=(Missile const & rhs);

		virtual void			refresh(void);
		virtual void			destroy(void);

		Pattern	&				getPattern( void ) const;
		ACharacter const &		getOwner( void ) const;

	protected:
		Pattern &				_pattern;
		ACharacter const &		_owner;

	private:
		Missile( void );
};

#endif /* MISSILE_HPP */
