
#include "AList.hpp"

AList::AList( void ) : _next(NULL), _previous(NULL)
{
	std::cout << "[CONSTRUCTED] Alist" << std::endl;
	AList::pushFront(this);
	return ;
}

AList::AList(AList const & src)
{
	std::cout << "[CONSTRUCTED] Alist" << std::endl;
	*this = src;
	AList::pushFront(this);
	return ;
}

AList::~AList( void )
{
	deleteNode();
	return ;
}

AList &	AList::operator=(AList const & rhs)
{
	return *this;
}

std::string	AList::toString() const
{
	std::ostringstream ostr;

	ostr << "AList : previous :" << (this->_previous == NULL) << "next : " << (this->_next == NULL);
	return ostr.str();
}

AList *				AList::getNext() const
{
	return this->_next;
}

AList *				AList::getPrevious() const
{
	return this->_previous;
}

AList *		AList::getHead()
{
	return AList::_head;
}

void				AList::pushFront(AList *alist)
{
	AList *save = AList::_head;

	AList::_head = alist;
	alist->_next = save;
	if (save != NULL)
		save->_previous = alist;
}

void				AList::deleteNode()
{
	if (this == AList::_head)
	{
		AList::_head = this->_next;
		if (this->_next)
			this->_next->_previous = NULL;
	}
	else
	{
		if (this->_previous)
			this->_previous->_next = this->_next;
		if (this->_next)
			this->_next->_previous = this->_previous;
	}
}

