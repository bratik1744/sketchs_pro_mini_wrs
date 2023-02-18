#include <Servo.h>
// создание объекта
Servo motor;
Servo servo;
#define led_r 5
#define led_g 4
#define led_b 3

void rgb_led(int red, int green, int blue){
  digitalWrite(led_r, red);
  digitalWrite(led_g, green);
  digitalWrite(led_b, blue);
}
#define mot_pin 11
int max_pwm = 2500;
int min_pwm = 100;
void setup(){
  Serial.begin(9600);
  servo.attach(10);
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);
  motor.attach(mot_pin);
  rgb_led(1, 0, 0);
  motor.writeMicroseconds(max_pwm);
  delay(2000);
  rgb_led(0, 1, 0);
  motor.writeMicroseconds(min_pwm);
  delay(2000);
  rgb_led(0, 0, 1);
  motor.writeMicroseconds((min_pwm + max_pwm) / 2);
  delay(2000);
  
}
 

void loop(){  
  rgb_led(1, 1, 1);
  motor.writeMicroseconds(2000);
  servo.write(0);
  delay(10);
  motor.writeMicroseconds(1000);
  servo.write(180);
  delay(10);
}
