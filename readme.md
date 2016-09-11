:bear bearaille
===============

This is Ruby and MCU code and designs for a braille keyboard entrance device,
using the RedBear Duo. Made for IDD at uc berkeley, fall 2016.

![bearaille](/images/finished.jpg)


## setup

To install ruby dependencies: `bundle`. The ruby keyboard workaround is only
neccesary because the redbear duo has an ARM processor which Arduino's standard
`Keyboard` library does not work. Ruby reads the serial monitor and converts
the text to keyboard input. You can open the serial port directly if you simply
want to verify that output is being sent from the arduino.


## input device

I used Braille because it was a fairly concise input method, and also would
allow for people that were already familiar with how to read braille an
efficient way to enter text.

![schematic](/images/schematic.png)

My device consists of 7 switches - one for each segment of braille and another
for submitting the chord and entering text, in the shape of a bear head. The
braille input mapping was based on [English braille][eng]. There is an internal
mapping in the arduino code which samples the state of each switch when the
enter button is pressed, and then returns a string which corresponds to that
mapping.

![wiring](/images/wiring.png)

To run this code, you will have to set the proper port name to open in
`serial.rb`. Once this is done, and you checked that input is coming into the
serial port, you can route it to directly to the keyboard by running `make`.

![under](/images/under-wiring.jpg)

[eng]:https://en.wikipedia.org/wiki/English_Braille


## reflection

I learned about designing phsyical enclosures, and also about emulating
arbitrary text as keyboard input on OSX. I was satisfied with the difficulty of
the project. It allowed me to experiment with laser cutting, and to be creative
with the internal mapping of text input. I made two protoypes before setting up
on the final design: the first didn't have any bear buttons, and the next
design added two new laser cut holes for keeping the enclosure together.


## videos

[youtube]()

[outtake]()

