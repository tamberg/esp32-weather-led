# ESP32 Weather LED
ESP32-based weather-indicating color LED.

Initiated by [Kim](https://www.kimdoanquoc.studio) at [HomeMade 2026](https://mechatronicart.ch/homemade-summercamp-girlen-2026/).

## Wiring electrical components
<img width="540" alt="weather-led" src="https://github.com/user-attachments/assets/f997916a-2d1d-4dcb-979e-e51696095284" />

## Setting up Arduino IDE
- Install the Arduino IDE (integrated development environment) 2.x from https://arduino.cc
- Go to _File > Preferences > Additional board manager URLs_ and add this line:
    ```
    https://dl.espressif.com/dl/package_esp32_index.json
    ```
- Close and reopen the Arduino IDE
- Go to _Tools > Board > Boards manager_
- Type _esp32_ (by Espressif Systems)
- Click _Install_ (newest version)

## Installing Arduino libraries
- ...

## Getting a weather API key
- Create an account at https://openweathermap.org
- Get a free API key allowing 1'000 calls per day (see [pricing](https://openweathermap.org/price))

## Making an API request
- Replace LAT, LON and API_KEY in this template URL (see [docs](https://openweathermap.org/api/one-call-4?collection=one_call_api))
  ```
  https://api.openweathermap.org/data/4.0/onecall/current?lat=LAT&lon=LON&appid=API_KEY
  ```
- Paste the modified URL into your browser address bar
- Read the result, a document formatted in JSON
- Find the weather condition, e.g. _"cond": 500_

## Preparing the code
- Open the [ESP32_WeatherLED.ino](ESP32WeatherLED/ESP32_WeatherLED.ino) source code in the Arduino IDE
- Replace _MY_SSID_ and _MY_PASSWORD_ with your Wi-Fi Credentials
- Replace _LAT_, _LON_ and _API_KEY_ with your location and key

## Uploading the code
- Go to _Select other board and port..._
- Select board _DOIT ESP32 DEVKIT V1_
- Select port _COM3_ (or similar)
- Click _Sketch > Upload_ (or →)
