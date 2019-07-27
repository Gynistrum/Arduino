int testLED = 10; // LED D4 in MF Shield

void setup() 
{
  // Nothing to do here
}

void loop() 
{
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) 
  {
    analogWrite(testLED, fadeValue);
    delay(30);
  }

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) 
  {
    analogWrite(testLED, fadeValue);
    delay(30);
  }
}
