#include <Arduino.h>

#define Z_STEP_PIN 46
#define Z_DIR_PIN 48
#define Z_ENABLE_PIN 62

void setup() {
  Serial.begin(115200);
  Serial.println("Setup OK");

  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);

  digitalWrite(Z_ENABLE_PIN, LOW);
}

void loop() {
  Serial.println("Moving Z up...");

  digitalWrite(Z_DIR_PIN, HIGH);
  for (int i = 0; i < 1600; i++) {
    digitalWrite(Z_STEP_PIN, HIGH);
    delayMicroseconds(500); 
    digitalWrite(Z_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  delay(1000);

  Serial.println("Moving Z down...");

  //digitalWrite(Z_DIR_PIN, LOW);
  //for (int i = 0; i < 1600; i++) {
  //  digitalWrite(Z_STEP_PIN, HIGH);
  //  delayMicroseconds(500);
  //  digitalWrite(Z_STEP_PIN, LOW);
  //  delayMicroseconds(500);
  //}

  delay(5000);
}
