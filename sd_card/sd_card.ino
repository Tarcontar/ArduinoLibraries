#include <SPI.h>
#include <SD.h>

//for DFRobot.com MicroSD module

File myFile;
int CS = 2;

void setup()
{
  Serial.begin(9600);
  Serial.println("initializing SD card...");
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  if (!SD.begin(CS))
  {
    Serial.println("error");
    return;
  }
  Serial.println("initialization done");

  myFile = SD.open("log.txt", FILE_WRITE);
  if (myFile)
  {
    Serial.println("Writing to log.txt...");
    myFile.println("testing 1");
    myFile.println("testing 2");
    myFile.println("testing 3");
    myFile.println("testing 4");
    myFile.close();
    Serial.println("done");
  }
  else
    Serial.println("Error opening log.txt");

  myFile = SD.open("log.txt");
  if (myFile)
  {
    Serial.println("log.txt:");
    while(myFile.available())
    {
      Serial.write(myFile.read());
    }
    myFile.close();
  }
  else
    Serial.println("Error reading log.txt");

  myFile = SD.open("settings.txt");
  if (myFile)
  {
    Serial.println("Einstellungen:");
    while(myFile.available())
    {
      Serial.write(myFile.read());
    }
    myFile.close();
  }
  else 
    Serial.println("Error reading settings.txt");
}

void loop()
{
  
}

