#include <Servo.h>

Servo servo;
int servoAngles[] = {0, 100};

#define positionX A0
#define positionY A1
int xAxis;
int yAxis;

void setup() {
  servo.attach(3);
  Serial.begin(9600);
}

void serial(String text)
{
  Serial.println(text);
}

void checkServo(int value)
{
  servo.write(value);
}

void tRex()
{
   xAxis = analogRead(positionX);
   yAxis = analogRead(positionY);
   
   if(xAxis >= 500 && xAxis <=535 && yAxis >= 490 && yAxis <= 499 ) {
     checkServo(servoAngles[0]);
     serial("Meio");
   } else if(xAxis >= 170 && xAxis <= 1023 && yAxis >= 490 && yAxis <= 730 ) {
       checkServo(servoAngles[1]);
       serial("PULA");
     }
   delay(200);
}

void loop()
{
  tRex();
}
