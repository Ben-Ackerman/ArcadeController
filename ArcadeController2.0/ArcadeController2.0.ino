#include <Bounce.h>
#include <ButtonManager.h>
#include <Actions.h>
#include <Direction.h>
#include <JoystickManager.h>

const int joystickRadius = 314;
const int joystickCenter = 512;
const int bounceTime = 50;
const int player = 1;
unsigned long startTime;
ControllerMode currentMode = keyboardMode;
ButtonManager buttonManager(currentMode, player);
JoystickManager joystickManager(currentMode, player);

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce buttons[11] = {
  Bounce(3, bounceTime),
  Bounce(2, bounceTime),  // 10 = 10 ms debounce time
  Bounce(1, bounceTime),  // which is appropriate for
  Bounce(0, bounceTime),  // most mechanical pushbuttons
  Bounce(7, bounceTime),
  Bounce(6, bounceTime),
  Bounce(5, bounceTime),
  Bounce(4, bounceTime),
  Bounce(8, bounceTime),
  Bounce(9, bounceTime),
  Bounce(10, bounceTime)
};
Bounce joystick[4] = {
  Bounce(13, bounceTime),
  Bounce(14, bounceTime),
  Bounce(15, bounceTime),
  Bounce(16, bounceTime)
};

void setup() {
  // For pull up resistors LOW for "on", and HIGH for "off" 
  for(int i = 0; i < 17; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Keyboard.begin();
  startTime = millis();
}

bool modeChange() {
  // If the main 8 buttons are pressed change mode
  for (int i = 0; i < 8 ; i++) {
    if (buttons[i].read() == HIGH) {
      return false;
    }
  }
  // Since all pins read high on start up do not
  // allow change mode in first 5sec
  return (millis() - startTime > 5000);
}
void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  if (modeChange()) {
      if (currentMode == joystickMode) {
        currentMode = keyboardMode;
      } else {
        currentMode = joystickMode;
      }
      for(int i = 0; i < 11; i++) {
        buttonManager.ReleaseButton(i);
      }     
      joystickManager.SetMode(currentMode);
      buttonManager.ChangeMode(currentMode);
      delay(3000);
  }
  for(int i = 0; i < 11; i++) {
    buttons[i].update();
  }
  for(int i = 0; i < 4; i++) {
    joystick[i].update();
  }

  // Check each button for "falling" edge.
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  for(int i = 0; i < 11; i++) {
    if (buttons[i].fallingEdge()) {
      buttonManager.PressButton(i);
    }
  }

  for(int i = 0; i < 11; i++) {
    if (buttons[i].risingEdge()) {
      buttonManager.ReleaseButton(i);
    }
  }
  
  if (joystick[BUTTON_LEFT].fallingEdge()) {
    joystickManager.PressButton(BUTTON_LEFT);
  }
  
  if (joystick[BUTTON_RIGHT].fallingEdge()) {
    joystickManager.PressButton(BUTTON_RIGHT);
  }
  if (joystick[BUTTON_DOWN].fallingEdge()) {
    joystickManager.PressButton(BUTTON_DOWN);
  } 
  if (joystick[BUTTON_UP].fallingEdge()) {
    joystickManager.PressButton(BUTTON_UP);
  }
  
  if (joystick[BUTTON_LEFT].risingEdge()) {
    joystickManager.ReleaseButton(BUTTON_LEFT);
  }
  if (joystick[BUTTON_RIGHT].risingEdge()) {
    joystickManager.ReleaseButton(BUTTON_RIGHT);
  }
  if (joystick[BUTTON_DOWN].risingEdge()) {
    joystickManager.ReleaseButton(BUTTON_DOWN);
  } 
  if (joystick[BUTTON_UP].risingEdge()) {
   joystickManager.ReleaseButton(BUTTON_UP);
  }

  if(currentMode == joystickMode && buttonManager.ShiftJoystick() != joystickManager.GetShifted()) {
    joystickManager.SetShifted(buttonManager.ShiftJoystick());
    joystickManager.RunJoystick();
  }
}
