#pragma once

class Button
{
	public:
		Button(int pin);
		Button(int pin, int led_pin);
		
		bool On();
		bool Off();
		bool SwitchedOn();
		bool SwitchedOff();

		void LEDOn();
		void LEDOff();

	private:

		int		m_pin;
		int		m_led_pin;
		bool		m_state;
		bool		m_last_state;
};
