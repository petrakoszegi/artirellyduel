
#include "ground.hpp"

#include <stdlib.h>

#include <stdio.h>

void Ground::generateAltitudes(int min, int max) {
   if ((max - min) == 1) {
     // ..
   } else {
     int p = (rand() % (max - min - 1)) + min + 1;
     int delta = (max - min) / 4;

     _altitudes[p] = ((_altitudes[min] + _altitudes[max]) / 2) - delta + (rand() % ((2 * delta) + 1));
     if (_altitudes[p] < 50) {
       _altitudes[p] = 50;
     }

     generateAltitudes(min, p);
     generateAltitudes(p, max);
   }
}

Ground::Ground(Widget * parent, int id, int x, int y) :
    Widget(parent, id, x, y, 640, 400) {
}

void Ground::draw() const {
  int x = 0;

  gout << color(0, 0, 180);
  gout << move_to(0, 0) << box(640, 400);

  gout << color(240, 200, 30);
//  gout << line_to(_x + x, _y + 400 - _altitudes[x]);
  for (x = 0; x < 640; x++) {
    gout << move_to(_x + x, _y + 399) << line_to(_x + x, _y + 399 - _altitudes[x]);
  }
}

void Ground::initialize() {
    _altitudes[0] = (rand() % 150) + 50;
    _altitudes[639] = (rand() % 150) + 50;

    generateAltitudes(0, 639);
}


int Ground::smooth(int x, int e) {
  int m = _altitudes[x];
  int i = 0;

  for (i = (x - e); i < (x + e); i++) {
    if (_altitudes[i] < m) {
      m = _altitudes[i];
    }
  }

  for (i = (x - e); i < (x + e); i++) {
    _altitudes[i] = m;
  }

  return (m);
}
