#include <LiquidCrystal.h>
#include <Arduino.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int contrast = 2;
void setup() {
pinMode(contrast,OUTPUT);
analogWrite(contrast,13);
lcd.begin(16, 2);//设置LCD要显示的列数、行数，即2行16列
}

void loop() {
lcd.setCursor(0, 1);//设置光标定位到第0列，第1行（从0开始）
lcd.print("Hello World");//输出Hello World
}