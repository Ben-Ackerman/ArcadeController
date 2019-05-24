#include "ButtonManager.h"

#define NONE 1458
int ButtonManager::kb_map[4][11] = {{KEY_Q, KEY_U, KEY_Y, KEY_3, KEY_7, KEY_SPACE, KEY_SEMICOLON, KEY_PERIOD, KEY_ENTER, KEY_ESC, KEY_ENTER},
    {KEY_R, KEY_V, KEY_Z, KEY_4, KEY_8, KEY_MINUS, KEY_LEFT, KEY_QUOTE, KEY_ENTER, KEY_ESC, KEY_ENTER},
    {KEY_S, KEY_W, KEY_1, KEY_5, KEY_9, KEY_LEFT_BRACE, KEY_TILDE, KEY_RIGHT, KEY_ENTER, KEY_ESC, KEY_ENTER},
    {KEY_T, KEY_X, KEY_2, KEY_6, KEY_0, KEY_RIGHT_BRACE, KEY_COMMA, KEY_UP, KEY_ENTER, KEY_ESC, KEY_ENTER}};

ButtonManager::ButtonManager(ControllerMode mode, int player) {
    _player = player;
    _shiftJoystick = false;
    _mode = mode;
    _pressActions[0] = actionB1P;
    _pressActions[1] = actionB2P;
    _pressActions[2] = actionB3P;
    _pressActions[3] = actionB4P;
    _pressActions[4] = actionShiftP;
    _pressActions[5] = actionB5P;
    _pressActions[6] = actionB6P;
    _pressActions[7] = actionB7P;
    _pressActions[8] = actionB8P;
    _pressActions[9] = actionB9P;
    _pressActions[10] = actionB10P;
    _releaseActions[0] = actionB1R;
    _releaseActions[1] = actionB2R;
    _releaseActions[2] = actionB3R;
    _releaseActions[3] = actionB4R;
    _releaseActions[4] = actionShiftR;
    _releaseActions[5] = actionB5R;
    _releaseActions[6] = actionB6R;
    _releaseActions[7] = actionB7R;
    _releaseActions[8] = actionB8R;
    _releaseActions[9] = actionB9R;
    _releaseActions[10] = actionB10R;
}

void ButtonManager::ChangeMode(ControllerMode mode) {
    _mode = mode;
}
bool ButtonManager::ShiftJoystick() {
    return _shiftJoystick;
}

void ButtonManager::PressButton(int button) {
    ExecuteActionPressed(_pressActions[button]);
}

void ButtonManager::ReleaseButton(int button) {
    ExecuteActionReleased(_releaseActions[button]);
}

void ButtonManager::ExecuteActionPressed(int action) {
    if(_mode == joystickMode) {
        ExecuteActionJoystickPressed(action);
    } else if(_mode == keyboardMode) {
        ExecuteActionKeyboardPressed(action);
    } 
}

void ButtonManager::ExecuteActionReleased(int action) {
    if(_mode == joystickMode) {
        ExecuteActionJoystickReleased(action);
    } else if(_mode == keyboardMode) {
        ExecuteActionKeyboardReleased(action);
    } 
}

void ButtonManager::ExecuteActionKeyboardPressed(int action) {
    Keyboard.press(kb_map[_player][action]);
}

void ButtonManager::ExecuteActionKeyboardReleased(int action) {
    Keyboard.release(kb_map[_player][action]);
}

void ButtonManager::ExecuteActionJoystickPressed(int action) {
    if(action == actionB1P) {
        Joystick.button(1, BTN_PRESSED);
    } else if (action == actionB2P) {
        Joystick.button(2, BTN_PRESSED);
    } else if (action == actionB3P) {
        Joystick.button(3, BTN_PRESSED);
    } else if (action == actionB4P) {
        Joystick.button(4, BTN_PRESSED);
    } else if (action == actionB5P) {
        Joystick.button(5, BTN_PRESSED);
    } else if (action == actionB6P) {
        Joystick.button(6, BTN_PRESSED);
    } else if (action == actionB7P) {
        Joystick.button(7, BTN_PRESSED);
    } else if (action == actionB8P) {
        Joystick.button(8, BTN_PRESSED);
    } else if (action == actionB9P) {
        Joystick.button(9, BTN_PRESSED);
    } else if (action == actionB10P) {
        Joystick.button(10, BTN_PRESSED);
    } else if (action == actionShiftP) {
        _shiftJoystick = true;
    }
}

void ButtonManager::ExecuteActionJoystickReleased(int action) {
    if (action == actionB1R) {
        Joystick.button(1, BTN_RELEASED);
    } else if (action == actionB2R) {
        Joystick.button(2, BTN_RELEASED);
    } else if (action == actionB3R) {
        Joystick.button(3, BTN_RELEASED);
    } else if (action == actionB4R) {
        Joystick.button(4, BTN_RELEASED);
    } else if (action == actionB5R) {
        Joystick.button(5, BTN_RELEASED);
    } else if (action == actionB6R) {
        Joystick.button(6, BTN_RELEASED);
    } else if (action == actionB7R) {
        Joystick.button(7, BTN_RELEASED);
    } else if (action == actionB8R) {
        Joystick.button(8, BTN_RELEASED);
    } else if (action == actionB9R) {
        Joystick.button(9, BTN_RELEASED);
    } else if (action == actionB10R) {
        Joystick.button(10, BTN_RELEASED);
    } else if (action == actionShiftR) {
        _shiftJoystick = false;
    }
} 
