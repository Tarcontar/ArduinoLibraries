#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) : m_pin(pin)
{
	pinMode(m_pin, INPUT_PULLUP);
	m_last_state = digitalRead(m_pin);
}

Button::Button(int pin, int led_pin) : Button(pin)
{
	m_led_pin = led_pin;
	pinMode(m_led_pin, OUTPUT);
	digitalWrite(m_led_pin, HIGH);
}

bool Button::On()
{
	m_last_state = digitalRead(m_pin);
	return m_last_state == HIGH;
}

bool Button::Off()
{
	m_last_state = digitalRead(m_pin);
	return digitalRead(m_pin) == LOW;
}

bool Button::SwitchedOn()
{
	if (m_last_state == HIGH)
		return false;
	if (digitalRead(m_pin) == HIGH)
	{
		return true;
	}
}

bool Button::SwitchedOff()
{
	if (m_last_state == LOW)
		return false;
	if (digitalRead(m_pin) == LOW)
	{
		return true;
	}
}

void Button::LEDOn()
{
	digitalWrite(m_led_pin, HIGH);
}

void Button::LEDOff()
{
	digitalWrite(m_led_pin, LOW);
}