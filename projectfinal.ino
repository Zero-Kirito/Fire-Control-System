#include <LiquidCrystal.h>
#include <dht.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //lcd digital pins
int greenPin = A0; //dht data pin
dht sensor;

void setup()
{
  lcd.begin(16,2); //16 by 2 character display
  pinMode(6, OUTPUT); //Relay
  pinMode(7, OUTPUT); //Buzzer and RED LED (mark this line if u don't want to use buzzer and LED)
  //pinMode(8, OUTPUT); //GREEN LED(Unmark the previous comment if u want Green LED)
}
 
void loop()
{
  delay(1000); //wait a sec (recommended for DHT11)
  sensor.read11(greenPin);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity = ");
  lcd.print(sensor.humidity);
  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  lcd.print(sensor.temperature);
  if(sensor.temperature > 40 && sensor.humidity < 60) //change 40 into threshold Temperature Degree(Celcius)
   //Change 60 into required Threshold Humidity (Percentage)
  {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    //digitalWrite(8, LOW);   //uncheck previous comment if u want green led
    delay(500);
  }
  else
  {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    //digitalWrite(8, HIGH); //uncheck previous comment if u want green led
    delay(500);
  }
}
