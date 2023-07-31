#ifndef ZAPPLICATION_H
#define ZAPPLICATION_H

#include "ncurses/ncurses.h"
#include "ncurses/form.h"
#include "ZScreen.h"

class ZApplication
{
private:
    ZScreen *screen;

public:
    ZApplication(/* args */);
    ~ZApplication();
};

#endif  // ZAPPLICATION_H