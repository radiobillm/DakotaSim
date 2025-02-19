#Ardunio

### Arduino Joystick

## Three Arduinos cover all input-only controls using the Joystick library.  The project includes code for each:

* Arduino Pro Throttle, Switch, TOGA, Carb Heat
* Arduino Micro Pro Trim and Flaps
* Arduino Micro Pro Parking Brake, Key/Start, Fuel Selector, and Rudder Trim

### One goal was to reduce software stacks which is why the input-only controls are HID and configured in MSFS.  ChatGPT wrote those three software, it’s a marvelous tool for handling details and learning.

With FS2024 I may use MobiFlight or spad.next to better map and maintain.

# Switch-Throttle Micro Pin Mapping

This table documents the pin assignments and controls for the switch-throttle micro setup.

| R1 Color | Pin 1 | Pin 2 | R1 Color | Control |
|----------|------|------|----------|---------|
|          |      |      |          | **USB** |
| Green    | D13  |      | D12      | Pitot Off / Avionics On |
|          | 3V   |      | D11      | Avionics Off |
|          | AREF |      | D10      | Master On |
| Red      | A0   | Green | D9       | Throttle / Master Off |
| Brown    | A1   | Yellow | D8       | Mixture / Fuel On |
|          | A2   | Orange | D7       | Prop / Fuel Off |
| Blue     | A3   |       | D6       | Carb Heat On / Landing On |
| Purple   | A4   |       | D5       | Carb Heat Off / Beacon On |
|          | A5   |       | D4       | Beacon Off |
|          | NC   |       | D3       | Collision On |
|          | NC   |       | D2       | Landing On |
| Red      | 5V   |       | GND      | 5V / GND |
|          | RESET |      | RESET    | Reset |
| Brown    | GND  |       | D0       | GND / Collision Off |
|          | VIN  |       | D1       | Pitot On |
| Black    | D14  | Brown | D17      | GA |
| Orange   | D15  |       | D16      | Nav Off / Nav On |

---
_Last updated: February 2025_

