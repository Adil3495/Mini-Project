#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
int D3,D2,D1,D0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Receiving...");
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  delay(500);
}

void loop() {
  lcd.display();
  lcd.setCursor(0,1);

  D3=digitalRead(2);
  D2=digitalRead(3);
  D1=digitalRead(10);
  D0=digitalRead(11);

  //0000
  if((D3==LOW)&&(D2==LOW)&&(D1==LOW)&&(D0==LOW))
  {
    lcd.print("");
  }
  //0001
  if((D3==LOW)&&(D2==LOW)&&(D1==LOW)&&(D0==HIGH))
  {
    lcd.print("1");
  }
  //0010
  if((D3==LOW)&&(D2==LOW)&&(D1==HIGH)&&(D0==LOW))
  {
    lcd.print("2");
  }
  //0011
  if((D3==LOW)&&(D2==LOW)&&(D1==HIGH)&&(D0==HIGH))
  {
    lcd.print("3");
  }
  //0100
  if((D3==LOW)&&(D2==HIGH)&&(D1==LOW)&&(D0==LOW))
  {
    lcd.print("4");
  }
  //0101
  if((D3==LOW)&&(D2==HIGH)&&(D1==LOW)&&(D0==HIGH))
  {
    lcd.print("5");
  }
  //0110
  if((D3==LOW)&&(D2==HIGH)&&(D1==HIGH)&&(D0==LOW))
  {
    lcd.print("6");
  }
  //0111
  if((D3==LOW)&&(D2==HIGH)&&(D1==HIGH)&&(D0==HIGH))
  {
    lcd.print("7");
  }
  //1000
  if((D3==HIGH)&&(D2==LOW)&&(D1==LOW)&&(D0==LOW))
  {
    lcd.print("8");
  }
  //1001
  if((D3==HIGH)&&(D2==LOW)&&(D1==LOW)&&(D0==HIGH))
  {
    lcd.print("9");
  }
  //1010
  if((D3==HIGH)&&(D2==LOW)&&(D1==HIGH)&&(D0==LOW))
  {
    lcd.print("A");
  }
  //1011
  if((D3==HIGH)&&(D2==LOW)&&(D1==HIGH)&&(D0==HIGH))
  {
    lcd.print("B");
  }
  //1100
  if((D3==HIGH)&&(D2==HIGH)&&(D1==LOW)&&(D0==LOW))
  {
    lcd.print("C");
  }
  //1101
  if((D3==HIGH)&&(D2==HIGH)&&(D1==LOW)&&(D0==HIGH))
  {
    lcd.print("D");
  }
  //1110
  if((D3==HIGH)&&(D2==HIGH)&&(D1==HIGH)&&(D0==LOW))
  {
    lcd.print("E");
  }
  //1111
  if((D3==HIGH)&&(D2==HIGH)&&(D1==HIGH)&&(D0==HIGH))
  {
    lcd.print("F");
  } 
}
