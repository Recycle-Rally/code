char t = '1'; //Set t to equal 1
char appData;  //Define appData to char
String inData = ""; //Set inData to ""
 #include <SoftwareSerial.h> //Include SoftwareSerial.h library
void setup() { //Code that runs once at the begining of runtime
  Serial.begin(9600); //Start serial at 9600 baud
}
 
void loop() { //Constantly runs 
if(Serial.available()){ //If serial is available
  t = Serial.read(); // Set t equal to the output of Serial
  Serial.println(t);  //Print t in serial
}
 
if(t == '1'){            //If the serial outputs 1
  digitalWrite(13,HIGH); //Write motor to high
  digitalWrite(12,LOW);//Write motor to low
  digitalWrite(11,HIGH);//Write motor to high
  digitalWrite(10,LOW);//Write motor to low
 
 //Doing so makes the car go forwards
}
 
else if(t == '2'){      //If the serial outputs 2
  digitalWrite(13,LOW); // Write all 
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
}
 
else if(t == '3'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}
 
else if(t == '4'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
 
else if(t == '5'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);
}
