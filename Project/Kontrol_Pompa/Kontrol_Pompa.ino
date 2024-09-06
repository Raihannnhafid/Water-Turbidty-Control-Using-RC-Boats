//#define BLYNK_TEMPLATE_ID "TMPLmcTdmYS-"
//#define BLYNK_DEVICE_NAME "kontrol relay"
//#define BLYNK_AUTH_TOKEN "4FmqtfWvA_sv4WipwIW-mrvtdrlQXhWp"

#define BLYNK_AUTH_TOKEN "fpZ-5GldQcyveHrbhzvXmdbTqSkpwivG"
#define BLYNK_TEMPLATE_ID "TMPL6bQM9b12c"
#define BLYNK_TEMPLATE_NAME "Control Robot"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "RAHMAT GANTENG";  // type your wifi name
char pass[] = "rahmatasu";  // type your wifi password

BlynkTimer timer;
#define relay 2
int SW_relay = 0;

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


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
