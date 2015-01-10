
#include "Missile.hpp"

Missile::Missile(int x, int y, std::string pattern, ACharacter const & owner) :	_x(x), _y(y), _pattern(Pattern(pattern)), _owner(owner)
{
	return ;
}

Missile::Missile(Missile const & src) : _x(src.getX()), _y(src.getY()), _pattern(src.getPattern().getPattern()), _owner(src.getOwner())
{
	return ;
}

Missile::~Missile( void )
{
}

Missile &	Missile::operator=(Missile const & rhs)
{
}

void		Missile::refresh(void)
{
}

void		Missile::destroy(void)
{
}

int			Missile::getX( void ) const
{
	return (this->_x);
}

int			Missile::getY( void ) const
{
	return (this->_y);
}

Pattern &	Missile::getPattern( void ) const
{
	return (this->_pattern);
}

ACharacter &	Missile::getOwner( void ) const
{
	return (this->_owner);
}

Missile::Missile( void ) : 	_x(0), _y(0), _pattern(Pattern("x")), _owner(getOwner())
{
}
