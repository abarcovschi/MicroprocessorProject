int sensor1 = 2;
int testVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  testVal = digitalRead(sensor1);
  Serial.println(testVal);

  delay(100);
  
}
