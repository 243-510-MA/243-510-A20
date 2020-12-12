#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


const int stepPin = 25; 
const int dirPin = 26; 


unsigned int vitesse;
unsigned int distance;
char state;

void lecture();
void moteur();

BluetoothSerial SerialBT;

void setup()
{
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() 
{
   lecture();

   if (state == '1')
   {
    distance = 200;
   }if (state == '2')
   {
    distance = 400;
   }if (state == '3')
   {
    distance = 600;
   }if (state == '4')
   {
    distance = 800;
   }if (state == '5')
   {
    distance = 1000;
   }if (state == '6')
   {
    distance = 1200;
   }if (state == '7')
   {
    distance = 1400;
   }if (state == '8')
   {
    distance = 1600;
   }if (state == '9')
   {
    distance = 1800;
   }


   
   if (state == 'A')
   {
    vitesse = 400;
   }
   else if (state == 'B')
   {
    vitesse = 600;
   }
   else if (state == 'C')
   {
    vitesse = 800;
   }
   else if (state == 'D')
   {
    vitesse = 1000;
   }
   else if (state == 'E')
   {
    vitesse = 1200;
   }
   else if (state == 'F')
   {
    vitesse = 1400;
   }
   else if (state == 'G')
   {
    vitesse = 1600;
   }
   else if (state == 'H')
   {
    vitesse = 1800;
   }
   else if (state == 'I')
   {
    vitesse = 2000;
   }

   
  
   if (state == 'd')
   {
    digitalWrite(dirPin,LOW);  
   }
   if (state == 'g')
   {
    digitalWrite(dirPin,HIGH);
   }
   if (state == 'a')
   {
    moteur();
   }
  
}

void lecture()
{
   
   state = SerialBT.read(); // Reads the data from the serial port
   //Serial.write(SerialBT.read());
}

void moteur()
{
  for(int x = 0; x < distance; x++) 
  {
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(vitesse); 
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(vitesse); 
  }
}
 
