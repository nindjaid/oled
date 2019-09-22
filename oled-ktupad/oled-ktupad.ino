#include <ESP8266WiFi.h>
#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include <Wire.h>
#include <ESP8266HTTPClient.h>

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 OLED(OLED_RESET);

const char *ssid =  "ktupad.com";   
const char *pass =  "wifi@ktupad"; 
String kirim = "http://oled-ktupad.gearhostpreview.com/sensor/?id=1";

void setOLED(String txt){
  OLED.begin();
  OLED.clearDisplay();
  OLED.setTextWrap(false);
  OLED.setTextSize(3);
  OLED.setTextColor(WHITE);
  OLED.setCursor(0,0);
  OLED.println(txt);
  OLED.display();
  OLED.startscrollleft(0x00, 0x0F); 
}
  
void getID(){
  HTTPClient http;
  http.begin(kirim);
  int statusCode = http.GET();
  String txt=http.getString();
  
  Serial.println(txt);
  http.end();
  setOLED(txt);
 }
 

void setup()   {
  Serial.begin(115200);    // Initialize serial communications
  delay(250);
  Serial.println(F("Booting...."));

  WiFi.begin(ssid, pass);
  
  int retries = 0;
  while ((WiFi.status() != WL_CONNECTED) && (retries < 10)) {
    retries++;
    delay(500);
    Serial.print(".");
  }
  
  if (WiFi.status() == WL_CONNECTED) { Serial.println(F("WiFi connected")); }
  
} 
 
void loop() {
  getID();
  delay(5000);
}
