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
  Serial.print("Button is ");
  Serial.print(val);
  Serial.println();
  Serial.print("Sensor is ");
  Serial.print(sensorValue);
  Serial.println();
  if(val == HIGH) {  // if button is pressed
    while(sensorValue > 300) {  // while light is hitting sensor
      move_servo_open();  // open the servo
    }
    if(sensorValue < 300) {
      move_servo_open_hold();
    }
  }
  else if(val == LOW) {
    move_servo_close();
  }
}

void move_servo_open() {
  myservo.write(15);
  delay(15);
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println("Servo currently opened");
  if(sensorValue < 300) {  // if sensor gets covered
    move_servo_close();  // close servo
    Serial.println("Servo closed");
  }
}

void move_servo_open_hold() {
  myservo.write(15);
  delay(15);
}

void move_servo_close() {
  myservo.write(115);
  delay(15);  
}


