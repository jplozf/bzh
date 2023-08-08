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
    /* data */
public:
    ZInput(/* args */);
    ~ZInput();

};

#endif // ZUI_H
