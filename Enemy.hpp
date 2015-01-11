#ifndef ENEMY_HPP
# define ENEMY_HPP
# include "ACharacter.hpp"
# include "MoveController.hpp"

class Enemy : public ACharacter
{
	public:
		Enemy(int x, int y, std::string pattern, Sprite const & sprt);
		Enemy(Enemy const & src);
		virtual ~Enemy( void );
		Enemy &	operator=(Enemy const & rhs);

		Pattern &		getPattern(void) const;

		virtual void		collidesWith(Enemy & enemy);
		virtual void		collidesWith(Enemy & enemy);
		virtual void		collidesWith(Enemy & enemy);

		virtual void		refresh(void);

	protected:
		Pattern			_pattern;
		MoveController	_moveCtrl;

	private:
		Enemy(void);
};

#endif /* ENEMY_HPP */
