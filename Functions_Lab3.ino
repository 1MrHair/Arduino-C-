const int LED1 = 13;

void blinkLED(); // LED blink
void hello(); // Says "Hello!"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
}

void loop()
{
  blinkLED1();
  hello();
}

void blinkLED1(){
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
}

void hello(){
  Serial.println("Hello!");
}
