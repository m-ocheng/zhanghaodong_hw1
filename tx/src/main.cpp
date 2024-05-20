/*
 * @Author: mochen 3230104299@zju.edu.cn
 * @Date: 2024-05-09 22:59:21
 * @LastEditors: mochen 3230104299@zju.edu.cn
 * @LastEditTime: 2024-05-09 23:45:36
 * @FilePath: \tx\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
# include <Arduino.h>
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