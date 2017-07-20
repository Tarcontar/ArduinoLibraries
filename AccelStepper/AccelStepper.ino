#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::DRIVER, 9, 8); 
int dist = 14000; 
float speed = 1000.0;
float acceleration = 6000.0;

int enablePin = 2;

void setup() 
{
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  pinMode(7, OUTPUT);
  digitalWrite(7,HIGH);

  stepper.setMaxSpeed(speed);
  stepper.setAcceleration(acceleration);
  stepper.setCurrentPosition(0);
  stepper.move(200000);
}

void loop() 
{

  stepper.run();
}
