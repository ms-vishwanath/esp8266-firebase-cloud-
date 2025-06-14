#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>


#define ssid "cloud360"
#define password "cClLoOuUdD360"
#define FIREBASE_HOST "web-ranger-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "LUj4ZihWoZPo9XyuEF0BxMefr6b4u4e9BzWQaeaN"

FirebaseData firebaseData;
FirebaseData fbdo;
void setup() {
  pinMode(D5,OUTPUT);
  WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
}
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  Firebase.setString(fbdo, F("BULBSYSTEM2"), "ON"); 
if (Firebase.get(firebaseData, "BULB2"))
{
if (firebaseData.dataType() == "string")
{
String BULB = firebaseData.stringData();
if (BULB == "ON") { 

digitalWrite(D5,LOW);
}
else if (BULB == "OFF") { 

digitalWrite(D5,HIGH);
}
else if (BULB.startsWith("ON")) {
        int n = BULB.substring(2).toInt();
digitalWrite(D5,LOW);
        delay(n * 1000);
digitalWrite(D5,HIGH);
        Firebase.setString(fbdo, F("BULB2"), "OFF");
}
else if (BULB.startsWith("OFF")) {
        int n = BULB.substring(3).toInt();
digitalWrite(D5,HIGH);
        delay(n * 1000);
digitalWrite(D5,LOW);
        Firebase.setString(fbdo, F("BULB2"), "ON");
}}}
}
