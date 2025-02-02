#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include <string>

#include "graphics.hpp"
#include "widget.hpp"

using namespace std;

class Button : public Widget {
protected:
  string _caption;

public:
  Button(Widget * parent, int id, int x, int y, int sx, int sy, const char * caption);
  virtual void draw() const ;
  virtual void handle(Widget * widget, int code, event ev);
};


#endif // BUTTON_HPP_INCLUDED
