#include <stdio.h>
#include <stdlib.h>

unsigned char reg_01;
unsigned char reg_02;
unsigned char reg_03;
unsigned char reg_04;
unsigned char reg_05;
unsigned char reg_06;
unsigned char reg_07;
unsigned char reg_08;
unsigned char reg_09;
unsigned char reg_10;

void clear_bits () {
    //  Modify the value of global variable reg_01, clearing 
    //  bit 0, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_01 &= 0b11111110;

    //  Modify the value of global variable reg_02, clearing 
    //  bit 6, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_02 &= 0b10111111;

    //  Modify the value of global variable reg_03, clearing 
    //  bits 0, 7, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_03 &= 0b01111110;

    //  Modify the value of global variable reg_04, clearing 
    //  bits 1, 6, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_04 &= 0b10111101;

    //  Modify the value of global variable reg_05, clearing 
    //  bits 0, 4, 7, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_05 &= 0b01101110;

    //  Modify the value of global variable reg_06, clearing 
    //  bits 1, 2, 3, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_06 &= 0b11110001;

    //  Modify the value of global variable reg_07, clearing 
    //  bits 0, 4, 6, 7, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_07 &= 0b00101110;

    //  Modify the value of global variable reg_08, clearing 
    //  bits 1, 5, 6, 7, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_08 &= 0b00011101;

    //  Modify the value of global variable reg_09, clearing 
    //  bits 0, 2, 3, 6, 7, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_09 &= 0b00110010;

    //  Modify the value of global variable reg_10, clearing 
    //  bits 1, 2, 3, 5, 7, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_10 &= 0b01010001;


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

    reg_01 = init_val;
    reg_02 = init_val;
    reg_03 = init_val;
    reg_04 = init_val;
    reg_05 = init_val;
    reg_06 = init_val;
    reg_07 = init_val;
    reg_08 = init_val;
    reg_09 = init_val;
    reg_10 = init_val;


    clear_bits();

    print_bits("Initial", init_val);
    print_bits("reg_01", reg_01);
    print_bits("reg_02", reg_02);
    print_bits("reg_03", reg_03);
    print_bits("reg_04", reg_04);
    print_bits("reg_05", reg_05);
    print_bits("reg_06", reg_06);
    print_bits("reg_07", reg_07);
    print_bits("reg_08", reg_08);
    print_bits("reg_09", reg_09);
    print_bits("reg_10", reg_10);


    return 0;
}
