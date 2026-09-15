// C++ code
//
int button = 2;
int readbutton = 0;
int count = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(button, INPUT);
  Serial.println("Reading Button State");
  delay(1000);
  readbutton = digitalRead(button);
  Serial.println("Starting While Loop - Checking if Button is HIGH");
  count = 0;
  delay(1000);
}

void loop()
{
  while(readbutton == 0){
    count++;
    Serial.print("Button is LOW | ");
    Serial.print("Count is ");
    Serial.println(count);
    readbutton = digitalRead(button);
    delay(100);
  }
  count++;
  Serial.print("Button is HIGH | ");
  Serial.print("Count is ");
  Serial.println(count);
  readbutton = digitalRead(button);
  delay(100);
  
  
}
