#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
	// Set baud rate
  Serial.begin(115200);

  // Error message if MPU6050 not detected, halt until chip found
	if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) delay(10);
  }

  // Set accelerometer and gyroscope ranges (see datasheet)
	mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
	mpu.setGyroRange(MPU6050_RANGE_250_DEG);
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

	delay(100);
}

void loop() {
  // Get sensor events
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

  // Print acceleration data  
	Serial.print("Acceleration X: "); Serial.print(a.acceleration.x);
	Serial.print(", Y: "); Serial.print(a.acceleration.y);
	Serial.print(", Z: "); Serial.print(a.acceleration.z);
	Serial.println(" m/s^2");

  // Print gyroscope data  
	Serial.print("Rotation X: "); Serial.print(g.gyro.x);
	Serial.print(", Y: "); Serial.print(g.gyro.y);
	Serial.print(", Z: "); Serial.print(g.gyro.z);
	Serial.println(" rad/s");

  // Print temperature data
	Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degC");

	delay(5000);
}