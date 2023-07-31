#ifndef ZLABEL_H
#define ZLABEL_H

#include <stdio.h>
#include <stdlib.h>
#include "ncurses/ncurses.h"
#include "ncurses/form.h"
#include "ZScreen.h"

class ZLabel
{
private:
    int pos;
    FIELD *field;
    ZScreen *screen;
public:
    ZLabel(ZScreen *screen, QString label, int x, int y);
    ~ZLabel();
    void setText(QString label);
};

#endif  // ZLABEL_H