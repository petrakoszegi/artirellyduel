#ifndef ARTIRELLYDUEL_HPP_INCLUDED
#define ARTIRELLYDUEL_HPP_INCLUDED

#include <vector>

#include "widget.hpp"

using namespace std;

class ArtirellyDuel : public Widget {
protected:
    vector<Widget *> widgets;

public:
    ArtirellyDuel();

    // run game
    void run();

//  virtual void draw() const ;
  //virtual void handle(Widget * source, int message, event ev);
};

#endif // BUTTON_HPP_INCLUDED

