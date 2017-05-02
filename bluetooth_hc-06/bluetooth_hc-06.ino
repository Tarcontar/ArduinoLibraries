#include<SoftwareSerial.h>
//tested with hc-06 module and arduino mega 
//no level shifting needed!! pins can be connected directly

SoftwareSerial BT(10,11);

void setup() {
  BT.begin(9600);
  BT.println("Hello from Arduino");
}

char c;
void loop() {
  if (BT.available())
  {
    c = BT.read();
    BT.println(c);
  }
}
