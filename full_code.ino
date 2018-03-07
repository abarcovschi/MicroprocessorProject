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
int noteOn = 144;       // 10010000, note on command
int noteOff = 128;      // 10000000, note off command

// Motor control
int pwmMotor = 3;       // pwm pin ~D3

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
  pinMode(sensor1,  INPUT);
  pinMode(sensor2,  INPUT);
  pinMode(sensor3,  INPUT);
  pinMode(sensor4,  INPUT);
  pinMode(pwmMotor, OUTPUT);
  
  // turn on motor
  motorControl(100);
}

void loop() {
  // turn on motor
  motorControl(100);
  
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
  
  num = bits.toInt(); //switch case needs an int 
  bits = "";          //reset

  // determining which note to play and sending appropriate MIDI message
  switch (num)
  {
    case 1110:
      MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
      break;
    case 1101:
      MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.
      break;
    case 1100:
      MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
      break;
    case 1011:
      MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
      break;
    case 1010:
      MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
      break;
    case 1001:
      MIDI.sendNoteOn(77, velocity, channel);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(77, velocity, channel); // Turn the note off.
      break;
    case 1000:
      MIDI.sendNoteOn(79, velocity, channel);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(79, velocity, channel); // Turn the note off.
      break;
    case 0111:
      MIDI.sendNoteOn(81, velocity, channel);  // Turn the note on.
      delay(500);                              // Wait 500 milliseconds.
      MIDI.sendNoteOff(81, velocity, channel); // Turn the note off.
      break;
  }
}

void MIDImessage(int command, int note, int velocity) {
  // Serial is D1 (TX = transmitter)
  Serial.write(command); 
  Serial.write(note);
  Serial.write(velocity);
}

void motorControl(int speed) {
  analogWrite(pwmMotor, speed);
}
