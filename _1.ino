#include <Servo.h>

int randNumber; //변수 설정
int led1=4;
int led2=3;
int led3=2;
int led4=12;
int trig=7;
int echo=6;
int but=11;
Servo mySvo1;
Servo mySvo2;

long distance(){    //거리 함수
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration=pulseIn(echo, HIGH);
  long distance=duration/58.2;
  return distance;
}

void product(){   //품목 배출 함수
  for(int i=0;i<4;i++){
    digitalWrite(led3, LOW);
    digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(250);
  }
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(500);
  
  randNumber=random(10);
  
  if(randNumber>=0 && randNumber<4){
    digitalWrite(led1, HIGH);
    tone(A0, 523, 100);
    delay(150);
    mySvo1.write(160);
    delay(1000);
    mySvo1.write(0);
    digitalWrite(led1, LOW);
  }
  else if(randNumber>=4 && randNumber<8){
    digitalWrite(led2, HIGH);
    tone(A0, 523, 100);
    delay(150);
    mySvo2.write(160);
    delay(1000);
    mySvo2.write(0);
    digitalWrite(led2, LOW);
  }else{
    digitalWrite(led3, HIGH);
    tone(A0, 523, 100);
    delay(150);
    digitalWrite(led3, LOW);
  }
  digitalWrite(led4, LOW);
  
  return;
}
  
void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A4));
  mySvo1.attach(A2);
  mySvo2.attach(A1);
  mySvo1.write(0);
  mySvo2.write(0);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(but, INPUT);
  pinMode(A0, OUTPUT);
}

void loop()
{
  distance();
  if(distance()<15)
  {
    digitalWrite(led4, HIGH);
    Serial.print(1); //작동 확인용
    if(digitalRead(but)==HIGH)
    {
      product();
   	}
  }
  
  delay(100); 
}