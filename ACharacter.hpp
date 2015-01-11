#ifndef ACHARACTER_HPP
# define ACHARACTER_HPP
# include "AGameEntity.hpp"
# include "Missile.hpp"
# include "Position.hpp"

class ACharacter : public AGameEntity
{
	public:
		ACharacter(int x, int y, int frate, int speed);
		ACharacter(ACharacter const & src);
		virtual ~ACharacter( void );
		ACharacter &	operator=(ACharacter const & rhs);

		virtual void	fireMissile(std::string pattern);
		int				getFireRate(void) const;
		int				getMaxFireRate(void) const;
		int				getSpeed(void) const;
		int				getMaxSpeed(void) const;

	protected:
		ACharacter( void );
		int				_frate;
		int				_maxfrate;
		int				_speed;
		int				_maxspeed;
		Position		_mslOrigin;
};

#endif /* ACHARACTER_HPP */
