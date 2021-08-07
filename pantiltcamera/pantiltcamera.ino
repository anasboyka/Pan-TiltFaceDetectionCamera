#include <Servo.h>


Servo pan;
Servo tilt;
int postilt = 0;
int postiltms = 0;

int right = 170;
int left = 80;
int mid = 125;
void setup() {
Serial.begin(19200);
pinMode(13,OUTPUT);
pan.attach(3);
tilt.attach(5);  
delay(1000);
pan.write(90);
postiltms = 125;
postilt = map(postiltms,0,250,550,2400);
tilt.write(postilt);
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
}
void loop() {
  
  if (Serial.available()>0){
  char data = Serial.read();

if(data == 'm'){
  digitalWrite(13,HIGH);
 //postiltms = map(tilt.read(),0,250,550,2400);
  //postilt = map(postiltms,0,250,500,2400);
  
   tilt.write(tilt.read());
   
   
    }
else if(data == 'l'){
  digitalWrite(13,LOW);
     int p = map(tilt.read(),0,180,0,250);
     if((p>=0)&&(p<=250)){
    p+=1;
      //postiltms = p-1;
      //postilt = map(p,0,250,550,2400);
      tilt.write(tilt.read()-1);
      }
      
      }
      else if(data == 'L'){
  digitalWrite(13,LOW);
     int p = map(tilt.read(),0,180,0,250);
     if((p>=0)&&(p<=250)){
    p+=1;
      //postiltms = p-1;
      //postilt = map(p,0,250,550,2400);
      tilt.write(tilt.read()-2);
      }
      
      }
else if (data == 'r'){
  digitalWrite(13,LOW);
       int p = map(tilt.read(),0,180,0,250);
     if((p<=250)&&(p>=0)){
      p=p-1;
      //postiltms = p-1;
      //postilt = map(p,0,250,500,2400);
      tilt.write(tilt.read()+1);
      }
      
        }
        else if (data == 'R'){
  digitalWrite(13,LOW);
       int p = map(tilt.read(),0,180,0,250);
     if((p<=250)&&(p>=0)){
      p=p-1;
      //postiltms = p-1;
      //postilt = map(p,0,250,500,2400);
      tilt.write(tilt.read()+2);
      }
      
        }
         else if (data == 't'){
  digitalWrite(13,LOW);
       int p = map(tilt.read(),0,180,0,250);
     if((p<=250)&&(p>=0)){
      p=p-1;
      //postiltms = p-1;
      //postilt = map(p,0,250,500,2400);
      tilt.write(tilt.read()+4);
      }
      
        }
             else if (data == 'k'){
  digitalWrite(13,LOW);
       int p = map(tilt.read(),0,180,0,250);
     if((p<=250)&&(p>=0)){
      p=p-1;
      //postiltms = p-1;
      //postilt = map(p,0,250,500,2400);
      tilt.write(tilt.read()-4);
      }
      
        }
        if(data == 'c'){
 
   pan.write(pan.read());
   
   
    }
else if(data == 'u'){
  if((pan.read()>=0)&&(pan.read()<=180)){
      pan.write(pan.read()+1);
      }

      }
      else if(data == 'U'){
  if((pan.read()>=0)&&(pan.read()<=180)){
      pan.write(pan.read()+2);
      }
      }
      
else if (data == 'd'){
  if((pan.read()>=0)&&(pan.read()<=180)){
      pan.write(pan.read()-1);
      }
}
        else if (data == 'D'){
 if((pan.read()>=0)&&(pan.read()<=180)){
      pan.write(pan.read()-2);
      }
        }
      
        
         else if (data == 's'){
  if((pan.read()>=0)&&(pan.read()<=180)){
      pan.write(pan.read()-4);
      }
         }
        
             else if (data == 'i'){
 if((pan.read()>=0)&&(pan.read()<=180)){
      pan.write(pan.read()+4);
      }
             }
        }}
