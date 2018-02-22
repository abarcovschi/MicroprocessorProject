int sensor1 = 3;
int sensor2 = 4;
int sensor3 = 5;
int sensor4 = 6;
int sensVals[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensVals[0] = digitalRead(sensor1);
  sensVals[1] = digitalRead(sensor2);
  sensVals[2] = digitalRead(sensor3);
  sensVals[3] = digitalRead(sensor4);

  
  
  // if the contents of the array hasn't changed since last check, do nothing/skip switch statements?

  // next: MIDI code
}
