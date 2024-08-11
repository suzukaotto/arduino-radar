#include <Servo.h>

#define DELAY_TIME 20
#define SERVO_PIN 2
#define ECHO_PIN 3
#define TRIG_PIN 4

Servo myServo;

int getDistance() {
  long duration, distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH); 
  distance = duration * 17 / 1000; 

  return distance;
}

void printStatus(int dist, int angl) {
  Serial.print(angl);
  Serial.print(",");
  Serial.print(dist);
  Serial.print(".");
}

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  myServo.write(90);
  delay(200);
}

void loop() {
  for (int i=0; i<=180; i++) {
    myServo.write(i);
    delay(DELAY_TIME);
    printStatus(getDistance(), i);
  }
  for (int i=180; i>=0; i--) {
    myServo.write(i);
    delay(DELAY_TIME);
    printStatus(getDistance(), i);
  }
}
