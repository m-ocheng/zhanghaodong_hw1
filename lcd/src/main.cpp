/*
 * @Author: mochen 3230104299@zju.edu.cn
 * @Date: 2024-05-09 21:07:21
 * @LastEditors: mochen 3230104299@zju.edu.cn
 * @LastEditTime: 2024-05-09 22:42:45
 * @FilePath: \lcd\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <LiquidCrystal.h>
#include <Arduino.h>
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() {

lcd.begin(16, 2);//设置LCD要显示的列数、行数，即2行16列
}

void loop() {
lcd.setCursor(0, 1);//设置光标定位到第0列，第1行（从0开始）
lcd.print("hello, world!");//输出Hello World
}
