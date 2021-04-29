#include <Servo.h>
Servo servo1;
int trigPin = 2;
int echoPin = 1;
int pinpot=A1;
int Red= 4;
int Blue= 5;
int Green= 6;
int value;
long distance;
long duration;
 
void setup() 
{
servo1.attach(3); 
 pinMode(Red, OUTPUT);
 pinMode(Blue, OUTPUT);
 pinMode(Green, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}
 
void loop() {
  ultra();
  value= analogRead(pinpot);
  servo1.write(0);
  if(distance >=100){
  servo1.write(60);
  
  digitalWrite(Red,HIGH);
  delay(2000);
  digitalWrite(Red, LOW);
  delay(1000);
  }
  //ultra();
  else{servo1.write(0);}
   if (distance>=100){
   servo1.write(120);
   digitalWrite(Blue,HIGH);
   delay(2000);
   digitalWrite(Blue,LOW);
   delay(1000);
 }
    //ultra();
  else{servo1.write(0);}
   if (distance>=100){
   servo1.write(180);
   digitalWrite(Green,HIGH);
   delay(2000);
   digitalWrite(Green,LOW);
   delay(1000);
 }
    
  else{servo1.write(0);}
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.343/2;
}
