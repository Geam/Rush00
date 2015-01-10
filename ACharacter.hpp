#ifndef ACHARACTER_HPP
# define ACHARACTER_HPP
# include "AGameEntity.hpp"
# include "Missile.hpp"

class ACharacter : public AGameEntity
{
	public:
		ACharacter(int frate, int maxfrate, int speed, int maxspeed);
		ACharacter(ACharacter const & src);
		virtual ~ACharacter( void );
		ACharacter &	operator=(ACharacter const & rhs);

		Missile	const	&fireMissile(std::string pattern);
		int				getFireRate(void) const;
		int				getMaxFireRate(void) const;
		int				getSpeed(void) const;
		int				getMaxSpeed(void) const;

	protected:
		int				_frate;
		int				_maxfrate;
		int				_speed;
		int				_maxspeed;

	private:
		ACharacter( void );
};

#endif /* ACHARACTER_HPP */
