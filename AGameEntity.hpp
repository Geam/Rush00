#ifndef AGAMEENTITY_HPP
# define AGAMEENTITY_HPP

# include <iostream>
# include <sstream>
# include "Console.hpp"
# include "Position.hpp"
# include "Hitbox.hpp"
# include "Sprite.hpp"
# include "DisplaySprite.hpp"

class AGameEntity
{
	public:
		AGameEntity(int x, int y, int spe);
		AGameEntity(AGameEntity const & src);
		virtual ~AGameEntity( void );

		AGameEntity &			operator=(AGameEntity const & rhs);

		Position const &		getPosition(void) const;
		Hitbox const &			getHitbox(void) const;
		Sprite const &			getSprite(void) const;
		int						getSpeed() const;
		int						isDead() const;

		virtual void			refresh() = 0;
		virtual void			collidesWith(AGameEntity const & ge);

		virtual AGameEntity		*getNext() const;
		virtual AGameEntity		*getPrevious() const;
		static AGameEntity		*getHead();
		static void				pushFront(AGameEntity *alist);
		static void				setWindow(WINDOW *window);
		void					deleteNode();
		std::string				toString(void) const;

	protected:
		Position				_pos;
		Hitbox					_hb;
		Sprite					_sp;
		AGameEntity				*_next;
		AGameEntity				*_previous;
		int						_speed;
		int						_maxspeed;
		int						_dead;
		int						_index;
		static AGameEntity		*_head;
		static WINDOW			*_window;
		AGameEntity( void );

	private:
		static unsigned int		_nb_inst;
		static unsigned int		_nb_node;
};

std::ostream &					operator<<(std::ostream & o, AGameEntity const & rhs);

#endif /* AGAMEENTITY_HPP */
