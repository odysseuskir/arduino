int echoPin = 12; // Echo Pin of the ultrasonic board
int trigPin = 13; // Trigger Pin of the ultrasonic board
int alarmPin = 5; // Buzzer
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
int alarmRange=10; // The distance at which the alarm will sound
float duration, distance;

void setup() {

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(alarmPin, OUTPUT);
    Serial.begin(9600);

}

void loop() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration/58.2; // Calculate distance (in cm) based on the speed of sound.

    if (distance >= maximumRange || distance <= minimumRange){
        Serial.println("Εκτός ορίων");
        delay(100);
    } else {
        Serial.println(distance,2);
    };

    if(distance<alarmRange) {
    digitalWrite(5,HIGH); // Turn on buzzer
    } else {
    digitalWrite(5,LOW); // Turn off buzzer
    }

    delay(50); // 50ms delay before next reading

}