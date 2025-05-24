#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>

// Firebase helpers
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#include "credentials.h" //firebase and wifi credentials are here

// Firebase objects
FirebaseData fbdo;
FirebaseConfig config;
FirebaseAuth auth;

  

bool signupOK = false;

void setup()
{
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected!");

  // Firebase setup
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback;

  if (Firebase.signUp(&config, &auth, "", ""))
  {
    Serial.println("Firebase connected!");
    signupOK = true;
  }
  else
  {
    Serial.printf("Firebase signup failed: %s\n", config.signer.signupError.message.c_str());
  }
  
  Firebase.begin(&config, &auth);
}

void loop()
{
  if (Firebase.ready() && signupOK)
  {
    // Read integer data from Firebase
    if (Firebase.RTDB.getInt(&fbdo, "/test/value")) 
    {
      int value = fbdo.intData();
      Serial.print("Read value: ");
      Serial.println(value);
    }
    else
    {
      Serial.println("Failed to read: " + fbdo.errorReason());
    }
  }  
  delay(2000); // Read every 2 seconds
}