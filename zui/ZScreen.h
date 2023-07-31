#ifndef ZSCREEN_H
#define ZSCREEN_H

#include "ncurses/ncurses.h"
#include "ncurses/form.h"

class ZScreen
{
private:
    /* data */
public:
    ZScreen(/* args */);
    ~ZScreen();
    FIELD *fields;
};

#endif  // ZSCREEN_H
