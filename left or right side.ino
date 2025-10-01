/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial
  by Dejan Nedelkovski,
  www.HowToMechatronics.com
*/

// defines pins numbers
const int trigPin1 = 11;
const int echoPin1 = 12;
const int trigPin2 = 6;
const int echoPin2 = 7;
bool object_Detected = false;
bool object_Detected2 = false;
bool object_Left_Side = false;
bool object_Right_Side = false;
int object_Amount = 0;
// defines variables
long duration;
int distance;
int distance1;
int distance2;

void setup() {
  // UltraSonoc Pins
  pinMode(trigPin1, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT);   // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);  // Starts the serial communication
}

void loop() {
  distance1 = distance_Value(trigPin1, echoPin1);
  distance2 = distance_Value(trigPin2, echoPin2);
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance1);

  // --------------------------------------------------------
  // ADD Your Code Here - Detect a specific distance... like distance > 5 cm

  if (distance1 <= 10) {
    Serial.println("Object Detected!");
    object_Detected = true;
    object_Left_Side = true;
  } else if (distance1 > 10 && object_Detected == true) {
    object_Detected = false;
    Serial.println("Object Gone!");
    Serial.print("Amount of Objects: ");
    Serial.println(object_Amount);
    object_Amount++;
    object_Left_Side = false;
  }

  if (distance2 <= 10) {
    Serial.println("Object Detected!");
    object_Detected2 = true;
    object_Right_Side = true;
  } else if (distance2 > 10 && object_Detected2 == true) {
    object_Detected2 = false;
    object_Right_Side = false;
  }

  if (object_Left_Side == true && object_Right_Side == false) {
    Serial.println("Object came in from Left Side!");
  } else if (object_Left_Side == false && object_Right_Side == true) {
    Serial.println("Object came in from Right Side!");
  }
  // --------------------------------------------------------
}
int distance_Value(int trigPin, int echoPin) {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}
