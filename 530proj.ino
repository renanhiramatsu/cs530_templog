#include <LiquidCrystal.h>
#include <dht.h>

// Length of time between cycles in milliseconds
#define INTERVAL 1000
// Temperature Sensor Pin
#define DHT11_PIN 7
// Button Pin
#define BUTTON_PIN 8
// LCD Pins:
#define RS 12
#define EN 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

// Initialize global variables
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
dht DHT;
int bstate = 0;
float savedTemp;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  lcd.begin(16, 2);
  lcd.print("Temp Sensor");
  delay(2000);
}

void loop() {
  bstate = digitalRead(BUTTON_PIN); // Read button press at start of loop
  int curtmp = DHT.read11(DHT11_PIN); // Read temperature from sensor after button press
  if (bstate == HIGH) { // If button is pressed, override everything and save current temperature
    savedTemp = DHT.temperature;
    Serial.print("Temp saved: ");
    Serial.println(DHT.temperature);
    lcd.clear();
    lcd.print("Temp Saved: ");
    lcd.print(DHT.temperature);
  } else if (DHT.temperature < savedTemp) { // If current temp is less than saved temp (colder)
    Serial.println("Colder...");
    lcd.clear();
    lcd.print("Colder: ");
    lcd.print(DHT.temperature);
    savedTemp = 0;
  } else if (DHT.temperature > savedTemp) { // If current temp is greater than saved temp (warmer)
    Serial.println("Hotter!!!"); // replace/add lcd usage
    lcd.clear();
    lcd.print("Hotter: ");
    lcd.print(DHT.temperature);
    savedTemp = 0;
  } else { // If current temp = saved temp, and button is not pressed
    Serial.print("Temp: ");
    Serial.println(DHT.temperature);
    lcd.clear();
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
  }
  delay(INTERVAL); // 
}
