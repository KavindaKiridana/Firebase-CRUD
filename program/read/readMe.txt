
This Arduino sketch demonstrates how to read data from **Firebase Realtime Database** using an **ESP8266** (NodeMCU or similar). 

---

## **📌 Prerequisites**  
Before uploading this code, ensure you have:  

### **1. Required Libraries**  
Install these libraries in the **Arduino IDE**:  
- **ESP8266WiFi** (Included with ESP8266 Board Package)  
- **Firebase ESP Client** by **Mobizt** (Install via **Library Manager**)  

### **2. Board Setup**  
- Select **NodeMCU 1.0 (ESP-12E Module)** in **Tools > Board**  
- Set the correct **COM port**  

### **3. Firebase Setup**  
- Create a **Firebase project** at [Firebase Console](https://console.firebase.google.com/)  
- Enable **Realtime Database** (in test mode or with proper security rules)  
- Get your **API Key** and **Database URL**  

---

## **🔧 How to Use**  

### **1. Create `credentials.h` File** 
1. In the same folder as `create.ino`, create a new file named `credentials.h`.  
2. Add the following content (replace with your actual credentials):  

```cpp
// credentials.h - Keep this file secure
// Wi-Fi credentials
#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASSWORD "Your_WiFi_Password"

// Firebase credentials
#define API_KEY "Your_Firebase_API_Key"
#define DATABASE_URL "Your_Firebase_Database_URL"
```

### **2. Upload the Code**  
1. Open `create.ino` in Arduino IDE.  
2. Verify & Upload to your ESP8266.  
3. Open **Serial Monitor (115200 baud)** to check logs.  

---

## **📝 Expected Output**  
If successful, the Serial Monitor will show:  
```
Wi-Fi connected!  
Firebase connected!  
Data Sent!  
Data Sent!  
... (repeats every second)
```

If there’s an error, it will display:  
```
Failed: [Error Reason]
```

---

## **⚠️ Troubleshooting**  
- **Wi-Fi Not Connecting?**  
  - Check `WIFI_SSID` & `WIFI_PASSWORD` in `credentials.h`.  
  - Ensure the ESP8266 is in range.  

- **Firebase Connection Failed?**  
  - Verify `API_KEY` and `DATABASE_URL`.  
  - Check Firebase **Realtime Database Rules** (allow read/write if in test mode).  

- **Library Errors?**  
  - Reinstall **Firebase ESP Client** via **Library Manager**.  

