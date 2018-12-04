#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial BTSerial(12, 13); //블루투스 설정 BTSerial(Tx, Rx)

int Green = 5;
int Yellow = 7;
int Red = 9;    //led 핀 설정

void setup() {
  BTSerial.begin(9600); //블루투스 통신 시작
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Red, OUTPUT); 
}

void loop() {
  if(BTSerial.available())        //값이 들어오면
  {
    char bt;                     //제어할 변수 bt선언
    bt = BTSerial.read();        //들어온 값을 bt에 저장
    if(bt == 'a')                //bt가 a면
      digitalWrite(Green, HIGH); //초록불 ON
    if(bt == 'b')
      digitalWrite(Yellow, HIGH); //노란불 ON
    if(bt == 'c')
      digitalWrite(Red, HIGH); //빨간불 ON
    if(bt == 'd')
      digitalWrite(Green, LOW); //빨간불 OFF
    if(bt == 'e')
      digitalWrite(Yellow, LOW); //빨간불 OFF
    if(bt == 'f')
      digitalWrite(Red, LOW); //빨간불 OFF
  }
}
