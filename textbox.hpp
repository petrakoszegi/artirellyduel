#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include <string>
#include "graphics.hpp"
#include "widget.hpp"

using namespace std;

class TextBox : public Widget {
protected:
    string _text;
	bool _edit;

public:
    TextBox(Widget * parent, int id, int x, int y, int sizeX, int sizeY);
    virtual void draw() const ;
    virtual void handle(Widget * widget, int code, event ev);

  const string & getText() const;
  void setText(const string & s);
  void setEdit(bool edit);
};


#endif // TEXTBOX_HPP_INCLUDED
