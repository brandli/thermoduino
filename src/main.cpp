#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 Test!"));

  dht.begin();

  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%	"));
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}