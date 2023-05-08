const int trigPin = 9;    // Trigger pin of the Ultrasonic Sensor
const int echoPin = 10;   // Echo pin of the Ultrasonic Sensor

void setup() {
  Serial.begin(9600);     // Initialize serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);      // Set trigger pin to low
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);     // Set trigger pin to high
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);      // Set trigger pin to low

  duration = pulseIn(echoPin, HIGH);    // Read the echo pin, returns the sound wave travel time in microseconds
  distance = duration / 58;             // Convert the travel time to distance in cm

  if (distance <= 10) {
    // If object detected within 5 cm, send message to serial port
    Serial.println("Object detected at 5 cm");
  } else {
    Serial.println("No object detected");
  }
  delay(1000);
}
