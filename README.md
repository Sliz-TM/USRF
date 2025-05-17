# USRF

This is the <b>official firmware</b> for <b>ESP32</b> <b>(M5StickC Plus2)</b> The Ultrasonic rangefinder game is the simplest for this device


# Install for M5 StickC Plus2

1)Connect <b>M5 StickC Plus2</b>

2)Open <b>Arduino IDE</b>

3)In Arduino IDE, open <b>File>Settings and in Additional links for Board Manager</b> enter: <b>https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json</b>, <b>save and re-enter Arduino IDE</b>

4)Next Go to <b>"Sketch>Connect library"</b> Next choose to <b>connect the .zip file and choose the M5StickCPlus2.zip</b> file from the <b>Repository</b> and confirm and wait for the download and after this, <b>re-enter the Arduino IDE</b>

5)Then in <b>File>Open</b> and select the file USRF.ino then next to it select where the Device is find M5 StickC Plus2 and then go to Flash Requenty and Erase all flash before loading the sketch select Enabled, then next to the check mark select the arrow to the right and wait for loading then turn on the device: <b>Button C (2-3 seconds)</b>

6)After that connect the Ultrasonic rangefinder <b>(HC-SR04)</b> to:

<b>VCC → 3.3V Or 5V (On GROVE or side contacts of M5StickC Plus2).</b>
<b>GND → GND.</b>
<b>Trig → GPIO 26.</b>
<b>Echo → GPIO 32.</b>

<b>If something is <b>not working properly</b>, does not load or does not work then write to the administrator: <b>abs.mark.photo@gmail.com</b>

This code has two values: OR and TC, OR is Out of Range, and TC is Too Close; OR is if more than 4 meters, TC if less than 2 cm

# P.S

The installation is available through the Arduino IDE, so we have every right to change the code for yourself or look at the code, so you can completely trust us! Although we would like to remain anonymous for you and our code, but because we made our own license, you can do this but leave the code Open and leave a commented line: Made by Sliz™ or Made by (You) And taken as a basis from Sliz™
