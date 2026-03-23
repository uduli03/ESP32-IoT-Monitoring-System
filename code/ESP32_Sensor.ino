#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
#include "thingProperties.h"

// ----------------- OLED -----------------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ----------------- DHT22 -----------------
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ----------------- LDR -----------------
#define LDR_PIN 18

// ----------------- Setup Sensors -----------------
void setupSensors() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed!");
    while (1);
  }
  display.clearDisplay();

  dht.begin();
  pinMode(LDR_PIN, INPUT);
}

// ----------------- Update Sensors -----------------
void updateSensors() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int lightState = digitalRead(LDR_PIN);

  if (!isnan(temp) && !isnan(hum)) {
    temperature = temp;
    humidity = hum;
    light = lightState;
  }

  // OLED display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");

  display.setCursor(0, 20);
  display.print("Humidity: ");
  display.print(hum);
  display.println(" %");

  display.setCursor(0, 40);
  display.print("Light: ");
  display.println(lightState == HIGH ? "Dark" : "Bright");

  display.display();

  // Serial Monitor
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C  Hum: ");
  Serial.print(hum);
  Serial.print(" %  Light: ");
  Serial.println(lightState == HIGH ? "Dark" : "Bright");
}

// ----------------- MAIN SETUP -----------------
void setup() {
  Serial.begin(115200);
  delay(1500);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  setupSensors();
}

// ----------------- MAIN LOOP -----------------
void loop() {
  ArduinoCloud.update();
  updateSensors();
  delay(2000);
}
