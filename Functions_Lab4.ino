const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
void blinkLED(); // LED blink

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop(){
  int delay = 0;
  delay = 100;
  blinkLED(LED1, delay);
  delay = 200;
  blinkLED(LED2, delay);
  delay = 300;
  blinkLED(LED3, delay);
  delay = 400;
  blinkLED(LED4, delay);
}

void blinkLED(int pin, int ms){
  print_delay(ms);
  digitalWrite(pin, HIGH);
  delay(ms);
  digitalWrite(pin, LOW);
  delay(ms);
}

void print_delay(int time){
  Serial.print("delay: ");
  Serial.println(time);
}
