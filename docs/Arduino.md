# Ardunio Hardware

Before this project, I had no prior experience with Arduino or circuit board assembly.  

Initially, I soldered IDC ribbon cables directly to the Arduino pins, using a separate connector for each control. Later, for the two additional Arduino Pros, I switched to using connectors soldered on the Arduino.

Renaming the USB HID device requires updating the boards.txt file, one is included.

See the software info

## Pin Mapping and Wire Bundles

This table documents the pin assignments and controls for the switch-throttle micro setup.

### Switch-Throttle - Micro

| PIN | USB | WIRE-COLOR     | Cable    |
|-----|-----|----------------|----------|
| D13  |     | Pitot Off      | green    |
| 3V   | AREF|                |          |
| A0   |     | Throttle       | green    |
| A1   |     | Mixture        | yellow   |
| A2   |     | Prop           | orange   |
| A3   |     | Carb Heat On   | blue     |
| A4   |     | Carb Heat Off  | purple   |
| A5   | NC  |                |          |
| 5V   |     | 5V             | red      |
| GND  |     | GND            | brown    |
| VIN  |     |                |          |
| D14  |     | GA             | brown    |
| D15  |     | Nav Off        | orange   |
| D12  |     | Avionics On    | white    |
| D11  |     | Avionics Off   | grey     |
| D10  |     | Master On      | purple   |
| D9   |     | Master Off     | blue     |
| D8   |     | Fuel On        | green    |
| D7   |     | Fuel Off       | yellow   |
| D6   |     | Landing On     | orange   |
| D5   |     | Beacon On      | brown    |
| D4   |     | Beacon Off     | white    |
| D3   |     | Collision On   | grey     |
| D2   |     | Landing On     | red      |
| GND  |     | GND            | black    |
| RESET|     |                |          |
| D0   |     | Collision Off  | purple   |
| D1   |     | Pitot On       | blue     |
| D17  |     |                |          |
| D16  |     | Nav On         | yellow   |


### Brake-Fuel Pro Micro

| PIN     | USB | WIRE-COLOR     | Cable    |
|---------|-----|----------------|----------|
| TX/RX/GND|     | black          | Key+Brake|
| GND     |     | grey           | Key      |
| D2      |     | purple         | Key      |
| D3      |     | blue           | Key      |
| A6/D4   |     | green          | Key      |
| D5      |     | yellow         | Key      |
| A7/D6   |     | orange         | Key      |
| D7      |     |                |          |
| A8/D8   |     | orange         | Rudder   |
| A9/D9   |     |                | 7-12V    |
| GND     |     | black          | Rudder   |
| RST     | 5V  | orange         | Rudder   |
| A3/D21  |     | brown          | Fuel     |
| A2/D20  |     | red            | Fuel     |
| A1/D19  |     | orange         | Fuel     |
| A0/D18  |     | yellow         | Fuel     |
| D15     |     | green          | Fuel     |
| D14     |     | yellow         | Park     |
| D16     |     | red            | Park     |
| A10/D10 |     |                |          |


### Trim-Flaps Pro Micro

| PIN     | USB | WIRE-COLOR     | Cable    |
|---------|-----|----------------|----------|
| TX/RX/GND| GND | black          | Flaps    | 
| D2      |     | white          | Flaps    |
| D3      |     | grey           | Flaps    |
| A6/D4   |     | purple         | Flaps    |
| D5      |     | blue           |          |
| A7/D6   |     |                |          |
| D7      |     |                |          |
| A8/D8   |     | black          | Trim     |
| A9/D9   |     |                | 7-12V    |
| GND     | RST |                |          |
| 5V      |     |                |          |
| A3/D21  |     |                |          |
| A2/D20  |     |                |          |
| A1/D19  |     |                |          |
| A0/D18  |     |                |          |
| D15     |     |                |          |
| D14     |     |                |          |
| D16     |     |                |          |
| A10/D10 |     |                |          |


### Compass Pro Micro

| PIN     | USB | WIRE-COLOR     | Cable    |
|---------|-----|----------------|----------|
| TX/RX/GND|     |                |          |
| GND     |     |                | Compass  |
| D2      |     |                |          |
| D3      |     |                |          |
| A6/D4   |     |                |          |
| D5      |     |                |          |
| A7/D6   |     |                |          |
| D7      |     |                |          |
| A8/D8   |     |                |          |
| A9/D9   |     |                | 7-12V    |
| GND     | RST | 5V             |          |
| 5V      |     |                |          |
| A3/D21  |     |                | Compass  |
| A2/D20  |     |                | Compass  |
| A1/D19  |     |                | Compass  |
| A0/D18  |     |                | Compass  |
| D15     |     |                |          |
| D14     |     |                |          |
| D16     |     |                |          |
| A10/D10 |     |                |          |
