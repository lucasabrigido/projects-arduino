#define pinLumusInp1 A0
#define pinLedOut1 4 //green
#define pinLedOut2 6 //red

int currentVolts;
float currentAmper;

float amper = 5.0;
float volts = 1023.0;
void setup() {
  pinMode(pinLumusInp1, INPUT);
  pinMode(pinLedOut1, OUTPUT);
  pinMode(pinLedOut2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  currentVolts = analogRead(pinLumusInp1);
  currentAmper = currentVolts * amper / volts;
  if(currentAmper < 1.5) {
    digitalWrite(pinLedOut2, HIGH);
    digitalWrite(pinLedOut1, LOW);  
  } else {
    digitalWrite(pinLedOut2, LOW);
    digitalWrite(pinLedOut1, HIGH);       
  }
  
  Serial.print("volts: ");
  //Serial.print(currentVolts);
  //Serial.print("\t");
  //Serial.print("Tensão: ");
  //Serial.print(currentAmper);
  //Serial.print("\t");

  //Serial.println();
  //delay(3000);
  

}
