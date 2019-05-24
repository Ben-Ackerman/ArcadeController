#ifndef JoystickManager_H
#define JoystickManager_H

#include "Arduino.h"
#include "Modes.h"
#include "Constants.h"
#include "Direction.h"

#define SHIFT_MOD_AMOUNT 4
#define JOYSTICK_RADIUS 314
#define JOYSTICK_CENTER 512

class JoystickManager
{
    public:
        JoystickManager(ControllerMode mode, int player);
        void PressButton(Direction direction);
        void ReleaseButton(Direction direction);
        void RunJoystick();
        void ExecuteKeyboardPressed(Direction direction);
        void ExecuteKeyboardReleased(Direction direction);
        void SetShifted(bool shifted);
		bool GetShifted();
        void SetMode(ControllerMode mode);
    private:
        bool _joystickShifted;
        ControllerMode _mode;
        bool _leftPressed;
        bool _rightPressed;
        bool _upPressed;
        bool _downPressed;
        int _player;
        static int kb_map [4][4];
};

#endif
