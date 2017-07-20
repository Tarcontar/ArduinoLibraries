//Sunfounder I2C display
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  

void setup() {
  // put your setup code here, to run once:
  lcd.init();   

   for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  

  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("HI!YourDuino.com");
  delay(1000);  

// Wait and then tell user they can start the Serial Monitor and type in characters to
// Display. (Set Serial Monitor option to "No Line Ending")
  lcd.clear();
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("Use Serial Monitor");
  lcd.setCursor(0,1);
  lcd.print("Type to display");  

  lcd.setCursor(0,2);
  lcd.print("TAG: ");  
}

int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print(char(255));
  lcd.setCursor(0,1);
  lcd.print("HI!YourDuino.com");
  delay(500);
  lcd.clear();
}
