const int TRIG_PIN   = 7;
const int ECHO_PIN   = 6;
const int BUZZER_PIN = 13;
const int DISTANCE_THRESHOLD = 50;

float duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

 if (distance < DISTANCE_THRESHOLD)
    digitalWrite(BUZZER_PIN, HIGH); // or tone(BUZZER_PIN, 1000) for passive buzzer
else
    digitalWrite(BUZZER_PIN, LOW);  // or noTone(BUZZER_PIN)


  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
