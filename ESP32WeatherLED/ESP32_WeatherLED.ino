// By T. Amberg & K. Doan Quoc, licensed under MIT License
// based on BasicHTTPClient.ino by Espressif
// based on JSONKitchenSink.ino by Adafruit
// based on strandtest.ino by Adafruit

#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN    2
#define LED_COUNT 16

WiFiMulti wifiMulti;
JSONClass json;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // All pixels off
  strip.setBrightness(128); // max. 255

  Serial.begin(115200);
  wifiMulti.addAP("MY_SSID", "MY_PASSWORD"); // TODO
}

void setLight(int cond) {
  uint32_t color;
  if (cond == 500) { // light rain
    color = strip.Color(0, 255, 0); // green
  } else  if (cond == 502) { // heavy rain
    color = strip.Color(255, 0, 0); // red
  } else { // all other conditions
    color = strip.Color(0, 0, 0); // off
  }
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();                   
}

void loop() {
  if ((wifiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    Serial.print("[HTTP] sending request...\n");
    http.begin("http://api.openweathermap.org/data/2.5/weather?lon=LON&lat=LAT&APPID=API_KEY"); // TODO
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.printf("[HTTP] response code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        JSONVar var = json.parse(payload);
        int cond = var["weather"][0]["id"];
        Serial.println(cond);
        setLight(cond);
        delay(2 * 60 * 1000); // ms
      }
    } else {
      Serial.printf("[HTTP] request failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
  delay(5000); // ms
}
