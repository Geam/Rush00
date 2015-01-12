#ifndef DISPLAY_SPRITE_H_H
# define DISPLAY_SPRITE_H_H

# include <iostream>
# include <ncurses.h>
# include "Position.hpp"
# include "Sprite.hpp"

class DisplaySprite {
public:

    // constructor and destructor
    DisplaySprite(void);
    DisplaySprite(DisplaySprite const &src);
    ~DisplaySprite(void);

    //setters and getters

    // methods
    DisplaySprite  &operator=(DisplaySprite const &rhs);

    static void        display(int c, Position p, int color);
    static void        display(int c, Position p, int color, WINDOW *window);
    static void        display(Sprite s, Position p, int color);
    static void        display(Sprite s, Position p, int color, WINDOW *window);
    static void        display(std::string str, Position p, int color);
    static void        display(std::string str, Position p, int color, WINDOW *window);
    static void        erase(Position p);
    static void        erase(Position p, WINDOW *window);
    static void        erase(Sprite s, Position p);
    static void        erase(Sprite s, Position p, WINDOW *window);
    static int  _instanceNb;

private:

    static bool _VERBOSE;

};

std::ostream    &operator<<(std::ostream &o, DisplaySprite const &i);

#endif /* DISPLAY_SPRITE_H_H */




