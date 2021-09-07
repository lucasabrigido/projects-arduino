#define pin1 4
#define pin2 6
#define timeForClick 170

bool isOpen = false;
void setup(){
  pinMode(pin1, INPUT);
  pinMode(pin2, OUTPUT);
}

void loop(){
  if (digitalRead(pin1)) isOpen = !isOpen;
  digitalWrite(pin2, isOpen);
  delay(timeForClick);
}
