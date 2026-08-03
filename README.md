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

## Getting an API key
- Create an account at https://openweathermap.org
- Get an API key enabling 1k free calls per day (according to the [docs](https://openweathermap.org/api/one-call-4?collection=one_call_api))
- Test the API by replacing LAT, LON and API_KEY in this template URL
  ```
  https://api.openweathermap.org/data/4.0/onecall/current?lat=LAT&lon=LON&appid=API_KEY
  ```

## Uploading code
- Go to _Select other board and port..._
- Select board _DOIT ESP32 DEVKIT V1_
- Select port _COM3_ (or similar)
- Click _Sketch > Upload_ (or →)
