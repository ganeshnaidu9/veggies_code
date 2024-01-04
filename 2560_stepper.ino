const int stepPin = 32;
const int dirPin = 34;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  digitalWrite(dirPin, HIGH);  // Set HIGH for clockwise rotation

  // Rotate the motor for one full rotation with 6 stops
  for (int i = 0; i < 200 * 6; i++) {  // 200 steps for a full revolution, 6 rotations
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);

    // Check if it's time for a stop
    if (i % 33 == 0 && i > 0) {  // 33 steps per stop (adjust as needed)
      // Pause for 1 second at each stop
      delay(1000);
    }
  }

  // Reverse direction (CCW) to return to the initial position
  digitalWrite(dirPin, LOW);

  // Rotate the motor back to the initial position
  for (int i = 0; i < 200*6 ; i++) {  // 200 steps for a full revolution, 6 rotations
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }

  // Add any additional functionality or delays as needed
}