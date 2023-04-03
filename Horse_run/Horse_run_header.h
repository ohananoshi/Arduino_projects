/*
Horse Run Header

Made for Arduino with a 16x2 LCD display.

Author: Guilherme Arruda
Created: 23/03/23

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

uint8_t piter[2][8] = {
{0b00000,0b00000,0b00000,0b10000,0b01110,0b11111,0b00000,0b00000},
{0b00000,0b00000,0b00000,0b00000,0b01100,0b01011,0b11111,0b00110}
};
//=====================================================================================================

unsigned short int colum_operator[5] = {16,24,28,30,31};

typedef struct{
    uint8_t vector[8];
    unsigned short int line;
    unsigned short int start_colum;
    unsigned short int end_colum;
    unsigned short int block;
}sprite;

sprite sprite_merge(sprite sprite_1, sprite sprite_2){
    sprite merged_sprite;

    for(int i = 0; i < 8; i++){
        merged_sprite.vector[i] = sprite_1.vector[i] | sprite_2.vector[i];
    }
    return merged_sprite;
}


sprite** sprite_split(sprite* line_buffer){
    sprite* new_buffer = (sprite*)calloc(16,sizeof(sprite));
    unsigned short int block_ref[2], op_selector[2];

    for(int i = 0; i < 16; i++){
        new_buffer[i] = (sprite*)realloc(new_buffer[i], 2*sizeof(sprite*));

        block_ref[0] = line_buffer[i]->start_colum/5;
        block_ref[1] = line_buffer[i]->end_colum/5;

        if(block_ref[0] == block_ref[1]) continue;
        if(line_buffer[i]->line == 3) continue;

        op_selector[0] = 5*(start_block_num + 1) - line_buffer[i]->start_colum;
        op_selector[1] = 5*(end_block_num + 1) - line_buffer[i]->end_colum;

        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 8; k++){
                new_buffer[i][j]->vector[k] = line_buffer[i]->vector[k] & colum_operator[op_selector[j]];
                new_buffer[i][j]->block = block_ref[j];
            }
        }
    }

    return new_buffer;
}

sprite* line_buffer_update(sprite** splited_buffer){
    sprite* updated_buffer = (sprite*)calloc(15, sizeof(sprite));

    for(int i = 0; i < 15; i++){
        updated_buffer[i]->vector = sprite_merge(splited_buffer[i][1], splited_buffer[i+1][0]);
    }


    return updated_buffer;
}

void refresh(unsigned short int line, sprite* line_buffer){
    int a;
    lcd.setCursor(0,line);

    for(int i = 0; i < 15; i++){
        a = 0;
        lcd.createChar(a, line_buffer[i]->vector);
        lcd.write(a);
    }
}