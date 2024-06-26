#include <SPI.h>
#include <WiFi101.h>

char ssid[] = "NyarAsembo"; // your existing WiFi network SSID
char pass[] = "Asembo@2023"; // your existing WiFi network password

char apSSID[] = "NyarAsembo_EXT"; // desired access point SSID (name)
char apPass[] = "Asembo@2023"; // desired access point password

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Connect to existing WiFi network
  Serial.print("Connecting to WiFi network: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected to existing network");

  // Configure MKR 1010 as an access point
  Serial.print("Setting up access point: ");
  Serial.println(apSSID);
  WiFi.beginAP(apSSID, apPass);
  while (WiFi.status() != WL_AP_LISTENING) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nAccess point set up");

  // Initialize server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        client.write(c); // Echo back to client
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }

  // Check WiFi signal strength every 10 seconds
  static unsigned long lastCheckTime = 0;
  if (millis() - lastCheckTime >= 10000) {
    int32_t rssi = WiFi.RSSI();
    Serial.print("WiFi Signal Strength (RSSI): ");
    Serial.print(rssi);
    Serial.println(" dBm");
    lastCheckTime = millis();
  }
}
