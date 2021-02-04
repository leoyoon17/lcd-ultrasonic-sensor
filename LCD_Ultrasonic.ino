/*
The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4= 5, d5 = 4, d6 = 3, d7 = 2, trig = 7, echo = 8;

long duration;
int distance;


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  USRead();
  delay(500);
  lcd.clear();

}

// Ultrasonic Read
void USRead() {
  //  clear trig
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // Send sound for 10 microseconds 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.034 / 2;

  LCDRead(distance);
  
}

void LCDRead(int distance) {
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print(" cm");
  
  
  
}
