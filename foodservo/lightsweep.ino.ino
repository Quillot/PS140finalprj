#include <Servo.h>
//Servo vars
Servo myservo;
int pos = 0;    // stores servo position 

//Light vars
int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int vcc1 = 2;


// Button vars
int buttonin = 9;  // Turns to HIGH when button pressed
int val = 0;     // variable for reading the button
int buttonvcc = 8;  // Connects HIGH to button

void setup() {
  //Light detector setup
  Serial.begin(9600); //sets serial port for communication
  pinMode(vcc1,OUTPUT); 
  digitalWrite(vcc1,HIGH);

  //Button setup
  pinMode(buttonin, INPUT);
  pinMode(buttonvcc, OUTPUT);
  digitalWrite(buttonvcc, HIGH);

  //Servo setup
  myservo.attach(3);  // attaches the servo to pin 3
}

void loop() {

  //Servo code
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  //Button code
  val = digitalRead(buttonin);
  if(sensorValue < 300) {  //if light is being detected, move servo to open
    move_servo_back();
    Serial.println(1);
  }
  else if(val == HIGH) {
    move_servo_back();
    Serial.println(10);   
  } else {
    move_servo();
  }
}

void move_servo_back() {
  myservo.write(15);
  delay(15);
}

void move_servo() {
  myservo.write(115);
  delay(15);  
}


