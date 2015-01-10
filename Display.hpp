#ifndef DISPLAY_HPP
# define DISPLAY_HPP

class IDisplay
{
	public:
		IDisplay( void );
		Display(Display const & src);
		virtual ~Display( void );
		Display &	operator=(Display const & rhs);

};

#endif /* DISPLAY_HPP */
