#ifndef TOOLBARD_HPP_INCLUDED
#define TOOLBARD_HPP_INCLUDED

#include "widget.hpp"
#include "button.hpp"

class Toolbar : public Widget {
protected:
    Button _buttonNewGame;

public:
    Toolbar(Widget * parent, int id, int x, int y);

    virtual void add(vector<Widget *> & widgets);
};

#endif // TOOLBARD_HPP_INCLUDED



