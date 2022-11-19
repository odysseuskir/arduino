int echoPin = 12;
int trigPin = 13;
int alarmPin = 11;
int maximumRange = 500;
int minimumRange = 0;
int alarmRange = 20;
float duration, distance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alarmPin, OUTPUT);
  pinMode(3, OUTPUT); // Red
  pinMode(5, OUTPUT); // Green
  pinMode(7, OUTPUT); // Blue
  Serial.begin(9600);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;

  if (distance >= maximumRange || distance <= minimumRange){ // If the distance is out of range
    Serial.println("Out of range");
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
    Serial.println(distance,2);
  }

  if(distance <= alarmRange) { // If the distance is under the alarm range
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
 
  if(distance > minimumRange && distance <= maximumRange){ // If the distance is in range
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }
 
  delay(500);
}