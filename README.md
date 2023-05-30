# esp-now-control-rcv

The purpose of this modified example sketch is control of the RGB LED built onto an ESP-32 board from a remote ESP32 board. Both the 
colour and the brightness of the LED are controlled.

* The transmitting ESP32 is connected to a computer running a terminal program such as PuTTY or CoolTerm. 
* A single letter typed into the terminal window or the transmitting ESP32 acts as a command for the receiving ESP32.
* In this example the MAC address of the receiving ESP32 is coded into esp-now-control-xmit.ino programed into the transmitting ESP32.
* The two boards communicate via WiFi modules built into ESP32 the boards.

In exploring the use of ESP NOW on a ESP32-S2-DEVKITC-1 board I found a simple example at 

* [https://dronebotworkshop.com/esp-now/#One-Way_Responder_Sketch](https://dronebotworkshop.com/esp-now/#One-Way_Responder_Sketch)

All the sketches on that page can be downloaded in a zip file if you go to the bottom of the page. The entire page contains useful 
information that I will not duplicate here.

I took the responder sketch and modified it to control the RGB LED on the ESP32. My modified control transmitter can be found at 
[https://github.com/danpeirce/esp-now-command-xmit](https://github.com/danpeirce/esp-now-command-xmit)

... more to follow...