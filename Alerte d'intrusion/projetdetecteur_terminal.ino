#include <analogWrite.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define signal_mouvement 14
#define signal_detecte 21
#define buzzer 32

void setup() {
  // put your setup code here, to run once:
  pinMode(signal_mouvement, OUTPUT);
  pinMode(signal_detecte, INPUT);
  pinMode(buzzer, OUTPUT);
  SerialBT.begin("detecteur");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(signal_mouvement, LOW);
  if(digitalRead(signal_detecte)==LOW){
    analogWrite(buzzer, 0);
    printf("pas de mouvement\n\r");
  }
  else if(digitalRead(signal_detecte==HIGH)){
    SerialBT.println("mouvement detecte");
    while(1){
      analogWrite(buzzer, 255);
      printf("mouvement oui\n\r");
    }
  }
  
}
