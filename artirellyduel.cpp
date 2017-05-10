
#include "artirellyduel.hpp"

ArtirellyDuel::ArtirellyDuel() :
    Widget(NULL, 0, 0, 0, 640, 480) {
    gout.open(640, 480);
}

void ArtirellyDuel::run() {
    event ev;
    int focus = -1;

    while (gin >> ev) {
        if ((ev.type == ev_mouse) && (ev.button == btn_left)) {
            for (size_t i = 0; i < widgets.size(); i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        widgets[i]->setFocus(true);
                        focus = i;
                } else {
                        widgets[i]->setFocus(false);
                }
            }
        }
        if (focus != -1) {
            widgets[focus]->handle(ev);
        }

        // draw
        for (size_t i = 0; i < widgets.size(); i++) {
            widgets[i]->draw();
        }

        gout << refresh;
    }
}
