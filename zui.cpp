#include "zui.h"

//*****************************************************************************
// ZApplication()
//*****************************************************************************
ZApplication::ZApplication(ZScreen *screen) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  this->mainWindow = newwin(24, 80, 0, 0);

  this->setScreen(screen);
}

//*****************************************************************************
// ~ZApplication()
//*****************************************************************************
ZApplication::~ZApplication() {
  endwin();
}

//*****************************************************************************
// setScreen()
//*****************************************************************************
void ZApplication::setScreen(ZScreen *screen) {
  this->screen = screen;
}

//*****************************************************************************
// ZLabel()
//*****************************************************************************
ZLabel::ZLabel(ZScreen *screen, QString label, int x, int y) {
  this->screen = screen;
  this->field = *new_field(1, label.length(), x, y, 0, 0);
  field_opts_off(&this->field, O_STATIC);
  set_field_opts(&this->field, O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
  set_field_buffer(&this->field, 0, label.toStdString().c_str());
  this->key = QUuid::createUuid().toString();
}

//*****************************************************************************
// ~ZLabel()
//*****************************************************************************
ZLabel::~ZLabel() {
  screen->fields.remove(this->key);
  free_field(&this->field);
}

//****************************************************************************
// setText()
//*****************************************************************************
void ZLabel::setText(QString label) {
  set_field_buffer(&this->field, 0, label.toStdString().c_str());
  set_field_buffer(&this->screen->fields[this->key], 0,
                   label.toStdString().c_str());
}

//****************************************************************************
// ZScreen()
//*****************************************************************************
ZScreen::ZScreen(WINDOW *parent) { this->parent = parent; }

//****************************************************************************
// ~ZScreen()
//*****************************************************************************
ZScreen::~ZScreen() {}

//*****************************************************************************
// show()
//*****************************************************************************
void ZScreen::show() {
  int n = this->fields.count();
  int i{0};
  aFields = (FIELD *)malloc(n * sizeof(FIELD));
  for (auto e : this->fields.keys()) {
    aFields[i++] = this->fields.value(e);
  }
  this->form = new_form(&aFields);
  set_form_win(this->form, this->parent);
  post_form(this->form);
  refresh();
  wrefresh(this->parent);
}

/*
//*****************************************************************************
// addLabel()
//*****************************************************************************
void ZScreen::addLabel(ZLabel label) {
  this->fields[label.key] = label.field;
}
*/

//****************************************************************************
// ZInput()
//*****************************************************************************
ZInput::ZInput(/* args */) {

}

//****************************************************************************
// ~ZInput()
//*****************************************************************************
ZInput::~ZInput() {

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
