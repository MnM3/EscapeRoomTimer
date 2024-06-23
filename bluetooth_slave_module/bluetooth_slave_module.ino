
#include <SoftwareSerial.h>

const byte rxPin = 3;
const byte txPin = 2;

SoftwareSerial BTSerial(rxPin, txPin);

void setup() {
  
  //define pin modes for tx, rx:
  pinMode (rxPin, INPUT);
  pinMode (txPin, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}

String messageBuffer = "";
String message = "";

void loop() { 

  while (BTSerial.available() > 0) {
    char data = (char) BTSerial.read();
    messageBuffer += data;
    //Serial.print(data);
    if (data == '\n') {
      message = messageBuffer;
      messageBuffer = "";
      Serial.print(message); // send to serial monitor
      //Serial.print(message);
      message = "You sent " + message;
      BTSerial.print(message);
    }
  }
  //Serial.write("waiting...\n");
}

