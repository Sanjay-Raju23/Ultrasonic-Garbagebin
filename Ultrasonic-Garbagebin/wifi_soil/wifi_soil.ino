// Include the necessary libraries
#include <ESP8266WiFi.h>

// Define the pin for the soil moisture sensor
const int soilMoisturePin = 2; // Change pin number to D2

// Define the threshold value for moisture
const int moistureThreshold = 500; // Adjust this value based on your sensor calibration

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin("mi 11x", "1234567890");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Read the analog value from the soil moisture sensor
  int moistureValue = digitalRead(soilMoisturePin); // Changed digitalRead to analogRead

  // Print the raw moisture value for reference
  Serial.print("Moisture Level: ");
  Serial.println(moistureValue);

  // Compare the moisture value with the threshold
  if (moistureValue < moistureThreshold) {
    // Soil is dry, needs watering
    Serial.println("Soil is dry. Please water the plant!");
  } else {
    // Soil is moist
    Serial.println("Soil is moist. No need to water.");
  }

  // Wait for a moment before taking another reading
  delay(1000);
}
