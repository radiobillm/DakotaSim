# Ardunio Software

One goal was to reduce software stacks which is why the input-only controls are HID and configured in MSFS.  ChatGPT wrote those the software software, it’s a marvelous tool for handling details and learning.

With FS2024 I may use MobiFlight or spad.next to better map and maintain.

## Three Arduinos cover all input-only controls using the Joystick library.  The project includes code for each:
* Arduino Pro Throttle, Switch, TOGA, Carb Heat
* Arduino Micro Pro Trim and Flaps
* Arduino Micro Pro Parking Brake, Key/Start, Fuel Selector, and Rudder Trim

Arduino Joystick

## HID to Microsoft FS Controls

### Switch-Throttle
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

### Brake-Fuel
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

### Trim-Flaps
| Control              | Trim/Flaps | FS-Control             |
|-----------------------|------------|------------------------|
| Set Elevator Trim Axis | x          | Set Elevator Trim Axis |
| Retract Flaps          | 04         | Retract Flaps          |
| Flaps 1                | 103        | Flaps 1                |
| Flaps 2                | 302        | Flaps 2                |
| Flaps 3                | 451        | Flaps 3                |
