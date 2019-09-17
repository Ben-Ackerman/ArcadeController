*Arduino Arcade Controller*

**Purpose**
The purpose of this project is to add the necessary libraries to turn a teensy 3.0 into both a joystick or keyboard controller for use in MAME emulation.  

I created this project because I was creating a four player arcade cabinet that would allow for up to 10 buttons per player.  When researching PCBs to use with this cabinet every one I found was either to expensive or did not support the number of players/inputs I was looking for.  Since I had some experience working with arduino's in the past I decided to buy a couple of teenseys and solve this problem myself.

I am putting this source code up here on github to hopefully help give a starting off point for the next maker who finds themselves in the same situation I was in.

**Hardware used for creating arcade controllers**
Each of my four arcade controllers had -
1 - Teensy 3.2 board https://www.adafruit.com/product/2756?gclid=EAIaIQobChMInJ-GkbTY5AIVcRh9Ch2AeQdXEAQYAyABEgJ7aPD_BwE.
1 - Sanwa JLF joystick.
10 (11 for the player one who had an addtional escape button) - Happ competition buttons.

When choosing what hardware to use for my cabinet I found this article extremely useful.
https://www.tested.com/art/makers/464539-choosing-buttons-and-joysticks-custom-arcade-cabinet/


**Why I choose the technologies and design choose I did**
1. Why Teensy 3.2 board - I choose the teensy 3.0 board because teensy offers a robust library that sits on top of arduino which supports keyboard/mouse/joystick input out of the box saving me time on writting the underlying libraries. 

2. Why support both a keyboard and joystick mode.  My plan for this arcade cabinet was to emulate both MAME(digital joystick) and Gamecube(analog joystick) games. By supporting both a joystick and keyboard mode I made working with emulators easier.

** Issues and solutions I ran into **
1. One problem I ran into was since the joystick is all digital inputs and only determines direction not magnitude what would be the best way of simulating a analog joystick for gamecube emulators?  What I ended up deciding on doing was using one of my buttons as a magnitude switch that toggled the joystick from a high magnitude direction to a low magnitude direction.

2. Since I would not have easy access to my components how would I handle switching between the joystick and keyboard modes.  I decided the easiest and best way from me to switch between modes was to switch when all eight of the players primary buttons are pressed.

**Set Up**

1. Install arduino
2. Run teensy installer for arduino https://www.pjrc.com/teensy/td_download.html
3. In arduino IDE go to manage libaries and add Bounce2
4. Go to your arduino directory and add a symbolic link from the arduino libraries directory to this github project's libaries directory.
