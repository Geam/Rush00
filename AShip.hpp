#ifndef ASHIP_HPP
# define ASHIP_HPP

class AShip
{
	public:
		AShip( void );
		AShip(AShip const & src);
		virtual		~AShip( void );
		AShip &			operator=(AShip const & rhs);

		void			takeDamage(int damage);
		void			apRecover();
	protected:
		int				_ap;
		int				_ap_rec;
		int				_hp;
		unsigned int	_max_hp;
		unsigned int	_armor;
		AWeapon	*		_wep;
//		Appearance *	_sprite sprite

};

#endif /* ASHIP_HPP */
