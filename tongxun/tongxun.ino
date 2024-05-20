void setup() 
{
  Serial.begin(9600);
}
const String correctPassword[] = {"AA", "BB", "CC", "DD"};
int currentIndex = 0;
void loop()
{
  if (Serial.available()) 
  {
    String input = Serial.readStringUntil('\n');
    if (input == correctPassword[currentIndex]) 
    {
      currentIndex++;
      if (currentIndex == (sizeof(correctPassword) / sizeof(correctPassword[0]))) 
      {
        Serial.println("密码正确");
        currentIndex = 0;
      }
    } 
    else 
    {
      Serial.println("密码错误");
      currentIndex = 0;
    }
  }
}