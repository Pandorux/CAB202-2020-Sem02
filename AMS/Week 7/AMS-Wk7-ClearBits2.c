#include <stdio.h>
#include <stdlib.h>

unsigned char Var_01;
unsigned char Var_02;
unsigned char Var_03;
unsigned char Var_04;
unsigned char Var_05;
unsigned char Var_06;
unsigned char Var_07;
unsigned char Var_08;
unsigned char Var_09;
unsigned char Var_10;

void zero_bits () {

    // 0
    Var_01 &= 0b11111110;

    // 3
    Var_02 &= 0b11110111;

    // 0, 7
    Var_03 &= 0b01111110;

    // 1, 2
    Var_04 &= 0b11111001;

    // 0, 1, 5
    Var_05 &= 0b11011100;

    // 1, 3, 4
    Var_06 &= 0b11100101;

    // 0, 2, 3, 6
    Var_07 &= 0b10110010;

    // 3, 4, 5, 7
    Var_08 &= 0b01000111;

    // 0, 1, 4, 6, 7
    Var_09 &= 0b00101100;

    // 2, 3, 4, 5, 6
    Var_10 &= 0b10000011;


}


void print_bits( const char * label, unsigned char val){
    printf("%s bits = {", label);
    
    int deja = 0;

    for (int i = 0; i <= 7; i++) {
        if ( (val & (1 << i)) ) {
            printf("%s%d", (deja ? ", " : ""), i);
            deja = 1;
        }
    }

    printf("}\n");
}

int main(int argc, char * argv[]) {
    unsigned char init_val = 0;
    
    if (argc > 1) init_val = atoi(argv[1]) & 255;

    Var_01 = init_val;
    Var_02 = init_val;
    Var_03 = init_val;
    Var_04 = init_val;
    Var_05 = init_val;
    Var_06 = init_val;
    Var_07 = init_val;
    Var_08 = init_val;
    Var_09 = init_val;
    Var_10 = init_val;


    zero_bits();

    print_bits("Initial", init_val);
    print_bits("Var_01", Var_01);
    print_bits("Var_02", Var_02);
    print_bits("Var_03", Var_03);
    print_bits("Var_04", Var_04);
    print_bits("Var_05", Var_05);
    print_bits("Var_06", Var_06);
    print_bits("Var_07", Var_07);
    print_bits("Var_08", Var_08);
    print_bits("Var_09", Var_09);
    print_bits("Var_10", Var_10);


    return 0;
}
