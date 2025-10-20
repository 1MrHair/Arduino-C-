#include <Servo.h> // Import Servo Library
// create servo object to control a servo
// my_servo can be any name. 
// Twelve servo objects can be on most Arduino boards
Servo my_servo;
int pos = 0; // variable to store the servo position
float degree = 0; // degree variable
int counter = 0; // counter
int slide_pin = A0;
int button_pin = 7;

void setup() {
  Serial.begin(9600);
  my_servo.attach(9); // Servo on pin 9 to servo object 
  pos = 0; // Set position Variable
  my_servo.write(pos); // Set the default start position
  delay(1000); // Delay just a bit to get into position
  pinMode(button_pin, INPUT_PULLUP);
}

void loop() {
  int button = digitalRead(button_pin);
  int slide = analogRead(slide_pin);
  Serial.println(slide);
  Serial.println(degree);
  if(button == 0){
    degree = (slide/180.0)*32.4;
  }
  if(degree < 180){
    my_servo.write(degree);
  }else{
    my_servo.write(180);
  }
}
