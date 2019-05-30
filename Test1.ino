/*
        Arduino Brushless Motor Control
     by Dejan, https://howtomechatronics.com
*/
#include <Servo.h>
Servo ESC;     // create servo object to control the ESC
String x;
int y;
void setup() {
  Serial.begin(9600);
  // Attach the ESC on pin 9
  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
}
void loop() {
  if(Serial.available()){
    x = Serial.readString();
    Serial.println(x);
    
    y = x.toInt();
    ESC.write(y);
  }
}


