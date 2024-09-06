#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#define BLYNK_AUTH_TOKEN "fpZ-5GldQcyveHrbhzvXmdbTqSkpwivG"
#define BLYNK_TEMPLATE_ID "TMPL6bQM9b12c"
#define BLYNK_TEMPLATE_NAME "Control Robot"


#define BLYNK_PRINT Serial

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Rehat Dulu";  // type your wifi name
char pass[] = "12345678";  // type your wifi password

#define relay 2
int SW_relay = 0;
int sensorPin = 33; //A0 FOR ARDUINO/ 36 FOR ESP
int IN1 = 4;
int IN2 = 5;
int IN3 = 12;
int IN4 = 13;
BlynkTimer timer;

BLYNK_WRITE(V1) { //move forward  
  digitalWrite(IN2, param.asInt());
  digitalWrite(IN4, param.asInt());
}

BLYNK_WRITE(V2) { //move backward
  digitalWrite(IN1, param.asInt());
  digitalWrite(IN3, param.asInt());
}

BLYNK_WRITE(V3) { //turn left
  digitalWrite(IN2, param.asInt());
  digitalWrite(IN3, param.asInt());
}

BLYNK_WRITE(V4) { //turn right
  digitalWrite(IN1, param.asInt());
  digitalWrite(IN4, param.asInt());
}

BLYNK_WRITE(V6)
{
  SW_relay = param.asInt();
  if (SW_relay ==1){
    digitalWrite(relay, HIGH);
    Serial.println("Relay terbuka");
    Blynk.virtualWrite(V6, HIGH);
  }else{
    digitalWrite(relay, LOW);
    Serial.println("Relay tertutup");
    Blynk.virtualWrite(V6, LOW);
  }
}

void setup()
{ 
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(relay, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 8080);
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
