#include <LiquidCrystal.h>
#include <dht.h>

#define DHT11_PIN 7
#define BUTTON_PIN 2

dht DHT;
int bstate = 0;
float savedTemp;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  bstate = digitalRead(BUTTON_PIN);
  int chk = DHT.read11(DHT11_PIN);
  if (DHT.temperature > savedTemp || DHT.temperature < savedTemp) {
    Serial.println("TEMPERATURE CHANGED!!");
    delay(5000);
    //indicate somehow the temperature has changed (SPEAKER,)
  }
  if (bstate == HIGH) {
    savedTemp = DHT.temperature;
    Serial.print("Temp saved: ");
    Serial.println(DHT.temperature);
  } else {
    Serial.print("Temp: ");
    Serial.println(DHT.temperature);
  }
  delay(1000);
}
