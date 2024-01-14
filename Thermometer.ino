#include <Servo.h>
const int tempPin = A1; 
const int servoPin = 9;  


Servo myServo; 


float readTemperature() {

int tempReading = analogRead(tempPin);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
    float voltage = tempReading * 5.0;
    voltage /= 1024.0; 
    // Convert the voltage to temperature (in Celsius)
    float temperatureC = voltage * 100 ; // Change this formula based on your thermistor
    return temperatureC;
}

void setup() {
    Serial.begin(9600);        // Start the serial communication
    myServo.attach(servoPin);  // Attaches the servo on the servoPin to the servo object
}

void loop() {
    float temperature = readTemperature();
    // Map the temperature to the servo position
    int servoPos = map(temperature, 0, 50, 0, 180); // Change 0, 50 to your temperature range
    // Restrict the servo position to valid range
    servoPos = min(servoPos, 180);
    servoPos = max(servoPos, 0);
    myServo.write(servoPos); // Tell servo to go to position in variable 'servoPos'

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(1000); // Waits 1s for the servo to reach the position
}
