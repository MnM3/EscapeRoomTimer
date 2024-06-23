
#include <SoftwareSerial.h>

const byte rxPin = 3;
const byte txPin = 2;
const byte buttonPin = 5;

SoftwareSerial BTSerial(rxPin, txPin);

void setup() {
  
  //define pin modes for tx, rx:
  pinMode (rxPin, INPUT);
  pinMode (txPin, OUTPUT);
  pinMode (buttonPin, INPUT_PULLUP);
  BTSerial.begin(9600);
  Serial.begin(9600);
}

String messageBuffer = "";
String message = "";
bool send_message = false;

void loop() {
  //Serial.print(digitalRead(buttonPin));
  if (digitalRead(buttonPin) == 0 && send_message == false) {
    Serial.print("Send");
    BTSerial.print("play_sound\n");
    send_message = true;
    delay(2000);
  } else if (digitalRead(buttonPin) == 1 && send_message == true) {
    send_message = false;
  }
  /*
  if(BTSerial.available()) {
    Serial.print(BTSerial.read());
  }
  BTSerial.print("Hello form the other side\n");
  delay(5000);
  */
}
