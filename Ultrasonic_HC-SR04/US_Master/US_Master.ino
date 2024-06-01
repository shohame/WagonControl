// Define pins
const int buttonPin = 2;    // Button pin
const int vccPin = 8;     // Ultrasonic sensor vcc pin
const int trigPin = 9;      // Ultrasonic sensor trigger pin
const int echoPin = 10;     // Ultrasonic sensor echo pin
const int gndPin = 11;     // Ultrasonic sensor gnd pin
const long timeout = 100000000;
// Variables
long duration;
int distance;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);       // Initialize serial communication
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
  pinMode(vccPin, OUTPUT);  digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT);  digitalWrite(gndPin, LOW);
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT);  // Set echo pin as input
  Serial.print("Done setup: ");

}

void loop() {
  delay(1000);
  // Check if the button is pressed
  //if (digitalRead(buttonPin) == LOW) {
  //  buttonPressed = true;
  //}

  // If button is pressed, measure distance
  if (1) {
    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echo time
    duration = pulseIn(echoPin, HIGH); //, timeout);

    // Calculate the distance
    distance = duration * 0.034 / 2;

    // Print the distance to the serial monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    buttonPressed = false; // Reset the button press flag
  }
}