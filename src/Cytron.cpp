#include"Cytron.h"

Cytron::Cytron(int temp_pwm,int temp_dir_pin,bool temp_direction):pwm(temp_pwm),dir_pin(temp_dir_pin),direction(temp_direction){
    pinMode(dir_pin,OUTPUT);
    pinMode(pwm,OUTPUT);
}

void Cytron::rotate(int value){

  if(value>=0){
        digitalWrite(dir_pin,direction);
    }
    else{
        digitalWrite(dir_pin,!direction);
    }
    analogWrite(pwm, abs(value));
}

void Cytron::test(int pwmvalue, int Delay){
   Serial.begin(9600);
   Serial.println(String("testing Cytron pins pwm - ") + pwm + String("  direction - ") + dir_pin);
   delay(2000);
   for(int i = 0;i<pwmvalue;i+=5){
    rotate(pwmvalue);
    Serial.println(String("PWM - ")+i);
    delay(Delay);
   }
   for(int i = pwmvalue;i>-pwmvalue;i-=5){
    rotate(i);
    Serial.println(String("PWM - ")+i);
    delay(Delay);
   }
   for(int i = -pwmvalue;i<0;i+=5){
    rotate(i);
    Serial.println(String("PWM - ")+i);
    delay(Delay);
   }
   Serial.println("test complete!");
}