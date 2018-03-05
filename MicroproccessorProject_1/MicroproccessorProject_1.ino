
int sensor1 = 2;
int sensor2 = 3;
int sensor3 = 4;
int sensor4 = 5;
int senseVals[4];
int num = 0;
String bits = "";

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
  Serial.println(num);
  
  switch(num)
  {
    case 1110:
    playNote(69);
    break;
    case 1101:
    playNote(71);
    break;
    case 1100:
    playNote(72);
    break;
    case 1011:
    playNote(74);
    break;
    case 1010:
    playNote(76);
    break;
    case 1001:
    playNote(77);
    break;
    case 1000:
    playNote(79);
    break;
    case 0111:
    playNote(81);
    break;
  }
  delay(1000);
}

// Possible error in playNote method

void playNote(byte note)
{
    Serial.write();  // MIDI command byte
    Serial.write(note); //MIDI note byte
    Serial.write();  //MIDI volume byte
}

