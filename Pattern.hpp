#ifndef PATTERN_HPP
# define PATTERN_HPP

#include <iostream>
#include <string>
#include <sstream>
enum	e_direction { NONE = 0, UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4};
class Pattern
{
	public:
		Pattern(std::string const & pattern);
		Pattern(Pattern const & src);
		~Pattern( void );
		Pattern &	operator=(Pattern const & rhs);
		std::string	toString() const;

		e_direction	next();
		std::string		getPattern( void ) const;

	private:
		std::string	_pattern;
		int			_current;
		int			_last;
		Pattern( void );
};

std::ostream &			operator<<(std::ostream & o, Pattern const & rhs);

#endif /* PATTERN_HPP */
