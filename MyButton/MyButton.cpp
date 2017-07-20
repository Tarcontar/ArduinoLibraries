#include "MyButton.h"
#include <Arduino.h>

Button::Button(int pin, bool inverted) : m_pin(pin), m_inverted(inverted)
{
	pinMode(m_pin, INPUT);
	Read();
}

Button::Button(int pin, int led_pin, bool inverted) : Button(pin, inverted)
{
	m_led_pin = led_pin;
	pinMode(m_led_pin, OUTPUT);
	LEDOn();
}

bool Button::On()
{
	Read();
	return m_last_state == HIGH;
}

bool Button::Off()
{
	Read();
	return m_last_state == LOW;
}

bool Button::SwitchedOn()
{
	if (m_last_state == HIGH)
	{
		Read();
		return false;
	}
	Read();
	if (m_last_state == HIGH)
	{
		return true;
	}
	return false;
}

bool Button::SwitchedOff()
{
	if (m_last_state == LOW)
	{
		Read();
		return false;
	}
	Read();
	if (m_last_state == LOW)
	{
		return true;
	}
	return false;
}

void Button::LEDOn()
{
	digitalWrite(m_led_pin, HIGH);
}

void Button::LEDOff()
{
	digitalWrite(m_led_pin, LOW);
}

void Button::Read()
{
	//TODO: use m_inverted here
	m_last_state = digitalRead(m_pin);
}