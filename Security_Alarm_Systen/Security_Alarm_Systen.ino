/* 
   The code below is for a security door system...
   Using an ultrasonic sensor to set the secruity procedure by a 
   distance. Going to set a specific or fixed distance which is the distance from the 
   sensor to the door if this distance is by 2cm, when the systme has been activated 
   treat this as blugar or thief... 
  
 */

// Declaring the components pins 
const int TrigPin = 6;
const int EchoPin = 7;
const int BuzzerPin = 3;
const int ButtonPin = 4;

// Declaring or setting the threshold of the ultrasonic sensor
const int DistanceThreshold = 50;   // In centimeter

// Variables for the distance and duration
float distance_cm, duration_us;


void setup() {
  Serial.begin(9600);   // Initialze serial Port
  pinMode(TrigPin, OUTPUT);   // Setting the trig_pin of the US
  pinMode(EchoPin, INPUT);    // Setting the echo_pin of the US
  pinMode(BuzzerPin, OUTPUT); // Setting the buzzer pin

}

void loop() {
  // setting the button state of the button pin
  int ButtonState = digitalRead(ButtonPin);
  
  // generate 10-microsecond pulse to Trig Pin
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  // measuring the duration of pulse from Echo Pin
  duration_us = pulseIn(EchoPin, HIGH);

  // calculating the distance
  distance_cm = 0.017 * duration_us;

  if (distance_cm < DistanceThreshold){
    digitalWrite(BuzzerPin, HIGH);
    
    // perform whien the button is pressed or not
    if (ButtonState == HIGH){
      digitalWrite(BuzzerPin, LOW);
      }
    else {
      digitalWrite(BuzzerPin, HIGH);
      }
    }

   else {
    digitalWrite(BuzzerPin, LOW);
    }

  // printing the distance value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm ");

  delay(500);

}
