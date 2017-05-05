//Motor vars
int pwm = 6;  // Power for motor
int ina = 5;
int inb = 4;

// Button vars
int buttonin = 9;  // Turns to HIGH when button pressed
int val = 0;     // variable for reading the button
int buttonvcc = 8;  // Connects HIGH to button

void setup() {
  //Motor setup
  Serial.begin(9600);
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(pwm, OUTPUT);
  digitalWrite(ina, LOW); 
  digitalWrite(inb, HIGH);

  //Button setup
  pinMode(buttonin, INPUT);
  pinMode(buttonvcc, OUTPUT);
  digitalWrite(buttonvcc, HIGH);
}

void loop() {
  val = digitalRead(buttonin);   // Reads the button if pressed
  if (val == HIGH) {         // If button is pressed
    digitalWrite(pwm, HIGH);  // Turn on the motor
  } else {
    digitalWrite(pwm, LOW);
  }
  
}


