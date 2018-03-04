// MIDI commands 128->255: 10000000 -> 11111111: Most Significant 4 bits = commands, LS = channels
// MIDI databytes 0->127:  00000000 -> 01111111

// Hall effect sensors
int sensor1 = 1;        // digital pin (0 = magnet present, 1 = magnet not present)
int sensor2 = 2;        // digital pin
int sensor3 = 3         // digital pin
int sensor4 = 4;        // digital pin

// MIDI control
int velocityData = 0; // 01111111 -> 00000000 (default 0)
int noteOnCom = 144;    // 10010000b

// Motor control
int pwmMotor = 3;       // pwm pin ~D3

// Other vars for correct notes combinations
int sensVals[4]; // value of sensor per location
int num; // binary combination of sensor values

void setup() {
  pinMode(sensor1,  INPUT);
  pinMode(sensor2,  INPUT);
  pinMode(sensor3,  INPUT);
  pinMode(sensor4,  INPUT);
  pinMode(pwmMotor, OUTPUT);
  pinMode(midiOut,  OUTPUT);
  Serial.begin(9600);         // 9600 = baud rate (bits per second)
  
}

void loop() {
  // turn on motor
  motorControl(100);
  
  // read values of sensors
  sensVals[0] = digitalRead(sensor1);
  sensVals[1] = digitalRead(sensor2);
  sensVals[2] = digitalRead(sensor3);
  sensVals[3] = digitalRead(sensor4);

// creates one integer with value from 1111 -> 0000
  for (int i = 0; i <= 3; i++)
  {
    num = num*10 + sensVals[i];
  }

 // determining which note to play and sending appropriate MIDI message
  switch (num) {
    case 1111: // no note playing
      MIDImessage(noteOnCom, 0, 0);
      break;
      
    case 1110: // A (line 3)
      MIDImessage(noteOnCom, 69, 100);
      delay(1000);                      // allowing note to play
      MIDImessage(noteOnCom, 69, 0);    // turning note off
      break;
      
    case 1101: // B
      MIDImessage(noteOnCom, 71, 100);
      delay(1000);                      // allowing note to play 
      MIDImessage(noteOnCom, 71, 0);    // turning note off
      break;
      
    case 1100: // C
      MIDImessage(noteOnCom, 72, 100);
      delay(1000);                      // allowing note to play 
      MIDImessage(noteOnCom, 72, 0);    // turning note off
      break;
      
    case 1011: // D
      MIDImessage(noteOnCom, 74, 100);
      delay(1000);                      // allowing note to play 
      MIDImessage(noteOnCom, 74, 0);    // turning note off
      break; 
      
    case 1010: // E
      MIDImessage(noteOnCom, 76, 100);
      delay(1000);                      // allowing note to play 
      MIDImessage(noteOnCom, 76, 0);    // turning note off
      break;
      
    case 1001: // F
      MIDImessage(noteOnCom, 77, 100);
      delay(1000);                      // allowing note to play 
      MIDImessage(noteOnCom, 77, 0);    // turning note off
      break;
      
    case 1000: // G
      MIDImessage(noteOnCom, 79, 100);
      delay(1000);                      // allowing note to play 
      MIDImessage(noteOnCom, 79, 0);    // turning note off
      break; 
      
    case 0111: // A'
      MIDImessage(noteOnCom, 81, 100);
      delay(1000);                      // allowing note to play 
      MIDImessage(noteOnCom, 81, 0);    // turning note off   
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


