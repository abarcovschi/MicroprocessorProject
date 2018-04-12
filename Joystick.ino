// Arduino pin numbers
const int SW_pin = 10; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int pwmMotor=9; //digital pin connected to motor

int Speed=0;
int velocity=0;
int motorSpeed=0;
boolean mode=true;
int counter = 0;
void setup() {
  pinMode(SW_pin, INPUT_PULLUP);
  pinMode(X_pin,INPUT);
  pinMode(Y_pin,INPUT);
  Serial.begin(9600);

  motorControl(255);
  delay(500);
  motorControl(0);
}

void loop() {
//  Serial.print("Switch:  ");
//  Serial.print(digitalRead(SW_pin));
//  Serial.print("\n");
//  Serial.print("X-axis: ");
//  Serial.print(analogRead(X_pin));
//  Serial.print("\n");
//  Serial.print("Y-axis: ");
//  Serial.println(analogRead(Y_pin));
//  Serial.print("\n\n");
//  if(analogRead(X_pin)>900)
//  {
//    Speed=Speed+10;
//  }
//  if(analogRead(X_pin)<150)
//  {
//    Speed=Speed-10;
//  }
//  motorControl(Speed);
//   Serial.println(Speed);

joystick();
motorControl(motorSpeed);
Serial.print("Note: ");
Serial.print(mode);
Serial.print("\n");
Serial.print("Motor: ");
Serial.print(motorSpeed);
Serial.print("\n");
Serial.print("Vel: ");
Serial.print(velocity);
Serial.print("\n");
  delay(500);
}
void motorControl(int speed)
{
  analogWrite(pwmMotor,speed);
}

//void joystick ()
////{
//  //Toggles between the two modes 
//  //Also a manual debouncer implemented - need to hold down click button for 3 counts until the mode changes
//  if(digitalRead(SW_pin)==0) 
//  {
//    counter++;
//  }
//  else
//  {
//    counter=0;
//  }
//  if(counter>3)
//  {
//    note=(!note);
//  }
////  //Reads the joystick inputs
////  motorSpeed=map(analogRead(X_pin),0,1023,0,255);
////  velocity=map(analogRead(Y_pin),0,1023,0,255);
//// Code for making the change gradual
// // int a=map(analogRead(X_pin),0,1023,0,255);
//  if (analogRead(X_pin)>700)
//  {
//  motorSpeed=motorSpeed+10;
//  }
//  if(analogRead(X_pin)<300)
//  {
//    motorSpeed=motorSpeed-10;
//  }
////  int b=map(analogRead(Y_pin),0,1023,0,255);
//  if (analogRead(Y_pin)>700)
//  {
//  velocity=velocity+10;
//  }
//  if(analogRead(Y_pin)<300)
//  {
//    velocity=velocity-10;
//  }
//  
//  
//}
void joystick ()
{
  //Toggles between the two modes 
  //Manual debouncer - need to hold down click button for 3 counts until the mode changes
  if(digitalRead(SW_pin) == 0) 
  {
    counter++;
  }
  else if(digitalRead(SW_pin == 1))
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

