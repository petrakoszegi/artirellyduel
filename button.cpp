#include "button.hpp"

#include <stdio.h>

Button::Button(Widget * parent, int id, int x, int y, int sx, int sy, const char * caption)
    : Widget(parent, id, x + 2, y + 2, sx - 4, sy - 4) {
  _caption = caption;
}

void Button::draw() const {
    Widget::draw();
    gout << move_to(_x + ((_size_x - gout.twidth(_caption))/ 2), _y + (_size_y / 2) + 5) << ((_disabled == false) ? color(255,255,255) : color(192,192,192)) << text(_caption);
}

void Button::handle(event ev) {
  if (_disabled == false) {
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
      ev.widget = this;
      ev.code = __MESSAGE__OnClick;
      Widget::handle(ev);
    }
    if ((ev.type == ev_mouse) && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
      ev.widget = this;
      ev.code = __MESSAGE__OnClick;
      Widget::handle(ev);
    }
  }

  Widget::handle(ev);
}
