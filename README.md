# GPS System
This GPS system is designed to calculate the distance between two points on the earth's surface using a GPS module and a TM4C123GH6PM microcontroller. The program reads data from the GPS module, calculates the distance between the current location and the destination location, and turns on an LED based on that distance.

## Hardware Requirements
To use this system, you will need:

- A GPS module
- A TM4C123GH6PM microcontroller
- Jumper wires
- USB 2.0 Micro-B

## Setup
To set up the hardware:

1. Connect the GPS module to the microcontroller using a UART connection.
2. Connect the LED to the microcontroller.
3. Upload the code to the microcontroller.

## How it works
The program reads data from the GPS module using the UART connection and parses it to obtain the current latitude and longitude. It then uses the Haversine formula to calculate the distance between the current location and the destination location.

The LED turns green when the distance is less than 0.5 meters from the destination, yellow when the distance is between 0.5 and 5 meters from the destination, and red when the distance is more than 5 meters from the destination.

## Code Files
- `main.c`: This file contains the main code for the GPS system. It initializes the UART and LED, and reads data from the GPS module. It then calculates the distance to the destination and turns on the LED accordingly.

- `GPIO.h` and `GPIO.c`: These files contain functions for initializing and controlling the LED.

- `UART.h` and `UART.c`: These files contain functions for initializing and reading data from the GPS module using UART.

- `GPS.h` and `GPS.c`: These files contain functions for parsing the GPS data and calculating the distance using the Haversine formula.

- `stdint.h`, `math.h`, `stdlib.h`, `stdio.h`, and `string.h`: These are standard C libraries used in the program.

## Usage
To use the system:

1. Turn on the GPS module and the microcontroller.
2. Wait for the LED to turn green to indicate that the destination has been reached.
3. If the LED turns yellow, you are getting close to the destination. If the LED turns red, you are far from the destination.

