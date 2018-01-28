#include <Servo.h> 
 
Servo myservoa, myservob, myservoc, myservod, myservoe;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;
char space = ' ';
int servodata;
int arrays[] = {0,0,0,0,0};
int per_array[] = {0,0,0,0,0};//{int('0'),int('0'),int('0'),int('0'),int('0')};
String incomingByte = "";
void setup()  {
  Serial.begin(9600);
  myservoe.attach(8);
  myservod.attach(9);
  myservoc.attach(10);
  myservob.attach(11);
  myservoa.attach(12); 
}
void copy(){
  for (int i =0 ; i < 5; i ++){
    arrays[i] = per_array[i];
  }
}

void finder(int a){
  if (a == 49){
    arrays[0] = 49;
  }else if (a==50){
    arrays[1] = 50;
  }else if (a==51){
    arrays[2] = 51;
  }else if (a==52){
    arrays[3] = 52;
  }else if (a==53){
    arrays[4] = 53;
  }
}
void loop()   
{
  if (Serial.available() > 0) {
    // read the incoming byte:
    copy();
    Serial.println(arrays[0]);
    incomingByte = Serial.readString();
    int count = 0;
    for (int i = 0; i < incomingByte.length(); i++){
      if (incomingByte[i] != space){
        finder((int)incomingByte[i]);
      }
    }
    for (int i = 0; i < 5; i++){
      Serial.print(arrays[i],DEC);
    }
    
    Serial.println("Executed");
    Serial.print(arrays[2]+"a");
    if (arrays[0] == 49){
      Serial.println(arrays[0]);
      myservoa.write(0);
    }else{
      myservoa.write(180);
    }
    
    if (arrays[1] == 50){
      Serial.println(arrays[1]);
      myservob.write(0);
    }else{
      myservob.write(180);
    }
    
    if (arrays[2] == 51){
      Serial.println(arrays[2]);
      myservoc.write(0);
    }else{
      myservoc.write(180);
    }
    
    if (arrays[3] == 52){
      Serial.println(arrays[3]);
      myservod.write(180);
    }else{
      myservod.write(0);
    }
    
    if (arrays[4] == 53){
      Serial.println(arrays[4]);
      myservoe.write(180);
    }else{
      myservoe.write(0);
    }
  }
}      

