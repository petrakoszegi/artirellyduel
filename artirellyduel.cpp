
#include "artirellyduel.hpp"

#include "resources.hpp"

ArtirellyDuel::ArtirellyDuel() :
    Widget(NULL, 0, 0, 0, 640, 480),
    _ground(this, __IDC__GROUND, 0, 0),
    _toolbar(this, __IDC__TOOLBAR, 0, 400) {
    gout.open(640, 480);

    _ground.add(_widgets);
    _toolbar.add(_widgets);
}

void ArtirellyDuel::run() {
    event ev;
    int focus = -1;

    while (gin >> ev) {
        if ((ev.type == ev_mouse) && (ev.button == btn_left)) {
            for (size_t i = 0; i < _widgets.size(); i++) {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                } else {
                        _widgets[i]->setFocus(false);
                }
            }
        }
        if (focus != -1) {
            _widgets[focus]->setFocus(true);
            _widgets[focus]->handle(ev);
        }

        // draw
        for (size_t i = 0; i < _widgets.size(); i++) {
            _widgets[i]->draw();
        }

        gout << refresh;
    }
}

void ArtirellyDuel::handle(event ev) {
    if (ev.type == ev_widget) {
        Widget * widget = (Widget *)ev.widget;

        switch (widget->getId()) {
        case __IDC__TOOLBAR__BUTTON__NEW_GAME : {
            switch (ev.code) {
            case __MESSAGE__OnClick : {
              _ground.initialize();
              break;
            }
            }
            break;
        }
        }

    }
}
