/*
Written by:  John Rogers
designed for the teensy 4.0 and TR40-16T transducers
*/

const int carrierPin = 6;  // PWM output pin
const int potPin = A0;     // Analog pin for potentiometer input
const int analogRange = 1023; // Analog range (10-bit ADC)

void setup() {
  pinMode(carrierPin, OUTPUT); // Set the carrier pin as an output
  analogWriteFrequency(carrierPin, 40000); // Set the carrier frequency to 40 kHz
}

void loop() {
  // Read the potentiometer value
  int potValue = analogRead(potPin);

  // Map the potentiometer value to the modulation frequency range (5 kHz to 18 kHz)
  float modulationFrequency = map(potValue, 0, analogRange, 5000, 18000);

  // Calculate the modulation duty cycle
  float modulationDutyCycle = modulationFrequency / 40000.0; // 40 kHz carrier

  // Modulate the carrier PWM signal
  analogWrite(carrierPin, int(modulationDutyCycle * 255));

  // Delay for stability (you can adjust this as needed)
  delay(10);
}
