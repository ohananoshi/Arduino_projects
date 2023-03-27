//Programa: Teste de Display LCD 16 x 2
//Autor: MakerHero
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

#define FR 1
#define FF 2
#define FT 3
#define BR 4
#define BT 5 
#define BF 6

#define DELAY 100

uint8_t dino_f_1[8] = 
{
0b00000100,
0b00000100,
0b00000111,
0b00000111,
0b00011111,
0b00011010,
0b00011110,
0b00000010,
};
uint8_t dino_f_2[8] = 
{
0b00010000,
0b00011000,
0b00001111,
0b00000111,
0b00011111,
0b00011010,
0b00011110,
0b00000010,
};
uint8_t dino_f_3[8] = 
{
0b00000001,
0b00000010,
0b00000111,
0b00000111,
0b00011111,
0b00011010,
0b00011110,
0b00000010,
};
uint8_t dino_b_1[8] = 
{
0b00001000,
0b00001000,
0b00111010,
0b00111010,
0b00111100,
0b11100000,
0b11000000,
0b11100000
};

uint8_t dino_b_2[8] = 
{
0b00000010,
0b00000100,
0b00111010,
0b00111010,
0b00111100,
0b11100000,
0b11000000,
0b11100000
};
uint8_t dino_b_3[8] = 
{
0b00100000,
0b00010000,
0b00111010,
0b00111010,
0b00111100,
0b11100000,
0b11000000,
0b11100000
};
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  lcd.createChar(1,dino_f_1);
  lcd.createChar(2,dino_f_2);
  lcd.createChar(3,dino_f_3);
  lcd.createChar(4,dino_b_1);
  lcd.createChar(5,dino_b_2);
  lcd.createChar(6,dino_b_3);
}
 
void loop()
{
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 1, linha 0;
  
  lcd.setCursor(13, 1);
  lcd.print("1");

  lcd.setCursor(14, 1);
  lcd.write((byte)FT);
  lcd.write((byte)BF);
  delay(DELAY);

  lcd.setCursor(13, 1);
  lcd.print("2");
  
  lcd.setCursor(14, 1);
  lcd.write((byte)FR);
  delay(DELAY);

  lcd.setCursor(13, 1);
  lcd.print("3");
  
  lcd.setCursor(14, 1);
  lcd.write((byte)FF);
  lcd.write((byte)BF);  
  delay(DELAY);

  lcd.setCursor(13, 1);
  lcd.print("4");

  lcd.setCursor(15, 1);
  lcd.write((byte)BR);
  delay(DELAY);
  
  lcd.setCursor(13, 1);
  lcd.print("5");
  
  lcd.setCursor(15, 1);
  lcd.write((byte)BT);
  delay(DELAY);

  lcd.setCursor(13, 1);
  lcd.print("6");

  lcd.setCursor(14, 1);
  lcd.write((byte)FR);
  delay(DELAY);

  lcd.setCursor(13, 1);
  lcd.print("7");

  lcd.setCursor(14, 1);
  lcd.write((byte)FT);
  delay(DELAY);

  lcd.setCursor(13, 1);
  lcd.print("8");
  
  lcd.setCursor(15, 1);
  lcd.write((byte)BR);
  delay(DELAY);
  
}
