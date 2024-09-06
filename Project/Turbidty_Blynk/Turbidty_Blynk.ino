#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#define BLYNK_AUTH_TOKEN "fpZ-5GldQcyveHrbhzvXmdbTqSkpwivG"

#define BLYNK_PRINT Serial

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "RAHMAT GANTENG";  // type your wifi name
char pass[] = "rahmatasu";  // type your wifi password

int sensorPin = 33; //A0 FOR ARDUINO/ 36 FOR ESP
BlynkTimer timer;

void setup()
{ 
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}
void loop() {
   Blynk.run();
  timer.run();
  
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  Blynk.virtualWrite(V5, sensorValue);
  int turbidity = map(sensorValue, 0, 750, 100, 0);
  delay(100);
  if (turbidity < 20) {
    Serial.print(" its CLEAR ");
  }
  if ((turbidity > 20) && (turbidity < 50)) {
    Serial.print(" its CLOUDY ");
  }
  if (turbidity > 50) {
    Serial.print(" its DIRTY ");
  }
}
