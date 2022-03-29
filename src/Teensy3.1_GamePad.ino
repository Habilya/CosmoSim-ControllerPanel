// Button press constants
#define BUTTON_PRESS 1
#define BUTTON_RELEASE 0

// Pins of the Teensy microcontroller used
#define VCC_OUTPUT 0
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4
#define BUTTON_5 5
#define BUTTON_6 6
#define BUTTON_7 7
#define BUTTON_8 8
#define BUTTON_9 9
#define BUTTON_10 10
#define BUTTON_11 11
#define BUTTON_12 12
#define BUTTON_13 14
#define BUTTON_14 15
#define BUTTON_15 16
#define BUTTON_16 17
#define BUTTON_17 18
#define BUTTON_18 19
#define BUTTON_19 20
#define BUTTON_20 21
#define MODE_SWITCH 23
#define MODE_LED 22

// Debug Mode all buttons will be output to serial monitor
#define DEBUG 0

// 10 = 10 ms debounce time
// which is appropriate for
// most mechanical pushbuttons
#define DEBOUNCE_TIME 10

#include <Bounce.h>

bool isAlternateMode = false;

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button1 = Bounce(BUTTON_1, DEBOUNCE_TIME);
Bounce button2 = Bounce(BUTTON_2, DEBOUNCE_TIME);
Bounce button3 = Bounce(BUTTON_3, DEBOUNCE_TIME);
Bounce button4 = Bounce(BUTTON_4, DEBOUNCE_TIME);
Bounce button5 = Bounce(BUTTON_5, DEBOUNCE_TIME);
Bounce button6 = Bounce(BUTTON_6, DEBOUNCE_TIME);
Bounce button7 = Bounce(BUTTON_7, DEBOUNCE_TIME);
Bounce button8 = Bounce(BUTTON_8, DEBOUNCE_TIME);
Bounce button9 = Bounce(BUTTON_9, DEBOUNCE_TIME);
Bounce button10 = Bounce(BUTTON_10, DEBOUNCE_TIME);
Bounce button11 = Bounce(BUTTON_11, DEBOUNCE_TIME);
Bounce button12 = Bounce(BUTTON_12, DEBOUNCE_TIME);
Bounce button13 = Bounce(BUTTON_13, DEBOUNCE_TIME);
Bounce button14 = Bounce(BUTTON_14, DEBOUNCE_TIME);
Bounce button15 = Bounce(BUTTON_15, DEBOUNCE_TIME);
Bounce button16 = Bounce(BUTTON_16, DEBOUNCE_TIME);
Bounce button17 = Bounce(BUTTON_17, DEBOUNCE_TIME);
Bounce button18 = Bounce(BUTTON_18, DEBOUNCE_TIME);
Bounce button19 = Bounce(BUTTON_19, DEBOUNCE_TIME);
Bounce button20 = Bounce(BUTTON_20, DEBOUNCE_TIME);
Bounce modeSwitch = Bounce(MODE_SWITCH, DEBOUNCE_TIME);

void setup() {
  pinMode(VCC_OUTPUT, OUTPUT);
  digitalWrite(VCC_OUTPUT, HIGH);

  pinMode(MODE_LED, OUTPUT);
  digitalWrite(MODE_LED, LOW);
  
  Joystick.useManualSend(true);
  Joystick.hat(-1);
  
  setButtonsPinMode();

  debug();
}

void loop() {
  updateButtons();
  checkButtons();
}

void setButtonsPinMode() {
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  pinMode(BUTTON_6, INPUT_PULLUP);
  pinMode(BUTTON_7, INPUT_PULLUP);
  pinMode(BUTTON_8, INPUT_PULLUP);
  pinMode(BUTTON_9, INPUT_PULLUP);
  pinMode(BUTTON_10, INPUT_PULLUP);
  pinMode(BUTTON_11, INPUT_PULLUP);
  pinMode(BUTTON_12, INPUT_PULLUP);
  pinMode(BUTTON_13, INPUT_PULLUP);
  pinMode(BUTTON_14, INPUT_PULLUP);
  pinMode(BUTTON_15, INPUT_PULLUP);
  pinMode(BUTTON_16, INPUT_PULLUP);
  pinMode(BUTTON_17, INPUT_PULLUP);
  pinMode(BUTTON_18, INPUT_PULLUP);
  pinMode(BUTTON_19, INPUT_PULLUP);
  pinMode(BUTTON_20, INPUT_PULLUP);
  pinMode(MODE_SWITCH, INPUT_PULLUP);
}

