#include "JoystickManager.h"

#define RESULT_UP 1
#define RESULT_UPRIGHT 5
#define RESULT_UPLEFT 9
#define RESULT_DOWN 2
#define RESULT_DOWNRIGHT 6
#define RESULT_DOWNLEFT 10
#define RESULT_RIGHT 4
#define RESULT_LEFT 8

int JoystickManager::kb_map[4][4] = {{KEY_A, KEY_B, KEY_C, KEY_D}, {KEY_E, KEY_F, KEY_G, KEY_H},
    {KEY_I, KEY_J, KEY_K, KEY_L}, {KEY_M, KEY_N, KEY_O, KEY_P}};

JoystickManager::JoystickManager(ControllerMode mode, int player) {
    _mode = mode;
    _player = player;
    _joystickShifted = false;
}

void JoystickManager::SetMode(ControllerMode mode) {
    _mode = mode;
}

bool JoystickManager::GetShifted() {
		return _joystickShifted;
}
void JoystickManager::SetShifted(bool shifted) {
    _joystickShifted = shifted;
}
void JoystickManager::PressButton(Direction direction) {
	switch(direction){
        case BUTTON_UP:
            _upPressed = true;
            break;
        case BUTTON_DOWN:
            _downPressed = true;
            break;
        case BUTTON_LEFT:
            _leftPressed = true;
            break;
        case BUTTON_RIGHT:
            _rightPressed = true;
            break;
    }

    if (_mode == joystickMode) {
        RunJoystick();
    } else if (_mode == keyboardMode) {
        ExecuteKeyboardPressed(direction);
    }
}


void JoystickManager::ReleaseButton(Direction direction) {
     switch(direction){
        case BUTTON_UP:
            _upPressed = false;
            break;
        case BUTTON_DOWN:
            _downPressed = false;
            break;
        case BUTTON_LEFT:
            _leftPressed = false;
            break;
        case BUTTON_RIGHT:
            _rightPressed = false;
            break;
    }
 
    if (_mode == joystickMode) {
        RunJoystick();
    } else if (_mode == keyboardMode) {
        ExecuteKeyboardReleased(direction);
    }
}

void JoystickManager::ExecuteKeyboardPressed(Direction direction) {
	if(_upPressed) {
		Keyboard.press(kb_map[_player][BUTTON_UP]);
	} else {
		Keyboard.release(kb_map[_player][BUTTON_UP]);
	}
	if(_downPressed) {
		Keyboard.press(kb_map[_player][BUTTON_DOWN]);
	} else {
		Keyboard.release(kb_map[_player][BUTTON_DOWN]);
	}
	if(_leftPressed) {
		Keyboard.press(kb_map[_player][BUTTON_LEFT]);
	} else {
		Keyboard.release(kb_map[_player][BUTTON_LEFT]);
	}
	if(_rightPressed) {
		Keyboard.press(kb_map[_player][BUTTON_RIGHT]);
	} else {
		Keyboard.release(kb_map[_player][BUTTON_RIGHT]);
	}
	
}
void JoystickManager::ExecuteKeyboardReleased(Direction direction) {
    //Keyboard.release(kb_map[_player][direction]);
	// All logic moved into ExecuteKeyboardPressed
	ExecuteKeyboardPressed(direction);
}

void JoystickManager::RunJoystick() {
    int result = _upPressed;
    result += _downPressed << 1;
    result += _rightPressed << 2;
    result += _leftPressed << 3;

    int velocity = JOYSTICK_RADIUS;

    if (_joystickShifted) {
      velocity = (velocity * SHIFT_MOD_AMOUNT) / 10;
    }
    
    if(result == RESULT_UP) {
      Joystick.X(JOYSTICK_CENTER);
      Joystick.Y(JOYSTICK_CENTER + velocity);
    } else if (result == RESULT_UPRIGHT){
      Joystick.X(JOYSTICK_CENTER + velocity);
      Joystick.Y(JOYSTICK_CENTER + velocity);
    } else if (result == RESULT_UPLEFT){
      Joystick.X(JOYSTICK_CENTER - velocity);
      Joystick.Y(JOYSTICK_CENTER + velocity);
    } else if (result == RESULT_DOWN){
      Joystick.X(JOYSTICK_CENTER);
      Joystick.Y(JOYSTICK_CENTER - velocity);
    } else if (result == RESULT_DOWNRIGHT){
      Joystick.X(JOYSTICK_CENTER + velocity);
      Joystick.Y(JOYSTICK_CENTER - velocity);
    } else if (result == RESULT_DOWNLEFT){
      Joystick.X(JOYSTICK_CENTER - velocity);
      Joystick.Y(JOYSTICK_CENTER - velocity);
    } else if (result == RESULT_RIGHT){
      Joystick.X(JOYSTICK_CENTER + velocity);
      Joystick.Y(JOYSTICK_CENTER);
    } else if (result == RESULT_LEFT){
      Joystick.X(JOYSTICK_CENTER - velocity);
      Joystick.Y(JOYSTICK_CENTER);
    } else {
      Joystick.X(JOYSTICK_CENTER);
      Joystick.Y(JOYSTICK_CENTER);
    }
}
