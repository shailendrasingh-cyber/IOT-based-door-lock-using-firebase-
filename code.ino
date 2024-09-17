#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID "Enter your WIFI "         
#define _PASSWORD "Enter your WIFI password "     
#define REFERENCE_URL "Enter your firebase realtime data base url"  

#define M1A D5   // 
#define buzzer D6


Firebase firebase(REFERENCE_URL);

void setup() {
  Serial.begin(115200);
  pinMode(M1A, OUTPUT);
  pinMode(buzzer  , OUTPUT );
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  // Connect to WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("IP Address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  int command = firebase.getInt("cmd/Robot"); // Get data from database.

  if(command == 0){ //  STOP
    digitalWrite(M1A, LOW);
    digitalWrite(buzzer  , LOW );
    Serial.print(command);
    
  }

  if(command == 1){ //  FORWARD
    digitalWrite(M1A, HIGH);
    Serial.print(command);
    digitalWrite(buzzer  , HIGH);
    
  }

}