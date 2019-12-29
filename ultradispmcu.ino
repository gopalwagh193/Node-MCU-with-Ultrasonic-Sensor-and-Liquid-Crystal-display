
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
#define BLYNK_PRINT Serial
long dur;
float inc;
float cm;

const int eco=D4;
const int tri=D3;


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "9f1accc018f94d14a3fefb797e02ab98";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "note4";
char pass[] = "123456788";

void setup()
{
  
  lcd.begin(16,2);
// Debug console
  Serial.begin(9600);
  
  pinMode(eco,INPUT);
  pinMode(tri,OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  
  Blynk.run();

  digitalWrite(tri,LOW);
  delayMicroseconds(5);

  digitalWrite(tri,HIGH);
  delayMicroseconds(10);

  digitalWrite(tri,LOW);

  
  dur=pulseIn(eco,HIGH);

  cm=dur * 0.034 /2;
  inc=dur * 0.138 /2;

  Serial.println("cm:");
  Serial.println(cm);

  Serial.println("INCH:");
  Serial.println(inc);

  
  lcd.setCursor(0,0);
  lcd.print("cm:");
  lcd.print(cm);
  lcd.setCursor(0,1);
  lcd.print("INCH:");
  lcd.print(inc);

  Blynk.virtualWrite(V1,"CM:");
  Blynk.virtualWrite(V2,cm);
  Blynk.virtualWrite(V3,"INC:");
  Blynk.virtualWrite(V4,inc);
  
  

}
