#ifndef ALIST_HPP
# define ALIST_HPP
# include <string>
# include <sstream>
# include <iostream>

class AList
{
	public:
		AList( void );
		AList(AList const & src);
		~AList( void );
		AList &	operator=(AList const & rhs);

		std::string	toString() const;

		AList *				getNext() const;
		AList *				getPrevious() const;
		static AList *		getHead();
		static void			pushFront(AList *alist);
		void				deleteNode();

	private:
		AList *				_next;
		AList *				_previous;
		static AList *		_head;
		static unsigned int	_nb_node;
};

std::ostream &		operator<<(std::ostream & o, AList const & rhs);

#endif /* ALIST_HPP */
