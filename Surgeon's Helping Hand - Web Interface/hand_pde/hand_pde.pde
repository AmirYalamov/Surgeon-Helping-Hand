/*
 * Recieve instructions for robot control through website. 
 * http://wossrobotics.ca/LED_data.txt
 * To make this code work internet connection is needed
 * @Author : Aman Adhav
 * June 1st 2017
 */

import processing.serial.*;
import java.net.InetAddress;
// initialize arduino ports
Serial port;
Serial port1;

void setup () { 
  //size(600, 600);  // set up the window to whatever size you want
  println(Serial.list());  // List all the available serial ports
  String portName = "COM3"; // Change these port names as need according to the port list
  //String portName1 = "COM7"; // Change these port names as need according to the port list
  
  // Define baud rate for the ports and make sure in the beginning they are clear
  port = new Serial(this, portName, 9600); 
  //port1 = new Serial(this, portName1, 9600);
  port.clear();
  //port1.clear();
  
}
public boolean isServerAlive()
  // To check if server is reachable
{
  
  try {
    
    InetAddress.getByName("wossrobotics.ca").isReachable(3000); //this checks if the website is reachable with 3000 as maximum ping
    return true;
  } 
  catch (Exception e) {
    return false;
  }
}
String previous = "";
void draw(){

  // If the website is active
  if (isServerAlive()) {
    String onoffdata[] = loadStrings("http://wossrobotics.ca/Hand_data.txt"); //load the character (instruction from the website)
    String line = "";
    for (int i = 0; i < onoffdata.length; i++){
      line = line + onoffdata[i];
    }
    //port.write(line);
    if (line.equals(previous) == false){
       println(line);
       port.write(line);
       previous = line;
    }
  }else{
    text("POP A HOYA",10,100);
  }
  
}