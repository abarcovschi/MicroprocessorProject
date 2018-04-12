#include <MIDI.h>

// MIDI commands 128->255: 10000000 -> 11111111: Most Significant 4 bits = commands, LS = channels
// MIDI databytes 0->127:  00000000 -> 01111111

// Hall effect sensors  (0 = magnet present, 1 = magnet not present)
int sensor1 = 2;        // digital pin
int sensor2 = 3;        // digital pin
int sensor3 = 4;        // digital pin
int sensor4 = 5;        // digital pin

// leds to show which mode is on
int ledTetris = 12;
int ledDrums = 13;

//Joystick pins
const int SW_pin = 10;  // digital pin connected to switch output
const int X_pin = 0;    // analog pin connected to X output
const int Y_pin = 1;    // analog pin connected to Y output

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
int motorSpeed = 200;

// Other vars for correct notes combinations
int senseVals[4];       // value of sensor per location
String senseString = "";// convert array values to a single string
int num;                // binary combination of sensor values
boolean mode = true;    // TRUE = 4 bit note mode, FALSE = drum mode

int counter;

int previousNum = 0;
int previousNote = 0;
int currentNote = 0;

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
  pinMode(SW_pin,INPUT_PULLUP);
  pinMode(X_pin,INPUT);
  pinMode(Y_pin,INPUT);
  pinMode(ledTetris, OUTPUT);
  pinMode(ledDrums, OUTPUT);

  mode=true;
  // turn on motor
  motorControl();
  beginTest();
}

void loop() {
  // read values of sensors
  //senseVals[0] = digitalRead(sensor1);
  //senseVals[1] = digitalRead(sensor2);
  //senseVals[2] = digitalRead(sensor3);
  //senseVals[3] = digitalRead(sensor4);

  // create a number from 0-15
  num = digitalRead(sensor1) + 2*(digitalRead(sensor2)) + 4*(digitalRead(sensor3)) + 8*(digitalRead(sensor4));

  // creates one integer with value from 1111 -> 0000
  //for (int i = 0; i <= 3; i++)
  //{
    //senseString = senseString + senseVals[i];
  //}
  
  //num = senseString.toInt(); //switch case needs an int 
  //senseString = "";          //reset
  
  joystick();                //calling the joystick function
  motorControl();            //change motor speed

    // determining which note to play and sending appropriate MIDI message
    if(mode==true){
      digitalWrite(ledTetris, HIGH);
      digitalWrite(ledDrums, LOW);
        switch (num)
        {
          case 14:
            MIDI.sendNoteOn(60, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(60, velocity, channel); // Turn the note off.
            break;
          case 13:
            MIDI.sendNoteOn(62, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(62, velocity, channel); // Turn the note off.
            break;
          case 12:
            MIDI.sendNoteOn(64, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(64, velocity, channel); // Turn the note off.
            break;
          case 11:
            MIDI.sendNoteOn(65, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(65, velocity, channel); // Turn the note off.
            break;
          case 10:
            MIDI.sendNoteOn(67, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(67, velocity, channel); // Turn the note off.
            break;
          case 9:
            MIDI.sendNoteOn(69, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(69, velocity, channel); // Turn the note off.
            break;
          case 8:
            MIDI.sendNoteOn(71, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(71, velocity, channel); // Turn the note off.
            break;
          case 7:
            MIDI.sendNoteOn(72, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(72, velocity, channel); // Turn the note off.
            break;
          case 6:
            MIDI.sendNoteOn(74, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(74, velocity, channel); // Turn the note off.
            break;
          case 5:
            MIDI.sendNoteOn(76, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(76, velocity, channel); // Turn the note off.
            break;
          case 4:
            MIDI.sendNoteOn(77, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(77, velocity, channel); // Turn the note off.
            break;
          case 3:
            MIDI.sendNoteOn(79, velocity, channel);  // Turn the note on.
            delay(500);                              // Wait 500 milliseconds.
            MIDI.sendNoteOff(79, velocity, channel); // Turn the note off.
            break;
          case 2:
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
      digitalWrite(ledTetris, LOW);
      digitalWrite(ledDrums, HIGH);
      
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
  
////Display values - can be deleted after the code testing is complete
Serial.print("\nMode");
Serial.print(mode);
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
  if(counter > 5)
  {
    mode = (!mode);
  }
  
  //Reads the joystick inputs
  //Code for making the change gradual
  int a=map(analogRead(X_pin),0,1023,0,100);
  int b=map(analogRead(Y_pin),0,1023,0,100);
  if ((a>75)||(motorSpeed<0))
  {
  motorSpeed=motorSpeed+10;
  }
  else if((a<25)||(motorSpeed>255))
  {
    motorSpeed=motorSpeed-10;
  }
  if (b>75||(velocity<0))
  {
  velocity=velocity+10;
  }
  else if(b<25||(velocity>127))
  {
    velocity=velocity-10;
  }
  
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
    delay(250);
    MIDI.sendNoteOff(i,velocity,channel);
  }
}
