#include<SoftwareSerial.h>

//for use with sim900 gsm module
SoftwareSerial SIM900(15,14);
SoftwareSerial s(0,1);
String textForSMS = "testmessage";
String number = "*********";
String countryCode = "+49";

void setup()
{  
   s.begin(9600);
   number.remove(0,1);
   SendSMS(number, textForSMS);
   s.println("ready");
}

void SendSMS(String number, String msg)
{
  SIM900.begin(4800);
  SIM900.print("\r");
  SIM900.print("AT+CMGF=1\r");
  delay(300);
  SIM900.print("AT+CMGS=\"" + countryCode + number + "\"\r");  
  delay(300);
  SIM900.print(msg + "\r");
  delay(300);
  SIM900.write(0x1A);
}

void loop()
{
}

