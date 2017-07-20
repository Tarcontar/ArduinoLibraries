#include <DS3231.h>

DS3231 rtc(SDA, SCL);

void setup()
{
  rtc.begin();
  //do this only once for each clock module
  //rtc.setTime(20, 8, 20); 
  //rtc.setDate(22, 4, 2017);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(rtc.getTimeStr());
  Serial.println(rtc.getDateStr());
  Serial.println(rtc.getTemp());
  delay(1000);
}