void updateButtons() {
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();
  button12.update();
  button13.update();
  button14.update();
  button15.update();
  button16.update();
  button17.update();
  button18.update();
  button19.update();
  button20.update();
  modeSwitch.update();
}

void checkButtons(){

  if (modeSwitch.fallingEdge()) {
    digitalWrite(MODE_LED, HIGH);
    isAlternateMode = true;
    
  }
  
  if (modeSwitch.risingEdge()) {
    digitalWrite(MODE_LED, LOW);
    isAlternateMode = false;
  }

  if (isAlternateMode) {
    buttonsProcessingAlternateMode();
  } else {
    buttonsProcessingNormalMode();
  }
}

void buttonsProcessingNormalMode() {
  if (button1.fallingEdge()) Joystick.button(1, BUTTON_PRESS);
  if (button1.risingEdge()) Joystick.button(1, BUTTON_RELEASE);

  if (button2.fallingEdge()) Joystick.button(2, BUTTON_PRESS);
  if (button2.risingEdge()) Joystick.button(2, BUTTON_RELEASE);

  if (button3.fallingEdge()) Joystick.button(3, BUTTON_PRESS);
  if (button3.risingEdge()) Joystick.button(3, BUTTON_RELEASE);
  
  if (button4.fallingEdge()) Joystick.button(4, BUTTON_PRESS);
  if (button4.risingEdge()) Joystick.button(4, BUTTON_RELEASE);

  if (button5.fallingEdge()) Joystick.button(5, BUTTON_PRESS);
  if (button5.risingEdge()) Joystick.button(5, BUTTON_RELEASE);

  if (button6.fallingEdge()) Joystick.button(6, BUTTON_PRESS);
  if (button6.risingEdge()) Joystick.button(6, BUTTON_RELEASE);

  if (button7.fallingEdge()) Joystick.button(7, BUTTON_PRESS);
  if (button7.risingEdge()) Joystick.button(7, BUTTON_RELEASE);

  if (button8.fallingEdge()) Joystick.button(8, BUTTON_PRESS);
  if (button8.risingEdge()) Joystick.button(8, BUTTON_RELEASE);

  if (button9.fallingEdge()) Joystick.button(9, BUTTON_PRESS);
  if (button9.risingEdge()) Joystick.button(9, BUTTON_RELEASE);

  if (button10.fallingEdge()) Joystick.button(10, BUTTON_PRESS);
  if (button10.risingEdge()) Joystick.button(10, BUTTON_RELEASE);

  if (button11.fallingEdge()) Joystick.button(11, BUTTON_PRESS);
  if (button11.risingEdge()) Joystick.button(11, BUTTON_RELEASE);

  if (button12.fallingEdge()) Joystick.button(12, BUTTON_PRESS);
  if (button12.risingEdge()) Joystick.button(12, BUTTON_RELEASE);

  if (button13.fallingEdge()) Joystick.button(13, BUTTON_PRESS);
  if (button13.risingEdge()) Joystick.button(13, BUTTON_RELEASE);

  if (button14.fallingEdge()) Joystick.button(14, BUTTON_PRESS);
  if (button14.risingEdge()) Joystick.button(14, BUTTON_RELEASE);

  if (button15.fallingEdge()) Joystick.button(15, BUTTON_PRESS);
  if (button15.risingEdge()) Joystick.button(15, BUTTON_RELEASE);

  if (button16.fallingEdge()) Joystick.button(16, BUTTON_PRESS);
  if (button16.risingEdge()) Joystick.button(16, BUTTON_RELEASE);

  if (button17.fallingEdge()) Joystick.button(17, BUTTON_PRESS);
  if (button17.risingEdge()) Joystick.button(17, BUTTON_RELEASE);

  if (button18.fallingEdge()) Joystick.button(18, BUTTON_PRESS);
  if (button18.risingEdge()) Joystick.button(18, BUTTON_RELEASE);

  if (button19.fallingEdge()) Joystick.button(19, BUTTON_PRESS);
  if (button19.risingEdge()) Joystick.button(19, BUTTON_RELEASE);
    
  if (button20.fallingEdge()) Joystick.button(20, BUTTON_PRESS);
  if (button20.risingEdge()) Joystick.button(20, BUTTON_RELEASE);

  Joystick.send_now();
}

