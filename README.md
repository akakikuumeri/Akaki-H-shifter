# Akaki-H-shifter
## 3D printable H-pattern shifter for racing simulators.

"[photo](https://cdn.thingiverse.com/assets/9b/3f/48/93/a9/featured_preview_Screen_Shot_2020-09-02_at_22.26.34.jpg)

Highly printable: only external hardware needed is M3 bolts and nuts, two rubber bands, 5 pcs PCB style microswitches, and a compatible Arduino-like microcontroller.

Improved version of my [older 6 speed gear shift](https://www.thingiverse.com/thing:3881165), now with 8 speeds and better spring action. Instead of a simple rubber band and a PLA spring, it uses two cam elements for centering force and latch action. These were lessons learnt from my [joystick project](https://www.thingiverse.com/thing:4576634).

It uses an Arduino Micro for USB HID compliant gamepad support. No drivers required on Windows and Mac OS. Works great with Dirt Rally, Truck Simulator, Assetto Corsa, etc.

Video and build instructions: https://youtu.be/fTknGo8n0Co

Also includes a simple analog handbrake. You need a generic potentiometer. Mount the pot in the base piece, then slip on the shaft and the grip, and tension it with a rubber band.

Connect the potentiometer to your arduino 5V, GND and A0. I used a detachable connector. The source code has a feature where if the pot is not connected at start-up, it ignores the signal.

## Bill of Materials:
* Arduino Pro Micro
* PCB size microswitches, 5pcs
* M3 nuts and bolts (20 mm and 30 mm or other similar lengths)
* 2 Rubber bands
* 2 Desk clamps (I used two ebay microphone clamps)

For handbrake:
* Generic rotational potentiometer (any resistance value will work)
