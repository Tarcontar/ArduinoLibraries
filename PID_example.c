float Kp = 0.01;
float Ki = 0.01;
float Kd = 0.001;

float error = 0;
float last_error = 0;
float integral = 0;
float derivative = 0;

float target_position = 10;

while(1)
{
	float current_position = getPosition();
	error = target_position - current_position;
	
	integral += error;
	
	derivative = error - last_error;
	
	value = (Kp * error) + (Ki * integral) + (Kd * derivative);
	
	last_error = error;
}