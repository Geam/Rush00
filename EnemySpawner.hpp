#ifndef ENEMYSPAWNER_HPP
# define ENEMYSPAWNER_HPP

class EnemySpawner
{
	public:
		EnemySpawner( void );
		EnemySpawner(EnemySpawner const & src);
		~EnemySpawner( void );
		EnemySpawner &	operator=(EnemySpawner const & rhs);

		void			refresh(void);

	private:
		int				_speed;
		int				_maxspeed;
		std::string		_pattern[];
};

#endif /* ENEMYSPAWNER_HPP */
