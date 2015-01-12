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

		char				getStatus() const;
		void				refresh();

	private:
		char				_status;
		void				_refreshGameEntity();
		void				_deathCheck();
		void				_isQuit();
		void				_isOver();
		Player				_player;
		EnemySpawner		_spawner;

};

#endif /* GAME_HPP */
