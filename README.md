Automated_public_lighting_system
This project demonstrates a smart public lighting system controlled by an Arduino Uno and integrated with a web interface. The system utilizes light detection sensors to automatically control the lighting based on ambient light levels. In case of faults or issues, the system can send alerts via SMS using a GSM module.

Components Used
Arduino Uno
BH1750 Ambient Light Sensor
ZMPT101B Voltage Sensor
GSM Module
Various electronic components (resistors, LEDs, etc.)
Project Structure
The project includes the following components:

Arduino Code (public_lighting_system.ino): Arduino sketch responsible for reading light and voltage values, controlling the light, and sending SMS alerts.

Web Interface:

index.html: Landing page with a welcome message and a link to the details page.
details.html: Details page displaying real-time light status, voltage, fault status, and controls.
style.css: CSS file for styling the web interface.
script.js: JavaScript file to fetch data from the server and update the web interface dynamically.
Server (server.js): Node.js server to receive data from Arduino via serial port, expose an API endpoint (/data) to fetch sensor values, and serve the web interface.

Setup and Usage
Arduino Setup:

Connect the BH1750 and ZMPT101B modules to the Arduino Uno.
Upload the public_lighting_system.ino sketch to the Arduino.
Node.js Server Setup:

Install Node.js if not already installed.
Navigate to the server directory.
Install dependencies: npm install
Run the server: node server.js
Web Interface:

Open index.html or details.html in a web browser to interact with the system.
Dependencies
Arduino IDE: Used to upload sketches to the Arduino Uno. (note: prefer arduino ide version 1.8.3)
Node.js: Required to run the server.
Notes
Ensure proper connections of sensors and modules to the Arduino.
Update server.js with the correct serial port (COM port) for communication with the Arduino.
![WhatsApp Image 2024-06-15 at 13 49 14](https://github.com/Pavansai-Meruguma![WhatsApp Image 2024-06-15 at 13 49 31](https://github.com/Pavansai-Merugumala/Automated_public_lighting_system/assets/84954330/cde6e318-4474-4a88-82cc-32dd7e15e83f) la/Automated_public_lighting_system/assets/84954330/e7edf860-e2d4-4cfe-8aa9-77cbfa12458f)
