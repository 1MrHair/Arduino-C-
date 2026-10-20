// C++ code
//
int P1 = A0;
int P2 = A1;

void setup()
{
  Serial.begin(9600);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
}

void loop()
{
  int P1_val = map_value(P1);
  // Serial.print("P1_val: "); Serial.println(P1_val);
  int P2_val = map_value(P2);
  // Serial.print("P2_val: "); Serial.println(P2_val);
  // Serial.println("---------------------");
  // delay(500);
  
  int motor_1 = constrain((P1_val + P2_val), -255, 255);
  int motor_2 = constrain((P1_val - P2_val), -255, 255);
  Serial.print("motor1_val: "); Serial.println(motor_1);
  Serial.print("motor2_val: "); Serial.println(motor_2);
  Serial.println("---------------------");
  delay(500);
  
  int motor_1_forward_pin;
  int motor_1_backward_pin;
  int motor_2_forward_pin;
  int motor_2_backward_pin;
  
  if(motor_1 < 0){
    motor_1 = abs(motor_1);
    Serial.println("left wheel going backward");
    motor_1_backward_pin = true
    motor_1_forward_pin = false  
  }else{
    Serial.println("left wheel going forward");
    motor_1_forward_pin = true
    motor_1_backward_pin = false
  }
  
  if(motor_2 < 0){
    motor_1 = abs(motor_1);
    Serial.println("right wheel going backward");
    motor_2_backward_pin = true
  }else{
    Serial.println("right wheel going forward");
    motor_2_forward_pin = true
  }
  
  delay(1000);
  
}

int map_value(int x){
  int x_val = analogRead(x);
  return map(x_val, 0, 1023, -255, 255);
}


