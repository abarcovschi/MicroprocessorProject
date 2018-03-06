#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

struct MySettings : public midi::DefaultSettings
{
  static const long BaudRate = 115200;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);

const int velocity = 127; //Max Velocity (range is 0-127)
const int channel = 1; //MIDI Channel 1 (out of 16)

void setup() {
  MIDI.begin();
}

// Play notes from F3 (53) to A6 (93):
void loop() {
  // E
  MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
  // B
  MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // D
  MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.

  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.

  MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.
  // A
  MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.

  // A
  MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // E
  MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
  // D
  MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // B
  MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.
  
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // D
  MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
  // E
  MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // A
  MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
  // A
  MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.

  // D
  MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
  // F
  MIDI.sendNoteOn(77, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(77, velocity, channel); // Turn the note off.
  // A
  MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
  // G
  MIDI.sendNoteOn(79, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(79, velocity, channel); // Turn the note off.
  // F
  MIDI.sendNoteOn(77, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(77, velocity, channel); // Turn the note off.
  // E
  MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
  
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // E
  MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
  // D
  MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // B
  MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.

  // B
  MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // D
  MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
  // E
  MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
  // C
  MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
  // A
  MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
  // A
  MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
  delay(500);                               // Wait 500 milliseconds.
  MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
  
  //for (int note = 69; note <= 81; note ++) {
    //MIDI.sendNoteOn(note, velocity, channel);  // Turn the note on.
    //delay(500);                               // Wait 500 milliseconds.
    //MIDI.sendNoteOff(note, velocity, channel); // Turn the note off.
  }
}
