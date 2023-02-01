#include "MPU6050.h"
#define mpu_addr 0x68;
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
mpu.CalibrateAccel(15);
void setup() {
  Wire.begin();
  Serial.begin(9600);
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "MPU6050 OK" : "MPU6050 FAIL");
  delay(1000);
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial.print(ax); Serial.print('\t');
  Serial.print(ay); Serial.print('\t');
  Serial.print(az); Serial.print('\t');
  Serial.print(gx); Serial.print('\t');
  Serial.print(gy); Serial.print('\t');
  Serial.println(gz);
  delay(5);
}
