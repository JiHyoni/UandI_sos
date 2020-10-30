#include <SPI.h>
#include "SoftwareSerial.h"
SoftwareSerial Serial1(2,3); // RX, TX
#include "WiFiEsp.h"
#define E 330
#define DEVICEID "vCC960B7D5EBA996"
#include<Wire.h>
#include<time.h>

int tempo = 500; // duration 옵션 값을 설정

const char* ssid = "square 12F-1";  // 누구나  
const char* pass = "micimpact"; // 비번

const char* server = "api.pushingbox.com";
int buttonPin = 8; //pin 번호 8에 + 와 GND 연결
WiFiEspClient client;

void setup() {
  //Serial.begin(9600);
  Serial.begin(115200);
  // initialize serial for ESP module
  Serial1.begin(9600);
  // initialize ESP module
  WiFi.init(&Serial1);
  pinMode(buttonPin, INPUT_PULLUP); 
// 와이파이 연결시도
  int status = WL_IDLE_STATUS;     // the Wifi radio's status

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }

  // you're connected now, so print out the data:

  Serial.println("You're connected to the network");
}

void loop(){

  if(digitalRead(buttonPin)==LOW){
    // Serial.println(digitalRead(buttonPin));
    Serial.println("SOS 버튼이 눌렸습니다.");
    tone(13,E, tempo);
    wifiMode();
    }
  }

void wifiMode(){
  if (client.connect(server, 80)) {
    // send the HTTP PUT request
    client.print(F("GET /pushingbox?devid="));
    client.print(DEVICEID);
    client.print(F(" HTTP/1.1\r\n"));
    client.print(F("Host: api.pushingbox.com\r\n"));
    client.print(F("User-Agent: Arduino\r\n"));
    client.print(F("\r\n\r\n"));
  }
  else {
    // if you couldn't make a connection
    Serial.println("Connection failed");
  }
}
