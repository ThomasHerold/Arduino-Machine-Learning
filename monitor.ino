#include <Servo.h>

void setup()
{
  Serial.begin(9600);
  
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  
}

void loop()
{
  delay(4000);
  int left, right;
  left = analogRead(A3);
  right = analogRead(A4);
  
  Serial.print("bp.Train(");
  Serial.print(right);
  Serial.print(",");
  Serial.print(left);
  Serial.println(");");
}
