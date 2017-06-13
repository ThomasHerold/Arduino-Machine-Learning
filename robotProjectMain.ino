#include <Servo.h>                           // Include servo library
#include <math.h> 
Servo servoLeft;                             // Declare left and right servos
Servo servoRight;
float m_fWeights[3][4] ={ {0.901439,0.0129561,-1.45102,-1.86228},
{-0.147415,-0.315726,-1.25608,-2.36521},
{0.787929,0.232099,-1.57518,1.48217}

};	



void setup()                                 // Built-in initialization block
{
  Serial.begin(9600);
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);  
                                              // Attach right signal to pin 12
}  
 
void loop()                                  // Main loop auto-repeats
{    
  delay(100);
  int left, right;
  float out1, out2;
  
  left = analogRead(A3);
  right = analogRead(A4);
  
  Run(left, right, out2, out1);
  
  out1 *= 100;
  out2 *= 100;

  Serial.println(left);
  Serial.println(right);  
  out1 = map(out1,0,5, 1450,1500);
  out2 = map(out2,0,5, 1550,1500);
  
  

  Serial.println(out1);
  Serial.println(out2);
  servoLeft.writeMicroseconds(out1);         // Left wheel clockwise
  servoRight.writeMicroseconds(out2);        // Right wheel clockwise

}

float Sigmoid(float num) {
	return (float)(1 / (1 + exp(-num)));
}

void Run(float i1, float i2, float& out1, float& out2) 
{
	// Train function for neural network

	float net1, net2, i3, i4;

	net1 = 1 * m_fWeights[0][0] + i1 * m_fWeights[1][0] +
		i2 * m_fWeights[2][0];
	net2 = 1 * m_fWeights[0][1] + i1 * m_fWeights[1][1] +
		i2 * m_fWeights[2][1];

	i3 = Sigmoid(net1);
	i4 = Sigmoid(net2);

	net1 = 1 * m_fWeights[0][2] + i3 * m_fWeights[1][2] +
		i4 * m_fWeights[2][2];

	net2 = 1 * m_fWeights[0][3] + i3 * m_fWeights[1][3] +
		i4 * m_fWeights[2][3];
	
	out1 = Sigmoid(net1);
	out2 = Sigmoid(net2);


}


