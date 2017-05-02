#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::FULL4WIRE, 8, 9); 
int dist = 14000; 
float speed = 1800.0;
float acceleration = 6000.0;

int enablePin = 2;

void setup() 
{
  Serial.begin(9600);

  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
  stepper.setMaxSpeed(speed);
  stepper.setAcceleration(acceleration);
  stepper.setCurrentPosition(0);
  stepper.move(dist);
}

void loop() 
{
  stepper.run();
}
