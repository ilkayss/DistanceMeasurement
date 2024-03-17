#include <LiquidCrystal.h>

const int trigPin = 7;
const int ecoPin = 6;

int sure, uzaklik;

int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(ecoPin, INPUT);

  lcd.begin(16, 2);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(ecoPin, HIGH ,11600); 
  uzaklik = sure * 0.0345 / 2;

  Serial.print("Sag uzaklik");
  Serial.println(uzaklik);

  delay(250);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Uzaklik:");
  lcd.setCursor(0, 1);
  lcd.print(uzaklik);
  lcd.print(" cm"); 
}
