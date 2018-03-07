#include <MIDI.h>

const int velocity = 127; //Max Velocity (range is 0-127)
const int channel = 1; //MIDI Channel 1 (out of 16)

int sensor1 = 2;
int sensor2 = 3;
int sensor3 = 4;
int sensor4 = 5;
int senseVals[4];
int pwmMotor = 9;
int num = 0;
String bits = "";

int noteOn = 144; // note on command
int noteOff = 128; // note off command
int vel = 127; // note volume, 127 is max volume

struct MySettings : public midi::DefaultSettings
{
  static const long BaudRate = 9600;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);

void setup() {
  // put your setup code here, to run once:
  MIDI.begin();
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(pwmMotor, OUTPUT);
  motorControl(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  senseVals[0] = digitalRead(sensor1);
  senseVals[1] = digitalRead(sensor2);
  senseVals[2] = digitalRead(sensor3);
  senseVals[3] = digitalRead(sensor4);

  for (int i = 0; i <= 3; i++)
  {
    bits = bits + senseVals[i];
  }

  num = bits.toInt();
  bits = ""; //reset

  // TEST
  //Serial.println(num);

  switch (num)
  {
    case 1110:
      MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
      delay(500);                               // Wait 500 milliseconds.
      MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
      break;
    case 1101:
      MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
      delay(500);                               // Wait 500 milliseconds.
      MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.
      break;
    case 1100:
      MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
      delay(500);                               // Wait 500 milliseconds.
      MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
      break;
    case 1011:
      MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
      delay(500);                               // Wait 500 milliseconds.
      MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
      break;
    case 1010:
      MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
      delay(500);                               // Wait 500 milliseconds.
      MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
      break;
    case 1001:
      MIDI.sendNoteOn(77, velocity, channel);  // Turn the note on.
      delay(500);                               // Wait 500 milliseconds.
      MIDI.sendNoteOff(77, velocity, channel); // Turn the note off.
      break;
    case 1000:
      MIDI.sendNoteOn(79, velocity, channel);  // Turn the note on.
      delay(500);                               // Wait 500 milliseconds.
      MIDI.sendNoteOff(79, velocity, channel); // Turn the note off.
      break;
    case 0111:
      MIDI.sendNoteOn(81, velocity, channel);  // Turn the note on.
      delay(500);                               // Wait 500 milliseconds.
      MIDI.sendNoteOff(81, velocity, channel); // Turn the note off.
      break;
  }
  delay(1000);
}

void motorControl(int speed) {
  analogWrite(pwmMotor, speed);
}
