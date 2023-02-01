#include <Servo.h>
Servo myservo;
#define serv 1;

void setup() {
  myservo.attach(serv);
}

void loop() {
  myservo.write(0);
}
