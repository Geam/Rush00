#ifndef DISPLAY_SPRITE_H_H
# define DISPLAY_SPRITE_H_H

#include <iostream>
#include <ncurses.h>
#include "Position.hpp"

// temp
struct Sprite {
    std::string     *tempT;
    int             tempW;
    int             tempH;
};
// endtemp

class DisplaySprite {
public:

    // constructor and destructor
    DisplaySprite(void);
    DisplaySprite(DisplaySprite const &src);
    ~DisplaySprite(void);

    //setters and getters

    // methods
    DisplaySprite  &operator=(DisplaySprite const &rhs);

    void        display(int c, Position p, int color);
    void        display(int c, Position p, int color, WINDOW *window);
    void        display(Sprite s, Position p, int color);
    void        display(Sprite s, Position p, int color, WINDOW *window);
    void        display(std::string str, Position p, int color);
    void        display(std::string str, Position p, int color, WINDOW *window);
    void        erase(Position p);
    void        erase(Position p, WINDOW *window);
    void        erase(Sprite s, Position p);
    void        erase(Sprite s, Position p, WINDOW *window);
    static int  _instanceNb;

private:

    static bool _VERBOSE;
};

std::ostream    &operator<<(std::ostream &o, DisplaySprite const &i);

#endif /* DISPLAY_SPRITE_H_H */




