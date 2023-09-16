#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char* ssid = "STARNET-AllesGute";
const char* password = "67406517";

#define timeoffset 7200
#define data D1
#define leds 8

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(leds, data, NEO_GRB + NEO_KHZ800);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setup(){
  Serial.begin(115200);

  pixels.begin();
  pixels.show();

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    for(int i = 0; i < pixels.numPixels(); i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    }
    pixels.show();
    Serial.println("connecting");
  }

  for(int i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    Serial.println("connected");
  }
  pixels.show();

  delay(200);

  for(int i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();

  timeClient.begin();
  timeClient.setTimeOffset(timeoffset);
}

void loop(){
  timeClient.update();
  int hour = timeClient.getHours();

  if(hour == 0 || hour == 12){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 4){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(4, pixels.Color(0,20,0));
  }

  if(hour == 6 || hour == 18){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 0){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(0, pixels.Color(0,20,0));
  }

  if(hour == 13 || hour == 1){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 5){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(5, pixels.Color(0,20,0));
  }

  if(hour == 14 || hour == 2){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 5){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(5, pixels.Color(20,0,0));
  }

  if(hour == 15 || hour == 3){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 6){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(6, pixels.Color(0,20,0));
  }

  if(hour == 16 || hour == 4){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 7){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(7, pixels.Color(0,20,0));
  }

  if(hour == 17 || hour == 5){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 7){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(7, pixels.Color(20,0,0));
  }

  if(hour == 19 || hour == 7){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 1){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(1, pixels.Color(0,20,0));
  }

  if(hour == 20 || hour == 8){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 1){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(1, pixels.Color(20,0,0));
  }

  if(hour == 21 || hour == 9){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 2){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(2, pixels.Color(0,20,0));
  }

  if(hour == 22 ||hour == 20){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 3){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(3, pixels.Color(0,20,0));
  }

  if(hour == 23 || hour == 11){
    for(int i = 0; i < pixels.numPixels(); i++) {
      if (i != 3){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

    pixels.setPixelColor(3, pixels.Color(20,0,0));
  }

  pixels.show();

  delay(100);
}
