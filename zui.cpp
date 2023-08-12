#include "zui.h"

//*****************************************************************************
// ZApplication()
//*****************************************************************************
ZApplication::ZApplication() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  getmaxxy(stdscr, maxrow, maxcol);

  this->mainWindow = newwin(maxrow, maxcol, 0, 0);
}

//*****************************************************************************
// ~ZApplication()
//*****************************************************************************
ZApplication::~ZApplication() {
  endwin();
}

//****************************************************************************
// ZBoard()
//*****************************************************************************
ZBoard::ZBoard(ZApplication parent) {
    this->parent = parent;
    this->zTitle = new ZTitle(this);
    this->zTitle.setTitle("");
}

//****************************************************************************
// ZBoard()
//*****************************************************************************
ZBoard::ZBoard(ZApplication parent, QString title) {
    this->parent = parent;
    this->zTitle = new ZTitle(this);
    this->zTitle.setTitle("");
}

//****************************************************************************
// ~ZBoard()
//*****************************************************************************
ZBoard::~ZBoard() {

}

//****************************************************************************
// setTitle()
//*****************************************************************************
void ZBoard::setTitle(QString title) {
    this->zTitle.setTitle(title);
}

//****************************************************************************
// ZTitle()
//*****************************************************************************
ZTitle::ZTitle(ZBoard parent) {
    this->parent = parent;
    FIELD *field[3];

    field[0] = new_field(1, 8, 0, 0);       // DATE
    field[1] = new_field(1, 64, 0, 0);      // TITLE
    field[2] = new_field(1, 8, 0, 0);       // HOUR

    FIELD fdDate = *new_field(1, label.length(), x, y, 0, 0);
    field_opts_off(&this->field, O_STATIC);
    set_field_opts(&this->field, O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_buffer(&this->field, 0, label.toStdString().c_str());
}

//****************************************************************************
// ~ZTitle()
//*****************************************************************************
ZTitle::~ZTitle() {

}

//****************************************************************************
// setTitle()
//*****************************************************************************
void ZTitle::setTitle(QString title) {
    this->title = title;
    this->refresh();
}

//****************************************************************************
// refresh()
//*****************************************************************************
void ZTitle::refresh() {

}
/*
int ZMain() {
    ZApplication app = ZApplication();
    ZScreen mainScreen = ZScreen();
    ZInput txtPrompt = ZInput();
    mainScreen.addField(txtPrompt);
    app->start(mainScreen);

    return 0;
}
*/
