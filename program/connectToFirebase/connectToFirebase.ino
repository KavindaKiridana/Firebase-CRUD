#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>


// Firebase helpers for handling authentication tokens and real-time database (RTDB) operations
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#include "credentials.h" //firebase and wifi credentials are here

// Firebase objects for authentication and database operations
FirebaseData fbdo;   // Firebase data object for sending/receiving data
FirebaseConfig config; // Firebase configuration object
FirebaseAuth auth;    // Firebase authentication object

void setup()
{
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // Start Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) // Wait until connected
  {
    Serial.print("."); // Print dots to indicate connection progress
    delay(500);
  }
  Serial.println("\nWi-Fi connected!");

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Option 1: Check if Firebase is ready (best way)
  if (Firebase.ready()) {
    Serial.println("Firebase connected successfully!");
  } else {
    Serial.println("Firebase connection failed!");
  }

//i commented this line bcz firebase esp client library have no function 'authError()' and it couse to an error
  // Option 2: If using Email/Password Auth, check signup status
  // if (Firebase.authError().code == 0) { // No error = success
  //   Serial.println("Firebase auth successful!");
  // } else {
  //   Serial.println("Firebase auth failed: " + Firebase.authError().message);
  // }
}

void loop()
{
  
}
