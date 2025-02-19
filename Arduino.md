# Ardunio Hardware

One goal was to reduce software stacks which is why the input-only controls are HID and configured in MSFS.  ChatGPT wrote those the software software, it’s a marvelous tool for handling details and learning.

With FS2024 I may use MobiFlight or spad.next to better map and maintain.

## Three Arduinos cover all input-only controls using the Joystick library.  The project includes code for each:
* Arduino Pro Throttle, Switch, TOGA, Carb Heat
* Arduino Micro Pro Trim and Flaps
* Arduino Micro Pro Parking Brake, Key/Start, Fuel Selector, and Rudder Trim

### Arduino Joystick

# Switch-Throttle Micro Pin Mapping

This table documents the pin assignments and controls for the switch-throttle micro setup.

## Switch-Throttle - Micro
| PIN   | USB | WIRE-COLOR | Cable   |
|-------|-----|------------|---------|
| D13   |     | Pitot Off  | green   |
| 3V    | AREF|            |         |
| A0    |     | Throttle   | green   |
| A1    |     | Mixture    | yellow  |
| A2    |     | Prop       | orange  |
| A3    |     | Carb Heat On| blue    |
| A4    |     | Carb Heat Off| purple  |
| A5    | NC  |            |         |
| 5V    |     | 5V         | red     |
| GND   |     | GND        | brown   |
| VIN   |     |            |         |
| D14   |     | GA         | brown   |
| D15   |     | Nav Off    | orange  |
| D12   |     | Avionics On| white   |
| D11   |     | Avionics Off| grey    |
| D10   |     | Master On  | purple  |
| D9    |     | Master Off | blue    |
| D8    |     | Fuel On    | green   |
| D7    |     | Fuel Off   | yellow  |
| D6    |     | Landing On | orange  |
| D5    |     | Beacon On  | brown   |
| D4    |     | Beacon Off | white   |
| D3    |     | Collision On| grey    |
| D2    |     | Landing On | red     |
| GND   |     | GND        | black   |
| RESET |     |            |         |
| D0    |     | Collision Off| purple  |
| D1    |     | Pitot On   | blue    |
| D17   |     |            |         |
| D16   |     | Nav On     | yellow  |

## Brake-Fuel Pro Micro
| TX/RX/GND | Key |        | Cable  |
|-----------|-----|--------|--------|
| GND       |     |        | black  |
|           | +   | Brake  |        |
| GND       |     |        | grey   |
| D2        | Off |        | purple |
| D3        | A   |        | blue   |
| A6/D4     | B   |        | green  |
| D5        | Run |        | yellow |
| A7/D6     | Start|        | orange |
| D7        |     |        |        |
| A8/D8     |     | Rudder Trim| orange |
| A9/D9     |     | 7-12V  |        |
| GND       |     | GND    | black  |
| RST       |     | 5V     | orange |
| A3/D21    |     | Fuel Off| brown  |
| A2/D20    |     | Left Tip | red    |
| A1/D19    |     | Left Main| orange |
| A0/D18    |     | Right Main| yellow |
| D15       |     | Right Tip| green  |
| D14       | Off | Park   | yellow |
| D16       | On  | Park   | red    |
| A10/D10   |     |        |        |

## Trim-Flaps Pro Micro
| TX/RX/GND | Trim/Flaps |     | Cable  |
|-----------|------------|-----|--------|
| GND       |            |     | black  |
| D2        | 0          | Flaps| white  |
| D3        | 1          | Flaps| grey   |
| A6/D4     | 3          | Flaps| purple |
| D5        | 4          | Flaps| blue   |
| A7/D6     |            |     |        |
| D7        |            |     |        |
| A8/D8     |            | Trim | black  |
| A9/D9     |            | 7-12V|        |
| GND       |            | RST  |        |
| 5V        |            |     |        |
| A3/D21    |            |     |        |
| A2/D20    |            |     |        |
| A1/D19    |            |     |        |
| A0/D18    |            |     |        |
| D15       |            |     |        |
| D14       |            |     |        |
| D16       |            |     |        |
| A10/D10   |            |     |        |

