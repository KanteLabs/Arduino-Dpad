int analogpin = 3; // analog pin to read the buttons

void setup()
{
  Serial.begin(9600);
}

void loop()
{ 
  Serial.println( analogRead(analogpin));
}
