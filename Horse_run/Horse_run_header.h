/*
Horse Run Header

Made for Arduino with a 16x2 LCD display.

Author: Guilherme Arruda
Created: 

Last updated:03/04/23
*/


//========================================== SPRITES ================================================

uint8_t horse_running[16][8] = {
{0b00000,0b00000,0b00000,0b00111,0b01011,0b00011,0b00001,0b00000},//Lower Left
{0b01000,0b01111,0b01011,0b11111,0b11100,0b11100,0b01000,0b10000},//Lower Right

{0b00000,0b00000,0b00000,0b00111,0b01011,0b00011,0b00001,0b00000},
{0b01000,0b01111,0b01011,0b11111,0b11100,0b11100,0b00100,0b00100},

{0b00000,0b00000,0b00000,0b00111,0b01011,0b01011,0b00001,0b00000},
{0b01000,0b01111,0b01011,0b11111,0b11100,0b11100,0b00010,0b00001},

{0b00000,0b00000,0b00000,0b00111,0b01011,0b01011,0b00010,0b00010},
{0b01000,0b01111,0b01011,0b11111,0b11100,0b11100,0b00010,0b00001},

{0b00000,0b00000,0b00000,0b01111,0b00011,0b00011,0b00100,0b01000},
{0b01000,0b01111,0b01011,0b11111,0b11100,0b11100,0b00010,0b00001},

{0b00000,0b00000,0b01000,0b00111,0b00011,0b00011,0b00100,0b01000},
{0b01000,0b01111,0b01011,0b11111,0b11100,0b11100,0b00100,0b00100},

{0b00000,0b00000,0b01000,0b00111,0b00011,0b00011,0b00100,0b01000},
{0b01000,0b01111,0b01011,0b11111,0b11100,0b11100,0b01000,0b10000},

{0b00000,0b00000,0b00000,0b01111,0b00011,0b00011,0b00010,0b00010},
{0b01000,0b01111,0b01011,0b11111,0b11100,0b11100,0b01000,0b10000}
};

uint8_t cacts[3][8] = {
{0b00000,0b00000,0b00100,0b10100,0b10101,0b11101,0b00111,0b00100},
{0b00000,0b00000,0b00000,0b00000,0b00100,0b00101,0b00111,0b00100},
{0b00000,0b00000,0b00000,0b00100,0b00110,0b00100,0b01100,0b00100}
};
//=====================================================================================================

unsigned short int colum_operator[5] = {16,24,28,30,31};

typedef struct{
    uint8_t vector[8];
    unsigned short int line;
    unsigned short int start_colum;
    unsigned short int end_colum;
}sprite;

sprite* sprite_split(sprite sprite_object){
    sprite* sp_temp = (sprite*)malloc(sizeof(sprite)*2);
    unsigned short int start_block_num, end_block_num, op_selector[2];

    start_block_num = sprite_object.start_colum;
    end_block_num = sprite_object.end_colum;

    op_selector[0] = 5*(start_block_num + 1) - sprite_object.start_colum;
    op_selector[1] = 5*(end_block_num + 1) - sprite_object.end_colum;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
            sp_temp[i].vector[j] = sprite_object.vector[j] & operator[op_selector[i]];
        }
    }

    return sp_temp;
}