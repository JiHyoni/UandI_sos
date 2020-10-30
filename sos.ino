#include<Wire.h>
#include<time.h>
#define E 330

int buttonPin = 8; //pin 번호 8에 + 와 GND 연결
//time_t now = time(NULL);
int tempo = 500; // duration 옵션 값을 설정
// sos 버튼 구성 -> 버튼 누르면 소리나고 , db 에 저장해주는 코드 
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); // 스위치를 구성하기 쉬운 방법 INPUT_PULLUP
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin)==LOW){
    // 스위치가 눌렸을 때, 떼어졌을 때 무슨 숫자가 나올지 찍어봄
    // Serial.println(digitalRead(buttonPin));
    Serial.println("SOS 요청입니다.");
    tone(13,E, tempo);
    delay(500);
    }
}
