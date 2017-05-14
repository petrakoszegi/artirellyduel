#ifndef ARTIRELLY_HPP_INCLUDED
#define ARTIRELLY_HPP_INCLUDED

#include "widget.hpp"

class Artirelly : public Widget {
protected:
    int _angle;
    int _power;

public:
    Artirelly(Widget * parent, int id);

    virtual void draw() const;

    int getAngle() const;
    void setAngle(int angle);
    int getPower() const;
    void setPower(int power);
};

#endif // ARTIRELLY_HPP_INCLUDED
