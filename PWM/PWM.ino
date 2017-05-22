#include <PinChangeInterrupt.h>

const byte channel_pin[] = {2, 3, 4};
volatile unsigned long rising_start[] = {0,0,0};
volatile long channel_length[] = {0,0,0};

void setup() 
{
  Serial.begin(9600);
  pinMode(channel_pin[0], INPUT);
  pinMode(channel_pin[1], INPUT);
  pinMode(channel_pin[2], INPUT);

  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(channel_pin[0]), onRising0, CHANGE);
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(channel_pin[1]), onRising1, CHANGE);
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(channel_pin[2]), onRising2, CHANGE);
 
}

void loop() 
{
  Serial.print(channel_length[0]);
  Serial.print(" | ");
  Serial.print(channel_length[1]);
  Serial.print(" | ");
  Serial.print(channel_length[2]);
  Serial.println("");
  delay(100);
}

void processPin(byte pin)
{
  uint8_t trigger = getPinChangeInterruptTrigger(digitalPinToPCINT(channel_pin[pin]));
  if (trigger == RISING)
  {
    rising_start[pin] = micros();
  }
  else if (trigger == FALLING)
  {
    channel_length[pin] = micros() - rising_start[pin];
  }
}

void onRising0()
{
  processPin(0);
}

void onRising1()
{
  processPin(1);
}

void onRising2()
{
  processPin(2);
}

