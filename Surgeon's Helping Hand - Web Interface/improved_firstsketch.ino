#include <Servo.h> 
 
Servo myservoa, myservob, myservoc, myservod, myservoe;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;
char space = ' ';
char under_score = '_';
int servodata;
int arrays[] = {0,0,0,0,0};
int angle_arrays[] = {0,0,0,0,0};
int per_array[] = {0,0,0,0,0};//{int('0'),int('0'),int('0'),int('0'),int('0')};
int angle_index_pos = 0;
String incomingByte = "";
boolean trigger = true;
void setup()  {
  Serial.begin(9600);
  myservoa.attach(8);
  myservob.attach(9);
  myservoc.attach(10);
  myservod.attach(11);
  myservoe.attach(12); 
}
void copy(){
  for (int i =0 ; i < 5; i ++){
    arrays[i] = per_array[i];
  }
}

void finder(int a, bool trig){
  if (trig == true){
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
  }else{
    angle_arrays[angle_index_pos] = a;
    angle_index_pos += 1;
  }
}
void loop()   
{
  if (Serial.available() > 0) {
    // read the incoming byte:
    copy();
    //Serial.println(arrays[0]);
    incomingByte = Serial.readString();
    int count = 0;
    for (int i = 0; i < incomingByte.length(); i++){
      if (incomingByte[i] != under_score){
        finder((int)incomingByte[i], trigger);
      }else{
        trigger = false;
      }
    }
    for (int i = 0; i < 5; i++){
      //Serial.println(arrays[i],DEC);
      Serial.println(angle_arrays[i], DEC);
    }
    trigger = true;
    angle_index_pos = 0;
    Serial.println("Executed");
    Serial.println("input");
    if (arrays[0] == 49){
      Serial.print(arrays[0]);
      Serial.println("thumb");
      myservoa.write(45*(angle_arrays[0]-47));
    }else{
      myservoa.write(0);
    }
    
    if (arrays[1] == 50){
      Serial.print(arrays[1]);
      Serial.println("second finger");
      myservob.write(45*(angle_arrays[0]-47));
    }else{
      myservob.write(0);
    }
    
    if (arrays[2] == 51){
      Serial.print(arrays[2]);
      Serial.println("third finger");
      myservoc.write(180-(45*(angle_arrays[0]-47)));
    }else{
      myservoc.write(180);
    }
    
    if (arrays[3] == 52){
      Serial.print(arrays[3]);
      Serial.println("fourth finger");
      myservod.write(180-(45*(angle_arrays[0]-47)));
    }else{
      myservod.write(180);
    }
    
    if (arrays[4] == 53){
      Serial.print(arrays[4]);
      Serial.println("fifth Finger");
      myservoe.write(180-(45*(angle_arrays[0]-47)));
    }else{
      myservoe.write(180);
    }
  }
}      
