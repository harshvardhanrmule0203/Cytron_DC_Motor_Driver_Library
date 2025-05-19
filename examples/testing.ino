#include "Cytron.h"

const int pwm_pin 10
const int  direction_pin 11
const bool direction_bool false

char data;

Cytron motor(pwm_pin,direction_pin,direction_bool);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ganpati Bappa Morya!!");

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      data = Serial.read();
  }

  if(data == '1'){
      motor.rotate(30);
      Serial.println("Fwd");
  }
  else if(data == '2'){
      motor.rotate(-30);
      Serial.println("Rev");
  }
  else{
      motor.stop();
  }
}
