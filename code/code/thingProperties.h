#pragma once

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <WiFi.h>

// --------- YOUR DETAILS ---------
const char DEVICE_LOGIN_NAME[]  = "d9e250cf-392a-4738-9a1d-e8092f379e94";
const char SSID[]               = "U";
const char PASS[]               = "THARUPABA";
const char DEVICE_KEY[]         = "E6YRmCfE38Rn9159l1vSNQx5B";

// --------- CLOUD VARIABLES ---------
float temperature;
float humidity;
int light;

// --------- CALLBACKS ---------
void onTemperatureChange() {}
void onHumidityChange() {}
void onLightChange() {}

// --------- CONNECTION ---------
WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

// --------- INIT ---------
void initProperties() {
  ArduinoCloud.setBoardId("d9e250cf-392a-4738-9a1d-e8092f379e94");
  ArduinoCloud.setSecretDeviceKey("E6YRmCfE38Rn9159l1vSNQx5B");

  ArduinoCloud.addProperty(temperature, READWRITE, ON_CHANGE, onTemperatureChange);
  ArduinoCloud.addProperty(humidity, READWRITE, ON_CHANGE, onHumidityChange);
  ArduinoCloud.addProperty(light, READWRITE, ON_CHANGE, onLightChange);
}
