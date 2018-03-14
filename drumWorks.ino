#include <MIDI.h>

// MIDI commands 128->255: 10000000 -> 11111111: Most Significant 4 bits = commands, LS = channels
// MIDI databytes 0->127:  00000000 -> 01111111

// Hall effect sensors  (0 = magnet present, 1 = magnet not present)
int sensor1 = 2;        // digital pin
int sensor2 = 3;        // digital pin
int sensor3 = 4;        // digital pin
int sensor4 = 5;        // digital pin

// MIDI control
int velocity = 127;     // 00000000 -> 01111111 (default 0)
int channel = 1;        // number of MIDI channel (16 total)
int channel2 = 2;        // number of MIDI channel (16 total)
int channel3 = 3;        // number of MIDI channel (16 total)
int channel4 = 4;        // number of MIDI channel (16 total)
int noteOn = 144;       // 10010000, note on command
int noteOff = 128;      // 10000000, note off command



// Other vars for correct notes combinations
int senseVals[4];       // value of sensor per location


struct MySettings : public midi::DefaultSettings
{
  static const long BaudRate = 9600;
};


MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);

void setup() {
  MIDI.begin();
  Serial.begin(9600);
  pinMode(sensor1,  INPUT);
  pinMode(sensor2,  INPUT);
  pinMode(sensor3,  INPUT);
  pinMode(sensor4,  INPUT);

}

void loop() 
{

if(digitalRead(sensor1)== 0)
{
   MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on. 
}
if(digitalRead(sensor2)== 0)
{
   MIDI.sendNoteOn(70, velocity, channel2);  // Turn the note on.                       // Wait 500 milliseconds.  
}
if(digitalRead(sensor3)== 0)
{
   MIDI.sendNoteOn(71, velocity, channel3);  // Turn the note on.                              // Wait 500 milliseconds.  
}
if(digitalRead(sensor4)== 0)
{
  MIDI.sendNoteOn(72, velocity, channel4);  // Turn the note on.                             // Wait 500 milliseconds.
}
delay(500);
MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
MIDI.sendNoteOff(70, velocity, channel2); // Turn the note off.  
MIDI.sendNoteOff(71, velocity, channel3); // Turn the note off. 
MIDI.sendNoteOff(72, velocity, channel4); // Turn the note off.
}




