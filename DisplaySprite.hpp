#ifndef DISPLAY_SPRITE_H_H
# define DISPLAY_SPRITE_H_H

#include <iostream>
#include <ncurses.h>

// temp
struct Sprite {
    std::string     *tempT;
    int             tempW;
    int             tempH;
};
struct Pos {
    int             tempX;
    int             tempY;
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

    void        display(Sprite s, Pos p, int color);
    void        display(int c, Pos p, int color);
    void        erase(Pos p);
    void        erase(Sprite s, Pos p);
    static int  _instanceNb;

private:

    static bool _VERBOSE;
};

std::ostream    &operator<<(std::ostream &o, DisplaySprite const &i);

#endif /* DISPLAY_SPRITE_H_H */

//DisplaySprite(Sprite sprite, Pos xy)



