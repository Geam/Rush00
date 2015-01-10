#ifndef SCREEN_HPP
# define SCREEN_HPP
# include "AEntity.hpp"
# include <curses.h>

class Screen
{
	public:
		Screen(int x, int y);
		Screen(Screen const & src);
		~Screen( void );
		Screen &	operator=(Screen const & rhs);

		void		display(AEntity const & src);
		void		putElem(int const x, int const y, char const c, int color);

		int			getX(void) const;
		int			getY(void) const;

	private:
		int			_x;
		int			_y;

		Screen( void );
		int			_init();
};

#endif /* SCREEN_HPP */
