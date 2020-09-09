#include <stdio.h>
#include <stdlib.h>

unsigned char Reg_01;
unsigned char Reg_02;
unsigned char Reg_03;
unsigned char Reg_04;
unsigned char Reg_05;
unsigned char Reg_06;
unsigned char Reg_07;
unsigned char Reg_08;
unsigned char Reg_09;
unsigned char Reg_10;

void modify_bits () {

    // 0
    Reg_01 |= 0b00000001;

    // 3
    Reg_02 |= 0b00001000;

    // 0, 7
    Reg_03 |= 0b10000001;

    // 6, 7
    Reg_04 |= 0b11000000;

    // 0, 3, 5
    Reg_05 |= 0b00101001;

    // 3, 6, 7
    Reg_06 |= 0b11001000;

    // 0, 3, 5, 6
    Reg_07 |= 0b01101001;

    // 1, 3, 4, 5
    Reg_08 |= 0b00111010;

    // 0, 1, 3, 6, 7
    Reg_09 |= 0b11001011;

    // 1, 2, 4, 5, 7
    Reg_10 |= 0b10110110;

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

    Reg_01 = init_val;
    Reg_02 = init_val;
    Reg_03 = init_val;
    Reg_04 = init_val;
    Reg_05 = init_val;
    Reg_06 = init_val;
    Reg_07 = init_val;
    Reg_08 = init_val;
    Reg_09 = init_val;
    Reg_10 = init_val;


    modify_bits();

    print_bits("Initial", init_val);
    print_bits("Reg_01", Reg_01);
    print_bits("Reg_02", Reg_02);
    print_bits("Reg_03", Reg_03);
    print_bits("Reg_04", Reg_04);
    print_bits("Reg_05", Reg_05);
    print_bits("Reg_06", Reg_06);
    print_bits("Reg_07", Reg_07);
    print_bits("Reg_08", Reg_08);
    print_bits("Reg_09", Reg_09);
    print_bits("Reg_10", Reg_10);


    return 0;
}
