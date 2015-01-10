#ifndef POSITION_HPP
# define POSITION_HPP
# include <iostream>

class Position
{
	public:
		Position(int x, int y);
		Position(Position const & src);
		~Position( void );
		Position &	operator=(Position const & rhs);

		int			getX() const;
		int			getY() const;
		void		update(int const x, int const y);
		std::string	toString(void) const;

	private:
		Position( void );
		int			_x;
		int			_y;
};

std::ostream &	operator<<(std::ostream & o, Position const & rhs);

#endif /* POSITION_HPP */
