#define LedS1V 10

void setup(){
  pinMode(LedS1V, OUTPUT);
  Serial.begin(9600);
  Serial.println("Startup");
}
#define VIIVE 25

byte teho=0;
bool countUP = true;

void loop(){
  analogWrite(LedS1V, teho);
  if( countUP == true ) {
    teho++;//Kasvata muuttujan arvoa yhdellä
  }else{
    teho--;
  }
  if(teho == 255){
    countUP = false;
    Serial.println("Count Down");
  }
  if(teho == 0) {
    countUP = true;
    Serial.println("Count up");
  }
  delay(VIIVE);
}
