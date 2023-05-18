
#include <Servo.h>
#include <AFMotor.h>
#define Echo A0 // Replace Echo with A0 when started
#define Trig A1 // Replace Trig with A1 when started
#define motor 10 // Replace motor with 10 when started
#define Speed 170 // Replace Speed with 170 when started
#define spoint 103 // Replace spoint with 103 when started
char value; // Define value to a single characted
int distance; // Define distance to a number
int Left; // Define Left to a number
int Right; // Define Right to a number
int L = 0; // Define L to a number, 0
int R = 0; // Define R to a number, 0
int L1 = 0; // Define L1 to a number, 0
int R1 = 0; // Define R1 to a number, 0
Servo servo; // Create servo 
AF_DCMotor M1(1); // Set M1 to channel 1
AF_DCMotor M2(2); // Set M2 to channel 2
AF_DCMotor M3(3); // Set M3 to channel 3
AF_DCMotor M4(4); // Set M4 to channel 4
void setup() {
  Serial.begin(9600); // Begin Serial
  pinMode(Trig, OUTPUT); // Set Trig to output
  pinMode(Echo, INPUT); // Set Echo to input
  servo.attach(motor); // Attach motor to the servo
  M1.setSpeed(Speed); // Set M1 to Speed
  M2.setSpeed(Speed); // Set M2 to Speed
  M3.setSpeed(Speed); // Set M3 to Speed
  M4.setSpeed(Speed); // Set M4 to Speed
}
void loop() {
  Obstacle(); // Obstacle Avoidance
  //Bluetoothcontrol(); // Bluetooth Control
  //voicecontrol(); // Voice Control
}
void Bluetoothcontrol() {
  if (Serial.available() > 0) { 
    value = Serial.read();
    Serial.println(value);
  }
  if (value == 'F') {
    forward();
  } else if (value == 'B') {
    backward();
  } else if (value == 'L') {
    left();
  } else if (value == 'R') {
    right();
  } else if (value == 'S') {
    Stop();
  }
}
void Obstacle() {
  distance = ultrasonic();
  if (distance <= 12) {
    Stop();
    backward();
    delay(100);
    Stop();
    L = leftsee();
    servo.write(spoint);
    delay(800);
    R = rightsee();
    servo.write(spoint);
    if (L < R) {
      right();
      delay(500);
      Stop();
      delay(200);
    } else if (L > R) {
      left();
      delay(500);
      Stop();
      delay(200);
    }
  } else {
    forward();
  }
}
void voicecontrol() {
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);
    if (value == '^') {
      forward();
    } else if (value == '-') {
      backward();
    } else if (value == '<') {
      L = leftsee();
      servo.write(spoint);
      if (L >= 10 ) {
        left();
        delay(500);
        Stop();
      } else if (L < 10) {
        Stop();
      }
    } else if (value == '>') {
      R = rightsee();
      servo.write(spoint);
      if (R >= 10 ) {
        right();
        delay(500);
        Stop();
      } else if (R < 10) {
        Stop();
      }
    } else if (value == '*') {
      Stop();
    }
  }
}
// Ultrasonic sensor distance reading function
int ultrasonic() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  long t = pulseIn(Echo, HIGH);
  long cm = t / 29 / 2; //time convert distance
  return cm;
}
void forward() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}
void backward() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}
void right() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}
void left() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}
void Stop() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}
int rightsee() {
  servo.write(20);
  delay(800);
  Left = ultrasonic();
  return Left;
}
int leftsee() {
  servo.write(180);
  delay(800);
  Right = ultrasonic();
  return Right;
}
