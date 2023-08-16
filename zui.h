//*****************************************************************************
//
//    Ladies & Gentlemen, here is
//        _______    ________
//       |___  / |  | |_   _|
//          / /| |  | | | |
//         / / | |  | | | |
//        / /__| |__| |_| |_
//       /_____|\____/|_____|
//
//   A Simple NCurses UI Framework
//     Copyright jpl@ozf.fr 2023
//
//*****************************************************************************

#ifndef ZUI_H
#define ZUI_H

#include <QDateTime>
#include <QMap>
#include <QString>
#include <QUuid>
#include "ncurses/form.h"
#include "ncurses/ncurses.h"

//*****************************************************************************
// Forward declarations
//*****************************************************************************
class ZApplication;
class ZBoard;
class ZTitle;
class ZHeader;
class ZRows;
class ZRow;
class ZPrompt;
class ZFooter;
class ZStatusbar;

//*****************************************************************************
// Class ZApplication
//*****************************************************************************
class ZApplication {
private:
    FORM *form;
    WINDOW *mainWindow;
    int maxrow;
    int maxcol;

public:
    ZApplication();
    ~ZApplication();
};

//*****************************************************************************
// Class ZTitle
//*****************************************************************************
class ZTitle {
private:
    ZBoard *parent;
    bool withDate{true};
    bool withClock{true};
    QString title;
    void refresh();
    FIELD *field[3];

public:
    ZTitle(ZBoard *parent);
    void setTitle(QString title);
    void showDate(bool flag);
    void showClock(bool flag);
    ~ZTitle();

};

//*****************************************************************************
// Class ZBoard
//*****************************************************************************
class ZBoard {
private:
    ZTitle zTitle;
    ZHeader zHeader;
    ZPrompt zPrompt;
    ZRows zRows;
    ZFooter zFooter;
    ZStatusbar zStatusbar;
    ZApplication *parent;

public:
    ZBoard(ZApplication *parent);
    ZBoard(ZApplication *parent, QString title);
    void setTitle(QString title);
    void show();

    ~ZBoard();

};
#endif // ZUI_H
