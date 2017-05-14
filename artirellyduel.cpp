
#include "artirellyduel.hpp"

#include "resources.hpp"
#include <stdlib.h>

ArtirellyDuel::ArtirellyDuel() :
    Widget(NULL, 0, 0, 0, 640, 480),
    _ground(this, __IDC__GROUND, 0, 0),
    _player1(this, __IDC__PLAYER1, 0),
    _player2(this, __IDC__PLAYER2, 1),
    _toolbar(this, __IDC__TOOLBAR, 0, 400) {
    gout.open(640, 480);
    _ground.add(_widgets);
    _toolbar.add(_widgets);
    _player1.add(_widgets);
    _player2.add(_widgets);
    initialize();
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
            _widgets[focus]->handle(NULL, 0, ev);
        }

        // draw
        for (size_t i = 0; i < _widgets.size(); i++) {
            _widgets[i]->draw();
        }

        gout << refresh;
    }
}

void ArtirellyDuel::updateToolbar() {
    _toolbar._spinButtonPower.setCurrentValue(_currentPlayer->getPower());
    _toolbar._spinButtonAngle.setCurrentValue(_currentPlayer->getAngle());
}


void ArtirellyDuel::initialize() {
  int positionX = 0;
  int positionY = 0;

  // initialize area
  _ground.initialize();

  // generate player1 position
  positionX = (rand() % 100) + _player1.getSizeX();
  positionY = _ground.smooth(positionX, _player1.getSizeX() / 2);
  _player1.setPositionX(positionX - (_player1.getSizeX() / 2));
  _player1.setPositionY(_ground.getSizeY() - (positionY + _player1.getSizeY()));
  _player1.setAngle(20);

  // generate player2 position
  positionX = _ground.getSizeX() - ((rand() % 100) + _player2.getSizeX());
  positionY = _ground.smooth(positionX, _player2.getSizeX() / 2);
  _player2.setPositionX(positionX - (_player2.getSizeX() / 2));
  _player2.setPositionY(_ground.getSizeY() - (positionY + _player2.getSizeY()));
  _player2.setAngle(20);

  // set initial state
  if ((rand() % 2) == 0) {
    _state = PLAYER1_SETUP;
  } else {
    _state = PLAYER2_SETUP;
  }

  event ev = { 0, 0, 0, 0, 0, 0};
  handle(NULL, 0, ev);
}

void ArtirellyDuel::handle(Widget * widget, int code, event ev) {
    if (widget != NULL) {
printf("WIDGET %d %d\n", widget->getId(), code);
        switch (widget->getId()) {
        case __IDC__TOOLBAR__BUTTON__NEW_GAME : {
            switch (code) {
            case __MESSAGE__OnClick : {
              initialize();
              break;
            }
            }
            break;
        }
        case __IDC__TOOLBAR__SPINBUTTON__ANGLE : {
            SpinButton * spinButton = (SpinButton *)widget;
            _currentPlayer->setAngle(spinButton->getCurrentValue());
            break;
        }
        case __IDC__TOOLBAR__SPINBUTTON__POWER : {
            SpinButton * spinButton = (SpinButton *)widget;
            _currentPlayer->setPower(spinButton->getCurrentValue());
            break;
        }
        }
    }

printf("STATE : %d\n", _state);

    switch (_state) {
    case PLAYER1_SETUP : {
        _currentPlayer = &_player1;
        _player1.setSelected(true);
        _player2.setSelected(false);

        if (widget != NULL) {
            switch (widget->getId()) {
            case __IDC__TOOLBAR__BUTTON__PASS: {
                switch (code) {
                case __MESSAGE__OnClick : {
                  _state = PLAYER2_SETUP;
                  break;
                }
                }
                break;
            }
            }
        }
        break;
    }
    case PLAYER1_SHOT: {
        break;
    }
    case PLAYER2_SETUP : {
        _currentPlayer = &_player2;
        _player1.setSelected(false);
        _player2.setSelected(true);

        if (widget != NULL) {
            switch (widget->getId()) {
            case __IDC__TOOLBAR__BUTTON__PASS: {
                switch (code) {
                case __MESSAGE__OnClick : {
                  _state = PLAYER1_SETUP;
                  break;
                }
                }
                break;
            }
            }
        }
        break;
    }
    case PLAYER2_SHOT: {
        break;
    }
    case GAME_OVER : {
        break;
    }
    }

    updateToolbar();
}
