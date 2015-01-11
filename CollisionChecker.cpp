
#include "CollisionChecker.hpp"

void			CollisionChecker::checkCollision(AGameEntity & alist1, AGameEntity & alist2)
{
	if (alist1.getPosition() == alist2.getPosition())
	{
		// do;
	}
	int x1 = alist1.getPosition().getX();
	int y1 = alist1.getPosition().getY();
	int x2 = alist2.getPosition().getX();
	int y2 = alist2.getPosition().getY();

	int w1 = alist1.getHitbox().getWidth();
	int w2 = alist2.getHitbox().getWidth();
	int h1 = alist1.getHitbox().getHeight();
	int h2 = alist2.getHitbox().getHeight();

	if (((x2 >= x1 && x2 <= x1 + w1)
		|| (x2 >= x1 && x2 + w2 <= x1 + w1))
		&& ((y2 >= y1 && y2 <= y1 + h1)
		|| (y2 >= y1 && y2 + h2 <= y1 + h1)))
		;//do
	return ;
}

void			CollisionChecker::checkCollision(AList & alist1, AList  & alist2)
{
	std::cout << "Something's wrong in CollisionChecker." << std::endl;
	return ;
}

void			CollisionChecker::checkCollision(AList & alist)
{
	AList *current = &alist;
	if (!current || current->getNext() == NULL)
		return ;
	while (current = current->getNext())
		CollisionChecker::checkCollision(alist, *(current->getNext()));
	CollisionChecker::checkCollision(*(alist.getNext()));
}


CollisionChecker::CollisionChecker( void )
{
	return ;
}

CollisionChecker::CollisionChecker(CollisionChecker const & src)
{
	return ;
}

CollisionChecker &	CollisionChecker::operator=(CollisionChecker const & rhs)
{
	return *this;
}

CollisionChecker::~CollisionChecker( void )
{
	return ;
}

