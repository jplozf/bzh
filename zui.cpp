#include "zui.h"

//*****************************************************************************
// ZApplication()
//*****************************************************************************
ZApplication::ZApplication() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  getmaxyx(stdscr, maxrow, maxcol);

  this->mainWindow = newwin(maxrow, maxcol, 0, 0);
}

//*****************************************************************************
// ~ZApplication()
//*****************************************************************************
ZApplication::~ZApplication() {
  endwin();
}

//****************************************************************************
// ZTitle()
//*****************************************************************************
ZTitle::ZTitle(ZBoard *parent)
{
  this->parent = parent;

  field[0] = new_field(1, 8, 0, 0, 0, 0);  // DATE
  field[1] = new_field(1, 64, 0, 8, 0, 0); // TITLE
  field[2] = new_field(1, 8, 0, 72, 0, 0); // HOUR

  for (int i = 0; i < 3; ++i) {
      field_opts_off(field[i], O_STATIC);
      set_field_opts(field[i], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
  }
  this->form = new_form(field);
}

//****************************************************************************
// ~ZTitle()
//*****************************************************************************
ZTitle::~ZTitle() {}

//****************************************************************************
// setTitle()
//*****************************************************************************
void ZTitle::setTitle(QString title)
{
  this->title = title;
  this->refresh();
}

//****************************************************************************
// refresh()
//*****************************************************************************
void ZTitle::refresh()
{
  QDateTime datetime = QDateTime::currentDateTime();
  QString sDate = datetime.toString("dd/MM/yy");
  QString sHour = datetime.toString("hh:mm:ss");
  set_field_buffer(this->field[0], 0, sDate.toStdString().c_str());
  set_field_buffer(this->field[1], 0, this->title.toStdString().c_str());
  set_field_buffer(this->field[2], 0, sHour.toStdString().c_str());
  post_form(this->form);
  refresh();
}
//****************************************************************************
// ZBoard()
//*****************************************************************************
ZBoard::ZBoard(ZApplication *parent)
{
  this->parent = parent;
  this->zTitle = new ZTitle(this);
  this->zTitle.setTitle("");
}

//****************************************************************************
// ZBoard()
//*****************************************************************************
ZBoard::ZBoard(ZApplication *parent, QString title)
{
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
