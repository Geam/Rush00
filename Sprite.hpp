#ifndef SPRITE_HPP
# define SPRITE_HPP
# include <iostream>

class Sprite
{
	public:
		Sprite(std::string sprite[], int y);
		Sprite(Sprite const & src);
		~Sprite( void );
		Sprite &	operator=(Sprite const & rhs);

		std::string *	get(void);
		int				getY(void) const;
		std::string		toString(void) const;

	private:
		Sprite( void );
		std::string		_sprite[];
		int				_y;
};

std::ostream &	operator<<(std::ostream & o, Sprite const & rhs);

#endif /* SPRITE_HPP */
