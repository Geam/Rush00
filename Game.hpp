#ifndef GAME_HPP
# define GAME_HPP

# include "Player.hpp"
# include "CollisionChecker.hpp"
# include "EnemySpawner.hpp"

class Game
{
	public:
		Game( void );
		Game( Window const & win );
		Game(Game const & src);
		~Game( void );
		Game &	operator=(Game const & rhs);

		void				refresh();

	private:
		void				_refreshGameEntity();
		void				_deathCheck();
		void				_isQuit();
		void				_isOver();
		void				_getInput();
		Player				_player;
		EnemySpawner		_spawner;

};

#endif /* GAME_HPP */
