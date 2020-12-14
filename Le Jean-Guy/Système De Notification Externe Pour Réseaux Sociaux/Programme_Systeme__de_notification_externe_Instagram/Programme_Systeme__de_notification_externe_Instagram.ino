/*******************************************************************
 *  An example of usisng the InstagramStats library to get
 *  info on a given user
 *
 *  Written by Brian Lough
 *  https://www.youtube.com/channel/UCezJOfu7OtqGzd5xrP3q6WA
 *******************************************************************/

#include "InstagramStats.h"

 // ----------------------------
 // Standard Libraries - Already Installed if you have ESP32 set up
 // ----------------------------

#include <WiFi.h>
#include <WiFiClientSecure.h>

// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------

#include "JsonStreamingParser.h"
// Used to parse the Json code within the library
// Available on the library manager (Search for "Json Streamer Parser")
// https://github.com/squix78/json-streaming-parser

//------- Replace the following! ------
char ssid[] = "HUAWEI P20";       // your network SSID (name)
char password[] = "12345ed6789";  // your network key

WiFiClientSecure client;
InstagramStats instaStats(client);

unsigned long delayBetweenChecks = 60000; //mean time between api requests
unsigned long whenDueToCheck = 0;

//Inputs
String userName = "edwardricher"; // from their instagram url https://www.instagram.com/brian_lough/
//compteur de follower
int memoire;
int follower_actu;
const int ledPin =  13;

void setup() {

  Serial.begin(115200);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  pinMode(ledPin, OUTPUT);
}

void getInstagramStatsForUser() 
{
  Serial.println("Getting instagram user stats for " + userName );
  InstagramUserStats response = instaStats.getUserStats(userName);
  follower_actu = response.followedByCount;
  if( memoire != follower_actu)
  {
    for(int i=0; i < 5; i++)
    { 
      digitalWrite(ledPin, HIGH); 
      delay(300);
      digitalWrite(ledPin, LOW); 
      delay(300);
    }
  }
  Serial.println("Response:");
  Serial.print("Number of followers: ");
  memoire = follower_actu;
  Serial.println(response.followedByCount);
}

void loop() {
  unsigned long timeNow = millis();
  if ((timeNow > whenDueToCheck))  {
    getInstagramStatsForUser();
    whenDueToCheck = timeNow + delayBetweenChecks;
  }
}
