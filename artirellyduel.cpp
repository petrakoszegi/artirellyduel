
#include "artirellyduel.hpp"

#define __IDC__GROUND 1

ArtirellyDuel::ArtirellyDuel() :
    Widget(NULL, 0, 0, 0, 640, 480),
    _ground(this, __IDC__GROUND, 0, 0) {
    gout.open(640, 480);

    _ground.add(_widgets);
}

void ArtirellyDuel::run() {
    event ev;
    int focus = -1;

    while (gin >> ev) {
        if ((ev.type == ev_mouse) && (ev.button == btn_left)) {
            for (size_t i = 0; i < _widgets.size(); i++) {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        _widgets[i]->setFocus(true);
                        focus = i;
                } else {
                        _widgets[i]->setFocus(false);
                }
            }
        }
        if (focus != -1) {
            _widgets[focus]->handle(ev);
        }

        // draw
        for (size_t i = 0; i < _widgets.size(); i++) {
            _widgets[i]->draw();
        }

        gout << refresh;
    }
}