void buttonsProcessingAlternateMode() {
  // Define your logic here
}

// Debugging
void debug() {
#if (DEBUG == 1)
  Serial.begin(9600);
  
  while (true) {
    updateButtons();
    
    if (button1.fallingEdge()) Serial.println("BUTTON1_Press");
    if (button1.risingEdge()) Serial.println("BUTTON1_Release");

    if (button2.fallingEdge()) Serial.println("BUTTON2_Press");
    if (button2.risingEdge()) Serial.println("BUTTON2_Release");

    if (button3.fallingEdge()) Serial.println("BUTTON3_Press");
    if (button3.risingEdge()) Serial.println("BUTTON3_Release");

    if (button4.fallingEdge()) Serial.println("BUTTON4_Press");
    if (button4.risingEdge()) Serial.println("BUTTON4_Release");

    if (button5.fallingEdge()) Serial.println("BUTTON5_Press");
    if (button5.risingEdge()) Serial.println("BUTTON5_Release");

    if (button6.fallingEdge()) Serial.println("BUTTON6_Press");
    if (button6.risingEdge()) Serial.println("BUTTON6_Release");

    if (button7.fallingEdge()) Serial.println("BUTTON7_Press");
    if (button7.risingEdge()) Serial.println("BUTTON7_Release");

    if (button8.fallingEdge()) Serial.println("BUTTON8_Press");
    if (button8.risingEdge()) Serial.println("BUTTON8_Release");

    if (button9.fallingEdge()) Serial.println("BUTTON9_Press");
    if (button9.risingEdge()) Serial.println("BUTTON9_Release");

    if (button10.fallingEdge()) Serial.println("BUTTON10_Press");
    if (button10.risingEdge()) Serial.println("BUTTON10_Release");

    if (button11.fallingEdge()) Serial.println("BUTTON11_Press");
    if (button11.risingEdge()) Serial.println("BUTTON11_Release");

    if (button12.fallingEdge()) Serial.println("BUTTON12_Press");
    if (button12.risingEdge()) Serial.println("BUTTON12_Release");

    if (button13.fallingEdge()) Serial.println("BUTTON13_Press");
    if (button13.risingEdge()) Serial.println("BUTTON13_Release");

    if (button14.fallingEdge()) Serial.println("BUTTON14_Press");
    if (button14.risingEdge()) Serial.println("BUTTON14_Release");

    if (button15.fallingEdge()) Serial.println("BUTTON15_Press");
    if (button15.risingEdge()) Serial.println("BUTTON15_Release");

    if (button16.fallingEdge()) Serial.println("BUTTON16_Press");
    if (button16.risingEdge()) Serial.println("BUTTON16_Release");

    if (button17.fallingEdge()) Serial.println("BUTTON17_Press");
    if (button17.risingEdge()) Serial.println("BUTTON17_Release");

    if (button18.fallingEdge()) Serial.println("BUTTON18_Press");
    if (button18.risingEdge()) Serial.println("BUTTON18_Release");

    if (button19.fallingEdge()) Serial.println("BUTTON19_Press");
    if (button19.risingEdge()) Serial.println("BUTTON19_Release");

    if (button20.fallingEdge()) Serial.println("BUTTON20_Press");
    if (button20.risingEdge()) Serial.println("BUTTON20_Release");

    if (modeSwitch.fallingEdge()) Serial.println("modeSwitch_Press");
    if (modeSwitch.risingEdge()) Serial.println("modeSwitch_Release");

  }
  Serial.end();
#endif
}
