#ifndef SCREEN_HPP
# define SCREEN_HPP
# include "AEntity.hpp"
# include <curses.h>

class Screen
{
	public:
		Screen( void );
		Screen(Screen const & src);
		~Screen( void );
		Screen &	operator=(Screen const & rhs);

		void		display(AEntity const & src);
		void		putElem(int const x, int const y, char const c, int color);

	private:
		int const	_x;
		int const	_y;

};

#endif /* SCREEN_HPP */
