#include <MIDI.h>

// MIDI commands 128->255: 10000000 -> 11111111: Most Significant 4 bits = commands, LS = channels
// MIDI databytes 0->127:  00000000 -> 01111111

// Hall effect sensors  (0 = magnet present, 1 = magnet not present)
int sensor1 = 2;        // digital pin
int sensor2 = 3;        // digital pin
int sensor3 = 4;        // digital pin
int sensor4 = 5;        // digital pin

//Joystick pins
const int SW_pin = 10; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

// MIDI control
int velocity = 127;     // 00000000 -> 01111111 (default 0)  
int noteOn = 144;       // 10010000, note on command
int noteOff = 128;      // 10000000, note off command

//4 bit Note mode MIDI channel
int channel = 1;        // number of MIDI channel (16 total)

//Drum mode MIDI channels
int channel2 = 2;       // number of MIDI channel (16 total)
int channel3 = 3;       // number of MIDI channel (16 total)
int channel4 = 4;       // number of MIDI channel (16 total)
int channel5 = 5;       // number of MIDI channel (16 total)

// Motor control
int pwmMotor = 9;       // pwm pin ~D9
int motorSpeed=100;

// Other vars for correct notes combinations
int senseVals[4];       // value of sensor per location
String senseString = "";// convert array values to a single string
int num;                // binary combination of sensor values
boolean note = true;    // TRUE = 4 bit note mode, FALSE = drum mode

int counter;

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
  Serial.begin(9600);
  
  // turn on motor
  motorControl();
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
  
  joystick();                // calling the joystick function
  motorControl();            //change motor speed
  
  // determining which note to play and sending appropriate MIDI message
  if(note==true){
      switch (num)
      {
        case 1111:
        break;
        case 1110:
          MIDI.sendNoteOn(60, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(60, velocity, channel); // Turn the note off.
          break;
        case 1101:
          MIDI.sendNoteOn(62, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(62, velocity, channel); // Turn the note off.
          break;
        case 1100:
          MIDI.sendNoteOn(64, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(64, velocity, channel); // Turn the note off.0
          break;
        case 1011:
          MIDI.sendNoteOn(65, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(65, velocity, channel); // Turn the note off.
          break;
        case 1010:
          MIDI.sendNoteOn(67, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(67, velocity, channel); // Turn the note off.
          break;
          case 1001:
          MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
          break;
          case 1000:
          MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.
          break;
        case 110:
          MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
          break;
        case 101:
          MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
          break;
        case 100:
          MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
          break;
        case 111:
          MIDI.sendNoteOn(77, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(77, velocity, channel); // Turn the note off.
          break;
        case 11:
          MIDI.sendNoteOn(79, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(79, velocity, channel); // Turn the note off.
          break;
        case 10:
          MIDI.sendNoteOn(81, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(81, velocity, channel); // Turn the note off.
          break;
        case 1:
          MIDI.sendNoteOn(83, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(83, velocity, channel); // Turn the note off.
          break;
        case 0:
          MIDI.sendNoteOn(84, velocity, channel);  // Turn the note on.
          delay(500);                              // Wait 500 milliseconds.
          MIDI.sendNoteOff(84, velocity, channel); // Turn the note off.
          break;
      }
  }
  else // The drum kit notes
  {
      if(digitalRead(sensor1)== 0)
      {
         MIDI.sendNoteOn(69, velocity, channel2);  // Turn the note on. 
      }
      if(digitalRead(sensor2)== 0)
      {
         MIDI.sendNoteOn(70, velocity, channel3);  // Turn the note on. 
      }
      if(digitalRead(sensor3)== 0)
      {
         MIDI.sendNoteOn(71, velocity, channel4);  // Turn the note on.   
      }
      if(digitalRead(sensor4)== 0)
      {
        MIDI.sendNoteOn(72, velocity, channel5);  // Turn the note on.
      }
    
      delay(500);
      MIDI.sendNoteOff(69, velocity, channel2); // Turn the note off.
      MIDI.sendNoteOff(70, velocity, channel3); // Turn the note off.  
      MIDI.sendNoteOff(71, velocity, channel4); // Turn the note off. 
      MIDI.sendNoteOff(72, velocity, channel5); // Turn the note off.
    
  }
  
//Display values - can be deleted after the code testing is complete
Serial.print("\nNote");
Serial.print(note);
Serial.print("\nSpeed");
Serial.print(motorSpeed);
Serial.print("\nVelocity");
Serial.print(velocity);
delay(1000);
  
}

void joystick ()
{
  //Toggles between the two modes 
  //Manual debouncer - need to hold down click button for 3 counts until the mode changes
  if(digitalRead(SW_pin) == 0) 
  {
    counter++;
  }
  else
  {
    counter = 0;
  }
  if(counter > 3)
  {
    note = (!note);
  }
  
  //Reads the joystick inputs
  motorSpeed = map(analogRead(X_pin),0,1023,0,255);
  velocity = map(analogRead(Y_pin),0,1023,0,255);
  
  /* Code for making the change gradual
  int a=map(analogRead(X_pin),0,1023,0,255);
  if (motorSpeed>a)
  {
  motorSpeed=motorSpeed+10;
  }
  else{motorSpeed=motorSpeed-10;
  }
  int b=map(analogRead(Y_pin),0,1023,0,255);
  if (velocity>b)
  {
  velocity=velocity+10;
  }
  else{velocity=velocity-10
  }
  */
}

void motorControl() 
{
  analogWrite(pwmMotor, motorSpeed);
}

void beginTest()
{
  for (int i=60;i<85;i++) // Turns all notes to be used on and off, one by one
  {
    MIDI.sendNoteOn(i,velocity,channel);
    delay(500);
    MIDI.sendNoteOff(i,velocity,channel);
  }
}

