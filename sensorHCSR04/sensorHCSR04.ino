#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(2,3);

float distanceCM;
float distanceMeter;

void setup() {
  Serial.begin(9600);
}

void serial(float value, String unitOfMeasurement)
{
  Serial.print("Distance: ");
  Serial.print(value);
  Serial.println(unitOfMeasurement);
}

void serial2(String text)
{
  Serial.println(text);
}

void breakTime()
{
  delay(2000);
}

void measureDistance()
{
  distanceCM = distanceSensor.measureDistanceCm();
  distanceMeter = distanceCM / 100;
  serial(distanceCM, " cm");
  serial(distanceMeter, " M");
}

void alertDistance()
{
  if (distanceCM <= 50 && distanceMeter <= 0.50) {
    serial2("Perto");
  } else {
      serial2("Longe");
    }
  breakTime(2000);
}

void loop() {
  measureDistance();
  alertDistance();
  breakTime();
}
