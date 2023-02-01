#define led_r 1;
#define led_g 1;
#define led_b 1;
#define serv 1;
#define motor 1;
#define depth_rx 1;
#define depth_tx 1;
#define mpu_rx 1;
#define mpu_tx 1;


void rdb_led(int red, int green, int blue){
  digitalWrite(led_r, red);
  digitalWrite(led_g, green);
  digitalWrite(led_b, blue);
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
