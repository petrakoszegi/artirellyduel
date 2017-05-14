
#include "artirelly.hpp"

#include "resources.hpp"
#include <math.h>

Artirelly::Artirelly(Widget * parent, int id, int direction) :
    Widget(parent, id, 0, 0, __ARTIRELLY_SIZE_X, __ARTIRELLY_SIZE_Y) {
  _angle = 0;
  _power = __ARTIRELLY_POWER_MIN;
  _direction = direction;
}

void Artirelly::draw() const {
  double vx = 0;
  double vy = 0;
  double positionX = 0;
  double positionY = 0;
  int i = 0;
  int angle = 0;

  if (_selected == true) {
    gout << color(140, 200, 120);
  } else {
    gout << color(140, 140, 120);
  }
  gout << move_to(_x, _y) << box(_size_x, _size_y);

  gout << color(80, 80, 80);
  gout << move_to(_x + (_size_x / 2) - (_size_x / 6), _y - (_size_y / 2)) << box(2 * (_size_x / 6), _size_y / 2);
  angle = _angle;
  if (_direction == 1) {
    angle = 180 - angle;
  }
  vx = cos(((double)angle / 180.0) * 3.14159265) * __ARTIRELLY_BARREL_LENGTH;
  vy = sin(((double)angle / 180.0) * 3.14159265) * __ARTIRELLY_BARREL_LENGTH;

  gout << color(80, 80, 80);
  positionX = _x + (_size_x / 2);
  positionY = _y - (_size_y / 2);
  for (i = 0; i < __ARTIRELLY_BARREL_LENGTH; i++) {
    gout << move_to(positionX - 1 , positionY - 1) << box(3, 3);
    positionX = positionX + (vx / __ARTIRELLY_BARREL_LENGTH);
    positionY = positionY - (vy / __ARTIRELLY_BARREL_LENGTH);
  }


}

int Artirelly::getAngle() const {
    return (_angle);
}

void Artirelly::setAngle(int angle) {
    _angle = angle;
}

int Artirelly::getPower() const {
    return (_power);
}

void Artirelly::setPower(int power) {
    _power = power;
}
