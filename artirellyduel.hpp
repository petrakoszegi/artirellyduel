#ifndef ARTIRELLYDUEL_HPP_INCLUDED
#define ARTIRELLYDUEL_HPP_INCLUDED

#include <vector>

#include "widget.hpp"
#include "ground.hpp"
#include "toolbar.hpp"

using namespace std;

class ArtirellyDuel : public Widget {
protected:
    vector<Widget *> _widgets;

    Ground _ground;
    Toolbar _toolbar;

public:
    ArtirellyDuel();

    // run game
    void run();

//  virtual void draw() const ;
    virtual void handle(event ev);
};

#endif // BUTTON_HPP_INCLUDED

