#ifndef ENEMYSPAWNER_HPP
# define ENEMYSPAWNER_HPP

# include <string>
# include <cstdlib>
# include "Enemy.hpp"
# include "Window.hpp"

class EnemySpawner
{
	public:
		EnemySpawner( Window const & win );
		EnemySpawner(EnemySpawner const & src);
		~EnemySpawner( void );
		EnemySpawner &	operator=(EnemySpawner const & rhs);

		void			refresh(void);

	private:
		int				_winwdth;
		int				_winhgt;
		int				_speed;
		int				_maxspeed;
		std::string		_pattern[];
};

#endif /* ENEMYSPAWNER_HPP */
