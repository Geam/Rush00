#include <iostream>
#include <ncurses.h>
#include "DisplaySprite.hpp"

bool    DisplaySprite::_VERBOSE = false;
int     DisplaySprite::_instanceNb = 0;

// constructor and destructor
DisplaySprite::DisplaySprite(void) {
    if (DisplaySprite::_VERBOSE) {
        std::cout << "\033[35mDisplaySprite Default constructor\033[0m";
    }
    DisplaySprite::_instanceNb++;
}

DisplaySprite::DisplaySprite(DisplaySprite const &src) {
    *this = src;

    if (DisplaySprite::_VERBOSE) {
        std::cout << "\033[33mDisplaySprite Copy constructor\033[0m";
    }
    DisplaySprite::_instanceNb++;
}

DisplaySprite::~DisplaySprite(void) {
    if (DisplaySprite::_VERBOSE) {
        std::cout << "\033[31mDisplaySprite Destructor\033[0m";
    }
}

//setters and getters

// overload
DisplaySprite  &DisplaySprite::operator=(DisplaySprite const &rhs) {
    (void) rhs;
    return *this;
}
std::ostream    &operator<<(std::ostream &o, DisplaySprite const &i) {
    (void) i;
    o << "#" << DisplaySprite::_instanceNb << std::endl;
    return o;
}

// methods

void       DisplaySprite::erase(Sprite s, Pos p) {
    attron(COLOR_PAIR(1));
    for (int i = 0; i < s.tempH; i++) {
        mvprintw(p.tempY + i, p.tempX, s.tempT[i].c_str());
    }
    attroff(COLOR_PAIR(1));
}

void       DisplaySprite::display(Sprite s, Pos p, int color) {
    attron(COLOR_PAIR(color));
    for (int i = 0; i < s.tempH; i++) {
        mvprintw(p.tempY + i, p.tempX, s.tempT[i].c_str());
    }
    attroff(COLOR_PAIR(color));
}

void       DisplaySprite::erase(Pos p) {
    attron(COLOR_PAIR(1));
    mvaddch(p.tempY, p.tempX, ' ');
    attroff(COLOR_PAIR(1));
}

void    DisplaySprite::display(int c, Pos p, int color) {
    attron(COLOR_PAIR(color));
    mvaddch(p.tempY, p.tempX, c);
    attroff(COLOR_PAIR(color));
}
