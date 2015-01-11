#ifndef HITBOX_HPP
# define HITBOX_HPP
# include <iostream>

class Hitbox
{
	public:
		Hitbox( void );
		Hitbox(int wth, int hei);
		Hitbox(Hitbox const & src);
		~Hitbox( void );
		Hitbox &	operator=(Hitbox const & rhs);

		int			getWidth() const;
		int			getHeight() const;
		std::string	toString(void) const;

	private:
		int			_wth;
		int			_hei;
};

std::ostream &	operator<<(std::ostream & o, Hitbox const & rhs);

#endif /* HITBOX_HPP */
