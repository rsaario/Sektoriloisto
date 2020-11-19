#define LedS1Vi 11
#define LedS1Va 12
#define LedS1Pu 9
#define LedS2Vi 6
#define LedS2Va 5
#define LedS2Pu 4

void setup(){
  pinMode(LedS1Vi, OUTPUT);
  pinMode(LedS1Va, OUTPUT);
  pinMode(LedS1Pu, OUTPUT);
  pinMode(LedS2Vi, OUTPUT);
  pinMode(LedS2Va, OUTPUT);
  pinMode(LedS2Pu, OUTPUT);
  Serial.begin(9600);
  Serial.println("Startup");
}
#define VIIVE 25

byte tehoS1,tehoS2=0; //muuttujat tehon säätämiseen
bool countUpS1, countUpS2 = true; //muuttujat suunnan määrämiseen

void breathS1(){
  analogWrite(LedS1Vi, tehoS1);
  analogWrite(LedS1Va, tehoS1);
  analogWrite(LedS1Pu, tehoS1);
  if( countUpS1 == true ) {
    tehoS1 = tehoS1 +1;//Kasvata muuttujan arvoa yhdellä
  }else{
    tehoS1 = tehoS1 -1;//Pienennä muuttujan arvoa yhdellä
  }
  if(tehoS1 == 255){
    countUpS1 = false;
    Serial.println("Count DownS1");
  }
  if(tehoS1 == 0) {
    countUpS1 = true;
    Serial.println("Count upS1");
  }
  
}

void breathS2(){
  analogWrite(LedS2Vi, tehoS2);
  analogWrite(LedS2Va, tehoS2);
  analogWrite(LedS2Pu, tehoS2);
  if( countUpS2 == true ) {
    tehoS2 = tehoS2 +2;//Kasvata muuttujan arvoa kahdella
  }else{
    tehoS2 = tehoS2 -2;//Pienennä muuttujan arvoa kahdella
  }
  if(tehoS2 == 254){
    countUpS2 = false;
    Serial.println("Count DownS2");
  }
  if(tehoS2 == 0) {
    countUpS2 = true;
    Serial.println("Count upS2");
  }
  
}
void loop(){
  breathS1();
  breathS2();
  delay(VIIVE);// Ainoa viive ohjelmassa
}
