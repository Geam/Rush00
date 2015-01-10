#ifndef POSITION_HPP
# define POSITION_HPP

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

	private:
		Position( void );
		int			_x;
		int			_y;
};

#endif /* POSITION_HPP */
