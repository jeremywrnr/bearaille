# using the SerialPort gem, rout serial input to OSX keyboard
require 'serialport'
require 'accessibility/keyboard'
include Accessibility::Keyboard

# params for serial port, may be different for you
port = '/dev/cu.usbmodem1421'
SerialPort.open(port) do |sp|

  # configure port
  sp.baud = 9600
  sp.data_bits = 8
  sp.stop_bits = 1
  sp.parity = SerialPort::NONE
  sp.read_timeout = 200

  # rout data to keyboard
  while true do
    inbyte = sp.gets

    next if inbyte.nil?

    keyboard_events_for(inbyte.chomp).each {|e| KeyCoder.post_event(e) }
  end
end

