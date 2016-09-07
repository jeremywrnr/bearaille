require 'accessibility/keyboard'

include Accessibility::Keyboard

keyboard_events_for("Hey, there!").each do |event|
  KeyCoder.post_event event
end
