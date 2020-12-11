/*                                                          *
 *                 Code Arduino Projet                      *
 *    243-510-A20 Instrumentation en Systemes Ordinées      *
 *           Léonard Lesage et Sarah Yakoubi                *
 *                                                          */ 
#include <WiFi.h>
// Variable 
const char* ssid = "nom du reseau";                // Nom du réseau
const char* password =  "mot de passe du reseau";  // Mot de passe

const int bouton = 34;                    // Pin d'utilisation du bouton

WiFiServer wifiServer(80);                // Numéro de port

void setup() {

  pinMode(bouton, INPUT);

// Lors de la communication avec l'esp32, l'utilisation du Serial Monitor
// est recommandé pour la détection d'erreur et pour voir ou vous êtes 
// rendu dans le programme. Pour se faire, ouvrez le Serial Monitoir
// et rentrer le même baude rate que si dessous.

  Serial.begin(115200);                   // Baude rate 

  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) { // Connexion au WIFI
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());         // Affiche l'adresse IP 

  wifiServer.begin();
}

void loop() {                             // main

  WiFiClient client = wifiServer.available();

  if (client) {                           // Si connecté au client (le serveur python)
  Serial.println("Client connected");
    while (client.connected()) {          // Tant que connecté
      
        if (digitalRead(bouton) == 1)     // Lorsque le bouton est appuyé
        {
        char c = 'f';                     // Bit envoyé à l'esp32
        Serial.println("le bouton est app");    // Confirmation que le bouton a bien été appuyé  
        client.write(c);                  // Envoye au serveur python la valeur 'c'
        delay(1000);
        }

      delay(10);
    }
    Serial.println(" ");
    client.stop();
    Serial.println("Client disconnected");  // Indique que le client est déconnecté     
  }
}
