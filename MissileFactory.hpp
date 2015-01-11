#ifndef MISSILEFACTORY_HPP
# define MISSILEFACTORY_HPP

class MissileFactory
{
	public:
		MissileFactory(Hitbox hb, Sprite sp, Pattern pattern, ACharacter const & owner, int speed);
		MissileFactory(MissileFactory const & src);
		~MissileFactory( void );
		MissileFactory &	operator=(MissileFactory const & rhs);

		void				launchMissile(Pos &pos);

	private:
		MissileFactory( void );
		Hitbox				_hb;
		Sprite				_sp;
		Pattern				_pat;
		ACharacter const &	_owner;
		int					_speed;
};

#endif /* MISSILEFACTORY_HPP */
