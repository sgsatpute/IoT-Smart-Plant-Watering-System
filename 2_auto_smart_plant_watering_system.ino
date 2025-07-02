#define BLYNK_TEMPLATE_ID "TMPL3auC0QAky"
#define BLYNK_TEMPLATE_NAME "Smart irrigation system"
#define BLYNK_AUTH_TOKEN "RMmTHafd9Is0yAIJWQEkqJeFmpo5rqaH"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi and Blynk Authentication
char auth[] = "RMmTHafd9Is0yAIJWQEkqJeFmpo5rqaH";
char ssid[] = "Sa";  
char pass[] = "12345678";

// Pin Definitions
int sensorPin = A0;      
int relayPin = D0;       
int threshold = 40;      
bool autoMode = true;    
bool lowMoistureNotified = false; // Track notification status

// Blynk Manual Control for Pump (V3)
BLYNK_WRITE(V3) { 
  int buttonState = param.asInt();
  if (!autoMode) {
    digitalWrite(relayPin, buttonState == 1 ? LOW : HIGH);
    Serial.println(buttonState == 1 ? "Water pump turned ON (Manual)" : "Water pump turned OFF (Manual)");
  }
}

// Blynk Mode Switch: Automatic or Manual (V4)
BLYNK_WRITE(V4) {
  autoMode = param.asInt();
  if (autoMode) {
    Serial.println("Switched to Automatic Mode.");
  } else {
    digitalWrite(relayPin, HIGH); // Ensure pump is OFF initially
    Serial.println("Switched to Manual Mode. Use the switch to control the pump.");
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Ensure pump is initially OFF

  Serial.println("Setup complete. Connecting to Blynk...");
}

void loop() {
  Blynk.run();
  
  int moistureValue = analogRead(sensorPin); 
  int moisturePercentage = map(moistureValue, 1023, 0, 0, 100);
  Blynk.virtualWrite(V2, moisturePercentage);

  Serial.print("Moisture Level: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  // Immediate Notification when Moisture Drops Below Threshold
  if (moisturePercentage < threshold && !lowMoistureNotified) {
    Blynk.logEvent("lowmoisture", "Low Moisture Detected!");
    lowMoistureNotified = true; // Prevent spamming
    Serial.println("🚨 Immediate Notification Sent: Low Moisture!");
  }
  
  // Reset notification flag when moisture is sufficient
  if (moisturePercentage >= threshold) {
    lowMoistureNotified = false;
  }

  // Auto Mode - Control Pump Automatically
  if (autoMode) {
    if (moisturePercentage < threshold) {
      digitalWrite(relayPin, LOW); // Turn ON Pump
      Serial.println("Low moisture detected. Pump turned ON.");
    } else {
      digitalWrite(relayPin, HIGH); // Turn OFF Pump
      Serial.println("Sufficient moisture. Pump turned OFF.");
    }
  }
}
