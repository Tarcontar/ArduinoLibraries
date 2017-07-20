#include<NewPing.h>
//tested with hc-sr04 module and arduino mega 


NewPing sensor_1(32, 33, 2000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(sensor_1.ping_cm());
  delay(500);
}
