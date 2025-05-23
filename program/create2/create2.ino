#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>

int no=1;

// Firebase helpers for handling authentication tokens and real-time database (RTDB) operations
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#include "credentials.h" //firebase and wifi credentials are here

// Firebase objects for authentication and database operations
FirebaseData fbdo;   // Firebase data object for sending/receiving data
FirebaseConfig config; // Firebase configuration object
FirebaseAuth auth;    // Firebase authentication object

bool signupOK = false;

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

  // Firebase setup
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback;

// Firebase authentication (Anonymous Signup)
  if (Firebase.signUp(&config, &auth, "", ""))// Attempt Firebase anonymous sign-up
  {
    Serial.println("Firebase connected!");
    signupOK = true;
  }
  else
  {
    // Print signup error message if failed
    Serial.printf("Firebase signup failed: %s\n", config.signer.signupError.message.c_str());
  }
  // Initialize Firebase with configuration and authentication
  Firebase.begin(&config, &auth);
}

void loop()
{
  char path[50];
  sprintf(path, "/values/%d", no); // Creates path like "/values/1"

  // Send integer data to Firebase Realtime Database (RTDB)
  if (Firebase.RTDB.setInt(&fbdo, path, no))// Write the value of variable 'no'
  {
    Serial.println("Data Sent!"); // Print success message
  }
  else
  {
    // Print error message if data writing fails
    Serial.println("Failed: " + fbdo.errorReason());
  }
  no++;
  delay(1000); // Send data every  seconds
}
