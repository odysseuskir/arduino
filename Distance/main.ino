int echoPin = 12; // Echo Pin
int trigPin = 13; // Trigger Pin
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);

}

void loop() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration/58.2; //Υπολογισμός απόστασης (σε cm) βασιζόμενοι στην ταχύτητα του ήχου.

    if (distance >= maximumRange || distance <= minimumRange){
        Serial.println("Εκτός ορίων");
        delay(100);
    } else {
        Serial.println(distance);
        delay(50);
    };

    delay(50); //Καθυστέρηση 50ms πριν την επόμενη ανάγνωση

}