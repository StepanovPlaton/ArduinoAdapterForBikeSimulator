#include "Joystick.h"
Joystick_ Joystick;

long time_ = millis();
float cadence;
int speed_;
void setup() {
  // put your setup code here, to run once:
  Joystick.setYAxisRange(-127, 127);
  Joystick.setXAxisRange(-127, 127);
  Joystick.setXAxis(0);
  Joystick.begin();
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(5) == HIGH) {
    speed_ = (millis() - time_);
    cadence = 60000/speed_/0.25;
    time_ = millis();
    digitalWrite(7, HIGH);
    delay(50);
  }
  else { 
    cadence-=0.1;
    digitalWrite(7, LOW); 
  }

  

  if(cadence > 127) { cadence = 127; }
  if(cadence < 0) { cadence = 0; }
  Joystick.setYAxis(-1*(int)cadence);
  Joystick.sendState();
}
