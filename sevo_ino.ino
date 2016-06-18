#include<Servo.h>

#define minn1 60
#define maxx1 130

#define minn2 20
#define maxx2 70 

#define minn3 0
#define maxx3 60

#define minn4 0
#define maxx4 70


#define steady1 130
#define steady2 20
#define steady3 20
#define steady4 70 


#define delayMotor 15

int servoPin1 = 9;
int servoPin2 = 10;
int servoPin3 = 11;
int servoPin4 = 12;


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor


int angle=0;


void setup()
{
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  Serial.begin(9600);
}

void loop()
{ 
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  Serial.println(sensorValue);
  
  if(sensorValue > 0 &&  sensorValue< 6m00){
  
    handGrip();
    
  }else {
    
    wristMovement();
    
  }
  
}

void handGrip(){
  
  servo1.write(steady1);
  servo2.write(steady2);
  servo3.write(steady3); 
 
    //int count = 2; 
  
   //while(count--){
    for(angle = minn4; angle < maxx4;angle++){
              
              servo4.write(angle);
              delay(delayMotor);
     }
     
     for(angle = maxx4; angle > minn4; angle--){
              
              servo4.write(angle);
              delay(delayMotor);
     }
  // }
}


void wristMovement(){
  
  servo1.write(steady1);
  servo2.write(steady2);
  servo4.write(steady4); 
  
  //int count = 2; 
  
  // while(count--){
    for(angle = minn3; angle < maxx3; angle++){
              
              servo3.write(angle);
              delay(delayMotor);
     }
     
     for(angle = maxx3; angle > minn3; angle--){
              
              servo3.write(angle);
              delay(delayMotor);
     }
   //}
}

void elbowMovement(){
  
  servo1.write(steady1);
  servo3.write(steady3);
  servo4.write(steady4); 
 
 
   // int count = 2; 
  
   //while(count--){    
    for(angle = minn2; angle < maxx2; angle++){
      
              servo2.write(angle);
              delay(delayMotor);
     }
     
     for(angle = maxx2; angle > minn2; angle--){
              
              servo2.write(angle);
              delay(delayMotor);
     }
     
   //}
}



void armMovement(){
  
  servo2.write(steady2);
  servo3.write(steady3);
  servo4.write(steady4); 
 
   //int count = 2; 
  
   //while(count--){ 
  
   
    for(angle = minn1; angle < maxx1; angle++){
              
              servo1.write(angle);
              delay(delayMotor);
     }
     
     for(angle = maxx1; angle > minn1; angle--){
              
              servo1.write(angle);
              delay(delayMotor);
     }
     
   //}
}


