int sensorPin = 33; //A0 FOR ARDUINO/ 36 FOR ESP

void setup()
{ 
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  int turbidity = map(sensorValue, 0, 750, 100, 0);
  delay(100);
  if (turbidity < 20) {
    lcd.setCursor(0, 1);
    lcd.print(" its CLEAR ");
    Serial.print(" its CLEAR ");
  }
  if ((turbidity > 20) && (turbidity < 50)) {
    lcd.setCursor(0, 1);
    lcd.print(" its CLOUDY ");
    Serial.print(" its CLOUDY ");
  }
  if (turbidity > 50) {
    lcd.setCursor(0, 1);
    lcd.print(" its DIRTY ");
    Serial.print(" its DIRTY ");
  }
}
