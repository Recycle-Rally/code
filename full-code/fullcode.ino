#include <Servo.h>
Servo myServo;
int state = 0;
int servoVal = 0;
const int motorPin1 = 13; // Pin 15 of L293
const int motorPin2 = 12; // Pin 10 of L293
//Right Motor Connections
const int motorPin3 = 11; // Pin 7 of L293
const int motorPin4 = 10;
void setup() 
{
  myServo.attach(12);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial Started");
}

void loop() 
{
  if (Serial.available()>0)
  { // Checks whether data is coming from the serial port
    state = Serial.read(); // Reads the data from the serial port
    Serial.println(state);
    switch (state)
    { //switch statement easily deals with multiple results
      case 'F': //Program how to respond to each case
      FWD(); break; //if you don’t program a response to
      case 'B': //a button it will be ignored
      BKWD(); break;
      case 'L':
      SpinL(); break;
      case 'R':
      SpinR(); break;
      case 'S':
      SoftSTOP(); break; 
      case 'G':
      FWDL(); break;
      case 'I':
      FWDR(); break;
      case 'H':
      BKWDL(); break;
      case 'J':
      BKWDR(); break;
      case 'V':
      hornON(); break;
      case 'v':
      hornOFF(); break;
      case 'X':
      axeON(); break;
      case 'x':
      axeOFF(); break;
    }
    delay(1);
  }
  else
  {
    delay(100);
    SoftSTOP();
  }
}
void FWD()
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}
void BKWD()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
void SoftSTOP()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}
void SpinL()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
void SpinR()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}
void FWDL()
{
  analogWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  analogWrite(motorPin3, 100);
  analogWrite(motorPin4, LOW);
}
void FWDR()
{
  analogWrite(motorPin1, LOW);
  analogWrite(motorPin2, 100);
  digitalWrite(motorPin3, HIGH);
  analogWrite(motorPin4, LOW);
}
void BKWDL()
{
  analogWrite(motorPin3, LOW);
  analogWrite(motorPin4, 100);
  digitalWrite(motorPin1, HIGH);
  analogWrite(motorPin2, LOW);
}
void BKWDR()
{
  analogWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(motorPin1, 100);
  analogWrite(motorPin2, LOW);
}
