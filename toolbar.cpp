
#include "toolbar.hpp"

#include "resources.hpp"

Toolbar::Toolbar(Widget * parent, int id, int x, int y) :
    Widget(parent, id, x, y, 640, 80),
    _buttonNewGame(this, __IDC__TOOLBAR__BUTTON__NEW_GAME, 550 + x, 10 + y, 80, 30, "new game") {
}

void Toolbar::add(vector<Widget *> & widgets) {
  widgets.push_back(this);
  widgets.push_back(&_buttonNewGame);
}
