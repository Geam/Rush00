#ifndef MISSILE_HPP
# define MISSILE_HPP

# include <string>
# include "ACharacter.hpp"
# include "AGameEntity.hpp"
# include "Pattern.hpp"

class Missile : public AGameEntity
{
	public:
							Missile(int x, int y, std::string pattern, ACharacter const & owner);
							Missile(Missile const & src);
							~Missile( void );
		Missile &			operator=(Missile const & rhs);

		virtual void		refresh(void);
		virtual void		destroy(void);

		int					getX( void ) const;
		int					getY( void ) const;
		Pattern	&			getPattern( void ) const;
		ACharacter &		getOwner( void ) const;

	protected:
		int					_x;
		int					_y;
		Pattern &			_pattern;
		ACharacter &		_owner;

	private:
		Missile( void );
};

#endif /* MISSILE_HPP */
