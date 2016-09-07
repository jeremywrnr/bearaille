bearaille
=========

Ruby and MCU code and designs for a braille typewriter, using the redbear duo.
made for interactive device design at uc berkeley, fall 2016. to install
ruby dependencies:

    bundle

The ruby keyboard workaround is only neccesary because the redbear duo has an
ARM processor which Arduino's standard `Keyboard` library does not work. Ruby
reads the serial monitor and converts the text to keyboard input. The braille
input mapping was based on English braille. To use this, you will have to set
the proper port name to open in `serial.rb`. Once this is done, and you checked
that input is coming into the serial port,  you can route it to directly to the
keyboard by running `make`.

