#ifndef INPUTCONTROLLER_HPP
# define INPUTCONTROLLER_HPP

class InputController
{
	public:
		InputController( void );
		InputController(InputController const & src);
		~InputController( void );
		InputController &	operator=(InputController const & rhs);

		void				readInput(void);
		int					getInput(void);

	private:
		int					_input;
};

#endif /* INPUTCONTROLLER_HPP */
