#include <Arduino.h>


int trigPin = 9;
int echoPin = 10;

long duration;
long distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
/**
 * @file Ultrasonic_Distance_Measurement.ino
 * @brief Distance measurement using Ultrasonic Sensor (HC-SR04)
 * @details
 * This program measures distance using an ultrasonic sensor.
 * The sensor sends an ultrasonic pulse and calculates the time
 * taken for the echo to return. Distance is computed using
 * the speed of sound formula.
 *
 * @author Lakshay Bindal
 * @version 1.0
 * @date 27-02-2026
 *
 * @section hardware_sec Hardware Connections
 * - Trig Pin  → Digital Pin 9
 * - Echo Pin  → Digital Pin 10
 * - VCC       → 5V
 * - GND       → GND
 *
 * @section working_sec Working Principle
 * 1. Trigger pin sends a 10µs HIGH pulse.
 * 2. Ultrasonic wave is transmitted.
 * 3. Echo pin receives reflected wave.
 * 4. pulseIn() measures travel time.
 * 5. Distance is calculated using:
 *
 *    Distance = (Time × Speed of Sound) / 2
 *
 * Speed of Sound = 0.0343 cm/µs
 *
 * @note Distance is displayed in centimeters.
 * @warning Ensure object surface properly reflects sound waves.
 */

#include <Arduino.h>

/** @brief Digital pin connected to Trig */
int trigPin = 9;

/** @brief Digital pin connected to Echo */
int echoPin = 10;

/** @brief Stores echo pulse duration */
long duration;

/** @brief Stores calculated distance in cm */
long distance;


/**
 * @brief Initializes ultrasonic sensor pins and Serial communication
 */
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


/**
 * @brief Main loop function
 * @details
 * Sends ultrasonic pulse and calculates distance.
 */
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
