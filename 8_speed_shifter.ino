// 8 speed H shifter using 4 switches, by Akaki Kuumeri 
//Pins
// 2: X left
// 3: X right
// 4: X right extreme
// 5: X up
// 6: Y down

#define LEFT 0
#define RIGHT 1
#define RIGHTEXTREME 2
#define UP 3
#define DOWN 4

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  8, 0,                  // Button Count, Hat Switch Count
  false, false, false,   // No X, Y, Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();

}

// Last state of the buttons
int lastButtonState[8] = {0,0,0,0,0,0,0,0};
int currentButtonState[8] = {0,0,0,0,0,0,0,0};
int input[5] = {0,0,0,0,0};
int gear = 0; //0 is neutral

void loop() {

  // Read pin values
  for (int index = 0; index < 5; index++)
  {
    input[index] = !digitalRead(index+2);
  }
  gear = 0;
  if (input[UP]) //if stick is up
  {
    if (input[LEFT]) //left
    {
      gear = 1;
    }
    else if (input[RIGHT])
    {
      if (input[RIGHTEXTREME]) //if also right extreme
      {
        gear = 7;
      }
      else
      {
      gear = 5;
      }
    }
    else
    {
      gear = 3; //stick is neither left not right, but points up
    }
  }
  else if (input[DOWN])
  {
    if (input[LEFT])
    {
      gear = 2;
    }
    else if (input[RIGHT])
    {
      if (input[RIGHTEXTREME]) //if also right extreme
      {
        gear = 8;
      }
      else
      {
      gear = 6;
      }
    }
    else
    {
      gear = 4; //stick is neither left not right, but points down
    }
  } //otherwise 0, neutral

  //make all buttons 0
  currentButtonState[0] = 0;
  currentButtonState[1] = 0;
  currentButtonState[2] = 0;
  currentButtonState[3] = 0;
  currentButtonState[4] = 0;
  currentButtonState[5] = 0;
  currentButtonState[6] = 0;
  currentButtonState[7] = 0;
  if (gear != 0) {currentButtonState[gear-1] = 1;} //if in gear, make button number gear-1 active. First gear is 0, second is 1 and so on
  
  for (int index = 0; index < 8; index++) //send out button comands
  {
    if (currentButtonState[index] != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState[index]);
      lastButtonState[index] = currentButtonState[index];
    }
  }

  delay(10);
}
