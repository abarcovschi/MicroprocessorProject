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
int channel1 = 1;        // number of MIDI channel (16 total)
int channel2 = 2;        // number of MIDI channel (16 total)
int channel3 = 3;        // number of MIDI channel (16 total)
int channel4 = 4;        // number of MIDI channel (16 total)
int noteOn = 144;       // 10010000, note on command
int noteOff = 128;      // 10000000, note off command

// Motor control
int pwmMotor = 9;       // pwm pin ~D3

// Other vars for correct notes combinations
int senseVals[4];       // value of sensor per location
String senseString = "";// convert array values to a single string
int num;                // binary combination of sensor values

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


void loop() {
  // read values of sensors
  senseVals[0] = digitalRead(sensor1);
  senseVals[1] = digitalRead(sensor2);
  senseVals[2] = digitalRead(sensor3);
  senseVals[3] = digitalRead(sensor4);

  // creates one integer with value from 1111 -> 0000
  for (int i = 0; i <= 3; i++)
  {
    senseString = senseString + senseVals[i];
  }
  
  num = senseString.toInt(); //switch case needs an int 
  senseString = "";          //reset

  // determining which note to play and sending appropriate MIDI message
  switch (num)
  {
    case 1110:
      MIDI.sendNoteOn(70, velocity, channel1);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(70, velocity, channel1); // Turn the note off.
      break;
    case 1101:
      MIDI.sendNoteOn(70, velocity, channel2);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(70, velocity, channel2); // Turn the note off.
      break;
    case 1100:
      MIDI.sendNoteOn(70, velocity, channel1);  // Turn the note on.
      MIDI.sendNoteOn(70, velocity, channel2);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(70, velocity, channel1); // Turn the note off.
      MIDI.sendNoteOff(70, velocity, channel2); // Turn the note off.
      break;
    case 1011:
      MIDI.sendNoteOn(70, velocity, channel3);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(70, velocity, channel3); // Turn the note off.
      break;
    case 1010:
      MIDI.sendNoteOn(70, velocity, channel1);  // Turn the note on.
      MIDI.sendNoteOn(70, velocity, channel3);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(70, velocity, channel1); // Turn the note off.
      MIDI.sendNoteOff(70, velocity, channel3); // Turn the note off.
      break;
    case 110:
      MIDI.sendNoteOn(70, velocity, channel1);  // Turn the note on.
      MIDI.sendNoteOn(70, velocity, channel4);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(70, velocity, channel1); // Turn the note off.
       MIDI.sendNoteOff(70, velocity, channel4); // Turn the note off.
      break;
    case 101:
      MIDI.sendNoteOn(70, velocity, channel2);  // Turn the note on.
      MIDI.sendNoteOn(70, velocity, channel4);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(70, velocity, channel2); // Turn the note off.
      MIDI.sendNoteOff(70, velocity, channel4); // Turn the note off.
      break;
    case 111:
      MIDI.sendNoteOn(70, velocity, channel4);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(70, velocity, channel4); // Turn the note off.
      break;
  }
}




