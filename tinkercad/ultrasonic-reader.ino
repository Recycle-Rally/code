int inches = 0; //Declare the inches variable

int cm = 0; //Declare the cm variable

long readUltrasonicDistance(int triggerPin, int echoPin) //Create a 
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW); // Set the trigger pin to low
  delayMicroseconds(2); // Delay for 2 microseconds
  digitalWrite(triggerPin, HIGH); //Set the trigger pin to high
  delayMicroseconds(10); // Delay for 10 microseconds
  digitalWrite(triggerPin, LOW); // Set the trigger pin to low
  pinMode(echoPin, INPUT); // Set the echoPin to input
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH); // Waits until the pin gets a high signal then writes the distance
}

void setup()
{
  Serial.begin(9600); // Begin the serial monitor
}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches); // Print inches variable
  Serial.print("in, "); // Print "in, "
  Serial.print(cm); // Print cm variable
  Serial.println("cm"); // Print "cm"
  delay(100); // Wait for 100 millisecond(s)
}
