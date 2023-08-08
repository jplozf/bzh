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

#include <QString>
#include <QUuid>
#include <QMap>
#include "ncurses/ncurses.h"
#include "ncurses/form.h"

//*****************************************************************************
// Forward declarations
//*****************************************************************************
class ZApplication;
class ZScreen;
class ZLabel;
class ZInput;
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
    ZScreen *screen;
    WINDOW *mainWindow;

public:
    ZApplication(ZScreen *screen);
    ~ZApplication();
    void setScreen(ZScreen *screen);
    int start();
};

//*****************************************************************************
// Class ZLabel
//*****************************************************************************
class ZLabel {
private:

public:
    QString key;
    FIELD field;
    ZScreen *screen;
    ZLabel(ZScreen *screen, QString label, int x, int y);
    ~ZLabel();
    void setText(QString label);
};

//*****************************************************************************
// Class ZScreen
//*****************************************************************************
class ZScreen {
private:
    FORM *form;
    FIELD *aFields;
    WINDOW *parent;
public:
    ZScreen(WINDOW *parent);
    ~ZScreen();
    QMap<QString, FIELD> fields;
    void addField(ZLabel label);
    void addField(ZInput input);
    void show();
};

//*****************************************************************************
// Class ZInput
//*****************************************************************************
class ZInput {
private:

public:
    ZInput(/* args */);
    ~ZInput();
};


//*****************************************************************************
// Class ZTitle
//*****************************************************************************
class ZTitle {
private:
    ZBoard parent;
public:
    ZTitle(ZBoard parent);
    setTitle(QString title);
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

public:
    ZBoard();
    ZBoard(QString title);
    void setTitle(QString title);
    void show();

    ~ZBoard();

};
#endif // ZUI_H
