#define LedS1V 10

void setup(){
  pinMode(LedS1V, OUTPUT);
}
#define VIIVE 150
void loop(){
  analogWrite(LedS1V, 0);
  delay(VIIVE);
  analogWrite(LedS1V, 64);
  delay(VIIVE * 4);
  analogWrite(LedS1V, 127);
  delay(VIIVE);
  analogWrite(LedS1V, 200);
  delay(VIIVE * 2);
}
