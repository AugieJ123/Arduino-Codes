const int buttonPin = 8;
const int ledPin = 7;
const int buzzerPin = 10;

void setup(){
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop(){
    int buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH){
        Serial.println("The button is pressed...");
        digitalWrite(ledPin, HIGH);
        BuzzerTone(200,1000);
        delayMicroseconds(20);
    }
    else if (buttonState == LOW){
        Serial.println("The button is unpressed...");
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);
        delay(100);
    }
}

void BuzzerTone(int time1, int time2){
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(time1);   
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(time2);
  }
