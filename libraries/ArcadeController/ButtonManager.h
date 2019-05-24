#ifndef ButtonManager_h
#define ButtonManager_h

#include "Arduino.h"
#include "Actions.h"
#include "Modes.h"
#include "Constants.h"

#define MAX_BUTTONS 11

class ButtonManager
{
    public:
        ButtonManager(ControllerMode mode, int player);
        void PressButton(int button);
        void ReleaseButton(int button);
        bool ShiftJoystick();
        void ChangeMode(ControllerMode mode);
    private:
        void ExecuteActionPressed(int action);
        void ExecuteActionReleased(int action);
        void ExecuteActionJoystickPressed(int action);
        void ExecuteActionJoystickReleased(int action);
        void ExecuteActionKeyboardPressed(int action);
        void ExecuteActionKeyboardReleased(int action);
        bool _shiftJoystick;
        ControllerMode _mode;
        int _pressActions[MAX_BUTTONS];
        int _releaseActions[MAX_BUTTONS];
        int _player;
        int static kb_map[4][11];
};

#endif
