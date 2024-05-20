/*
 * @Author: mochen 3230104299@zju.edu.cn
 * @Date: 2024-05-05 22:06:21
 * @LastEditors: mochen 3230104299@zju.edu.cn
 * @LastEditTime: 2024-05-09 18:19:28
 * @FilePath: \light\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <Arduino.h>

void setup()
{
  for (int i = 2; i < 8; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  for (int i = 2; i < 8; i++)
  {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
  for (int i = 7; i > 2; i--)
  {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
}