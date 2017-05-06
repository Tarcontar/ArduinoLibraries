//Bosch bmi160
#include <BMI160Gen.h>


void setup() {
 Serial.begin(9600);
 while(!Serial);

 Serial.println("Initializing IMU device...");
 if (!BMI160.begin(BMI160GenClass::SPI_MODE, /*SS pin# = */10))
 {
  Serial.println("failed");
  return;
 }
 //BMI160.begin(BMI160GenClass::I2C_MODE);
 uint8_t dev_id = BMI160.getDeviceID();
 Serial.print("DEVICE ID: ");
 Serial.println(dev_id, HEX);

 //Set the accelerometer range to 250 degrees/second
 BMI160.setGyroRange(250);
 Serial.println("Initializing IMU device...done.");
}


void loop() {
 int gxRaw, gyRaw, gzRaw; //raw gyro values
 float gx, gy, gz;

 //read raw gyro measurements from device
 BMI160.readGyro(gxRaw, gyRaw, gzRaw);

 //convert the raw gyro data to degrees/second
 gx = convertRawGyro(gxRaw);
 gy = convertRawGyro(gyRaw);
 gz = convertRawGyro(gzRaw);

 //display tab_seperated gyro x/y/z values
 Serial.print("g:\t");
 Serial.print(gx);
 Serial.print("\t");
 Serial.print(gy);
 Serial.print("\t");
 Serial.print(gz);
 Serial.println();

 delay(500);
}

float convertRawGyro(int gRaw)
{
  //since we are using 250 degrees/second range

  float g = (gRaw * 250.0) / 32768.0;
  return g;
}

