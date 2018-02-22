const int engPin = 6;
int x = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(engPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(x < 255){
    x = x + 30; // 17 increases in speed.
    analogWrite(engPin, x);
    delay(2000);
  }
}
