int button_ccw = 7;   
int button_cw = 8;  
#include<Servo.h> 
Servo servo; 
int pos = 0;  
void setup() {
  servo.attach(9);  
  pinMode(button_ccw, INPUT);  
  pinMode(button_cw, INPUT); 
}

void loop() {
 
  if (digitalRead(button_ccw) == LOW) { 
    pos++;  
    delay(5); 
    servo.write(pos); 
  }
  if (digitalRead(button_cw) == LOW) { 
    pos--;  
    delay(5);
    servo.write(pos);
  }
}
