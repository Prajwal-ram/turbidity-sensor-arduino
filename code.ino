#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // LCD at I2C address 0x3F
int sensorPin = A0;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int turbidity = map(sensorValue, 0, 640, 100, 0);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turbidity: ");
  lcd.print(turbidity);
  
  if (turbidity < 20) {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Its CLEAR   ");
  }
  else if (turbidity < 50) {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Its CLOUDY  ");
  }
  else {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Its DIRTY   ");
  }
  
  delay(500);
}
