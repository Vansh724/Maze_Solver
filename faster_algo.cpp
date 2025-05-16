#define in1 10    //Left Motors
#define in2 9    
#define in3 5    //Right Motors
#define in4 3   

#define s1 12     // Left Sensor
#define s2 7      // Middle Sensor
#define s3 2      // Right Sensor

int speed = 65;

void setup ()
{
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  
  Serial.begin(9600);
}

void Forward()
{
  analogWrite(in1,speed);
  analogWrite(in2,0);
  analogWrite(in3,speed);
  analogWrite(in4,0);
}

void Right()
{
  analogWrite(in1,speed);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,speed);
}

void Left()
{
  analogWrite(in1,0);
  analogWrite(in2,speed);
  analogWrite(in3,speed);
  analogWrite(in4,0);
}


void Stop()
{
  analogWrite(in1,0);
  analogWrite(in4,0);
  analogWrite(in3,0);
  analogWrite(in2,0);
}

void loop ()
{
  int   IR1 = digitalRead(s1);
  int   IR2 = digitalRead(s2);
  int   IR3 = digitalRead(s3);

  // Serial.print("Reading of sensor1 is : ");
  // Serial.println(IR1);
  // Serial.print("Reading of sensor2 is : ");
  // Serial.println(IR2);
  // Serial.print("Reading of sensor3 is : ");
  // Serial.println(IR3);

  // ONE SENSOR AT A TIME
  if (IR1 == LOW && IR2 == HIGH && IR3 == LOW)// STRAIGHT LINE
   {
      Forward();
      delay(100);
   }
  else if (IR1 == HIGH && IR2 == LOW && IR3 == LOW) // LEFT TURN
    {
      Left();
      delay(50);
    }
  else if (IR1 == LOW && IR2 == LOW && IR3 == HIGH) // RIGHT TURN
    {
      Right();
      delay(30);
    }
  // COMBINATION OF SENSORS
  else if (IR1 == HIGH && IR2 == HIGH && IR3 == LOW)// T-INTERSECTION LEFT
    {
      Left();// As Left is possible
      delay(50);
      Forward();
      delay(20);
    }

    else if (IR1 == LOW && IR2 == HIGH && IR3 == HIGH) // T-INTERSECTION RIGHT 
   { 
    Forward();
    delay(20);
   }

  else if (IR1 == HIGH && IR2 == LOW && IR3 == HIGH)// MIDDLE DEVIATED
    {
      Left();
      delay(20);
    }

  else if (IR1 == HIGH && IR2 == HIGH && IR3 == HIGH)// T-JUNCTION
    {
      Left();
      delay(50);
Forward();
delay(10);
    }

  else if (IR1 == LOW && IR2 ==LOW && IR3 == LOW)// DEAD END
   {  Forward();
      delay(20);
      Left(); //As no other direction is possible
      delay(30);
   }
}