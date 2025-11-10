// Include LCD library
#include <LiquidCrystal.h>

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#define pH_PIN A0 // Potentiometer as pH Sensor

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Simulating pH");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(pH_PIN); // Read from potentiometer
  float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
  float pHValue = voltage * 2.8; // Approximate pH conversion (0-14 range)

  lcd.setCursor(0, 0);
  lcd.print("pH Value: ");
  lcd.print(pHValue);

  lcd.setCursor(0, 1);
  if (pHValue < 6.5) {
    lcd.print("Acidic (Lime)");
  } else if (pHValue > 7.5) {
    lcd.print("Basic (milk)");
  } else {
    lcd.print("Neutral (Water)");
  }

  Serial.print("pH Value: ");
  Serial.println(pHValue);

  delay(2000); // Wait for next reading
}
