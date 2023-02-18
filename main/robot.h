#pragma once
#include <Arduino.h>

#include <Servo.h>
#include <Wire.h>
#include "MS5837.h"
#include "MPU6050.h"
//eeprom
struct Mpu{
  int16_t ax = 0;
  int16_t ay = 0;
  int16_t az = 0;
  int16_t gx = 0;
  int16_t gy = 0;
  int16_t gz = 0;
}

struct Depth{
  int pressure = 0;
  int temperature = 0;
  int depth = 0;
  int altitude = 0;
  
}

class Robot {
private:
#define led_r 5
#define led_g 4
#define led_b 3
#define serv 1
#define motor 11
#define depth_addr 0x67
#define mpu_addr 0x68

  MPU6050 MPU;
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  Servo myservo;
  myservo.attach(serv);

  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);

  Serial.begin(57600);
  Wire.begin();

  sensor.setFluidDensity(997);

public:
  Robot();

  void Robot::rgb(int red = 0, int green = 0, blue = 0) const {
    digitalWrite(led_r, red);
    digitalWrite(led_g, green);
    digitalWrite(led_b, blue);
  }

  void Robot::servo(int position = 0) const{
    miservo.write(position);
  }

  int Robot::depth() const {
    Depth res = {sensor.pressure(), sensor.temperature(), sensor.depth(), sensor.altitude()}
    return res
  }

  int Robot::mpu() {
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Mpu res = {ax, ay, az, gx, gy, gz}
    return res;
  }
}
