#include "Horse_run_header.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

line_buffer lcd_buffer[2];
 

void setup()
{
  lcd.begin(16, 2);
  
}
 
void loop()
{ 
  for(unsigned short int i = 0; i < 2; i++){
    for(unsigned short int j = 0; j < 2; j++){
      buffer_add(&lcd_buffer[u], horse_running_sprite[i][])
    }
  }
}
