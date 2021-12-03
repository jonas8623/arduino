const int pinLed = 3;
const int piezoPin = A0;
int ledOn = 120;
int sensorValue = 0;
int ledValue = 0; // Porta PWM de 0 até 255

void setup() {
  pinMode(pinLed, OUTPUT);

  Serial.begin(9600);
  // Pisca o LED duas vezes, para mostrar que o programa iniciou
  initLed();
  initLed();
}

void loop() {
  piezo();
}

void initLed()
{
  digitalWrite(pinLed, HIGH);
  delay(1000);
  digitalWrite(pinLed, LOW);
}

void piezo()
{
  sensorValue = analogRead(piezoPin);
  Serial.println(sensorValue);
  delay(1000);
  if (sensorValue >= ledOn) {
    ledValue = 255; //Brilho máximo do led
  }
  analogWrite(pinLed, int(ledValue));
  turnOffLed();
}

void turnOffLed()
{
  ledValue = ledValue - 5.50;
  if(ledValue <= 0) {
    ledValue = 0;
  }
}
