#ifndef IDISPLAY_HPP
# define IDISPLAY_HPP

class IDisplay
{
	public:
		IDisplay( void );
		IDisplay(IDisplay const & src);
		virtual ~IDisplay( void );
		virtual IDisplay &	operator=(IDisplay const & rhs)=0;

		virtual	void		display(void)=0;
};

#endif /* IDISPLAY_HPP */
