#define pinAnalogLdrInp A0 //LDR input
#define pinLedOut1 4 //led green
#define pinLedOut2 6 //led red
#define pinBluzzerOut3 8 //bluzzer
#define pinButtonInp 12 //button
#define timeForClick 500


int freq = 20000;
int numberReadLdr = 0;
bool isActivate = true;
void setup() {
  pinMode(pinAnalogLdrInp, INPUT);
  pinMode(pinButtonInp, INPUT_PULLUP);
  pinMode(pinLedOut1, OUTPUT);
  pinMode(pinLedOut2, OUTPUT);
  pinMode(pinBluzzerOut3, OUTPUT);
  Serial.begin(9600);
  digitalWrite(pinLedOut1, HIGH);
}
p
void loop() {

  if(!digitalRead(pinButtonInp)){
    noTone(pinBluzzerOut3);
    digitalWrite(pinLedOut2, HIGH);
    digitalWrite(pinLedOut1, HIGH);
    isActivate = !isActivate;
    Serial.println(isActivate);
    delay(timeForClick);
  }

  if(isActivate) {
    numberReadLdr = analogRead(pinAnalogLdrInp);
    if(numberReadLdr < 950) {
      digitalWrite(pinLedOut2, HIGH);
      digitalWrite(pinLedOut1, LOW);
      tone(pinBluzzerOut3, freq);
    } else {
       digitalWrite(pinLedOut2, LOW);
       digitalWrite(pinLedOut1, HIGH);   
       noTone(pinBluzzerOut3);
    }
  }
}