## Compass Pro Micro
| TX/RX/GND |      |        | Cable    |
|-----------|------|--------|----------|
| GND       |      |        |          |
| D2        |      |        |          |
| D3        |      |        |          |
| A6/D4     |      |        |          |
| D5        |      |        |          |
| A7/D6     |      |        |          |
| D7        |      |        |          |
| A8/D8     |      |        |          |
| A9/D9     |      | 7-12V  |          |
| GND       |      | GND    | Compass  |
| RST       |      | 5V     |          |
| 5V        |      |        |          |
| A3/D21    | IN1  | Compass|          |
| A2/D20    | IN2  | Compass|          |
| A1/D19    | IN3  | Compass|          |
| A0/D18    | IN4  | Compass|          |
| D15       |      |        |          |
| D14       |      |        |          |
| D16       |      |        |          |
| A10/D10   |      |        |          |

## HID to Microsoft FS Control
### Switch-Throttle - Micro

| Control             | Button | FS-Control             |
|----------------------|--------|------------------------|
| Throttle             | x      | Throttle Axis          |
| Mixture              | y      | Mixture Axis           |
| Propeller Axis       | z      | Propeller Axis         |
| Avionics Master 1 On | 2      | Avionics Master 1 On   |
| Avionics Master 1 Off| 1      | Avionics Master 1 Off  |
| Master Battery On    | 4      | Master Battery On      |
| Master Battery Off   | 3      | Master Battery Off     |
| Set Electric Fuel Pump| 6      | Set Electric Fuel Pump |
| Set Electric Fuel Pump Off | 5   | Set Electric Fuel Pump Off |
| Landing Lights On    | 8      | Landing Lights On      |
| Landing Lights Off   | 7      | Landing Lights Off     |
| Beacon Lights On     | 10     | Beacon Lights On       |
| Beacon Lights Off    | 9      | Beacon Lights Off      |
| Strobes On           | 12     | Strobes On             |
| Strobes Off          | 11     | Strobes Off            |
| Pitot Heat On        | 14     | Pitot Heat On          |
| Pitot Heat Off       | 13     | Pitot Heat Off         |
| Nav Lights On        | 16     | Nav Lights On          |
| Nav Lights Off       | 15     | Nav Lights Off         |
| Set Anti Ice On      | 18     | Set Anti Ice On        |
| Set Anti Ice Off     | 17     | Set Anti Ice Off       |
| Auto Throttle to GA  | 19     | Auto Throttle to GA    |

### Brake-Fuel Pro Micro

| Control              | Key | FS-Control                |
|-----------------------|-----|---------------------------|
| Magnetos Off          | 1   | Magnetos Off              |
| Magnetos Left         | 2   | Magnetos Left             |
| Magnetos Right        | 3   | Magnetos Right            |
| Magnetos Both         | 4   | Magnetos Both             |
| Magnetos Start        | 5   | Magnetos Start            |
| Parking Brakes On     | 6   | Parking Brakes On         |
| Parking Brakes Off    | 7   | Parking Brakes Off        |
| Fuel Selector 1 Off   | 8   | Fuel Selector 1 Off       |
| Fuel Selector 1 Left Aux | 9   | Fuel Selector 1 Left Aux  |
| Fuel Selector 1 Left  | 10  | Fuel Selector 1 Left      |
| Fuel Selector 1 Right | 11  | Fuel Selector 1 Right     |
| Fuel Selector 1 Right Aux| 12  | Fuel Selector 1 Right Aux |
| Rudder Axis           | z   | Rudder Axis               |

### Trim-Flaps Pro Micro

| Control              | Trim/Flaps | FS-Control             |
|-----------------------|------------|------------------------|
| Set Elevator Trim Axis | x          | Set Elevator Trim Axis |
| Retract Flaps          | 04         | Retract Flaps          |
| Flaps 1                | 103        | Flaps 1                |
| Flaps 2                | 302        | Flaps 2                |
| Flaps 3                | 451        | Flaps 3                |
