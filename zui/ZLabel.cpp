#include "ZLabel.h"

//*****************************************************************************
// ZLabel()
//*****************************************************************************
ZLabel::ZLabel(ZScreen *screen, QString label, int x, int y) {
    this->screen = screen;
    this->field = new_field(1, label.length(), x, y, 0, 0);
    field_opts_off(this->field, O_STATIC);
    set_field_opts(this->field, O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_buffer(this->field, 0, label.toStdString());
    int i = 0;
    if (screen->fields != NULL) {
        i = sizeof(screen->fields) / sizeof(screen->fields[0]) + 1;
        screen->fields = (FIELD *)realloc(screen->fields, i * sizeof(FIELD));
    } else {
        i = 1;
        screen->fields = (FIELD *)realloc(screen->fields, sizeof(FIELD));
    }
    screen->fields[i - 1] = *this->field;
    this->pos = i;
}

//*****************************************************************************
// ~ZLabel()
//*****************************************************************************
ZLabel::~ZLabel() {
    int i = 0;
    int size = sizeof(this->screen->fields) / sizeof(this->screen->fields[0]);
    for (i = this->pos - 1; i < size - 1; i++) {
        this->screen->fields[i] = this->screen->fields[i + 1];
    }
    size--;
    this->screen->fields = (FIELD *)realloc(this->screen->fields, size * sizeof(FIELD));
    free_field(this->field);
}


//*****************************************************************************
// setText()
//*****************************************************************************
void ZLabel::setText(QString label) {
    set_field_buffer(this->field, 0, label.toStdString());
    set_field_buffer(&this->screen->fields[this->pos], 0, label.toStdString());
}