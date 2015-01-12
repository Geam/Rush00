
#include "EnemySpawner.hpp"

EnemySpawner::EnemySpawner( void ) : _pattern(NULL)
{
	std::string		*tpattern = new std::string[1];
	std::srand(time(0));

	tpattern[0] = "3";
	this->_pattern = tpattern;
	std::cout << "[CONSTRUCT] EnemySpawner" << std::endl;
	return ;
}

EnemySpawner::EnemySpawner(EnemySpawner const & src)
{
	*this = src;
	return ;
}

EnemySpawner::~EnemySpawner( void )
{
	std::cout << "[DESTRUCT] EnemySpawner" << std::endl;
	delete [] this->_pattern;
}

void			EnemySpawner::setWindow( Window const & win)
{
	this->_winwdth = win.getH();
	this->_winhgt = win.getW();
	return ;
}

EnemySpawner &	EnemySpawner::operator=(EnemySpawner const & rhs)
{
	this->_winwdth = rhs._winwdth;
	this->_winhgt = rhs._winhgt;
	this->_speed = rhs._speed;
	this->_maxspeed = rhs._maxspeed;
	return *this;
}

Enemy const &		EnemySpawner::refresh(void)
{
	Enemy *	tmp = NULL;

	if (this->_speed == 0)
	{
		this->_speed = this->_maxspeed;
		if (Enemy::enemyCount < 10)
		{
			tmp = new Enemy(this->_winwdth, (std::rand() %
					(this->_winhgt - 2)) + 1, 10, 15, "3");
		}
	}
	else
		this->_speed--;
	return *tmp;
}
