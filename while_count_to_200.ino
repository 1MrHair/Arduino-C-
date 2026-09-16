// C++ code
//
int count = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while(count < 200){
    count++;
    Serial.println(count);
    delay(50);
  }
  Serial.println("No more numbers :c");
  delay(100);
}
