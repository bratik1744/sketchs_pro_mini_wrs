#define led_r 1;
#define led_g 1;
#define led_b 1;

void rdb_led(int red, int green, int blue){
  digitalWrite(led_r, red);
  digitalWrite(led_g, green);
  digitalWrite(led_b, blue);
}
