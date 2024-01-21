#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);

float dht_temp()
{
  float temperature = 24.0 + float(float(random(100)))/100; 
  return temperature;
}

float dht_humid()
{
  float humidity = 9.0 + float(float(random(100)))/10; 
  return humidity;
}

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  float humidity = dht_humid();       
  float temperature = dht_temp();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(60000); 

}
