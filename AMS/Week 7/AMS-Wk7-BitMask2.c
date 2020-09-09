#include <stdio.h>
#include <stdlib.h>

unsigned char var_01;
unsigned char var_02;
unsigned char var_03;
unsigned char var_04;
unsigned char var_05;
unsigned char var_06;
unsigned char var_07;
unsigned char var_08;
unsigned char var_09;
unsigned char var_10;

void set_vars () {

    // 0
    var_01 = 0b00000001;

    // 4
    var_02 = 0b00010000;

    // 0, 7
    var_03 = 0b10000000 | var_01;

    // 4, 7
    var_04 = 0b00010001 ^ var_03;

    // 0, 4, 5
    var_05 = 0b00100000 | var_01 | var_02;

    // 2, 5, 7
    var_06 = 0b10100100;

    // 0, 1, 4, 7
    var_07 = 0b00000010 | var_02 | var_03;

    // 1, 3, 4, 7
    var_08 = 0b00001001 ^ var_07;

    // 0, 2, 4, 5, 7
    var_09 = var_05 | var_06;

    // 1, 2, 3, 6, 7
    var_10 = 0b11001110;

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

    var_01 = init_val;
    var_02 = init_val;
    var_03 = init_val;
    var_04 = init_val;
    var_05 = init_val;
    var_06 = init_val;
    var_07 = init_val;
    var_08 = init_val;
    var_09 = init_val;
    var_10 = init_val;


    set_vars();

    print_bits("Initial", init_val);
    print_bits("var_01", var_01);
    print_bits("var_02", var_02);
    print_bits("var_03", var_03);
    print_bits("var_04", var_04);
    print_bits("var_05", var_05);
    print_bits("var_06", var_06);
    print_bits("var_07", var_07);
    print_bits("var_08", var_08);
    print_bits("var_09", var_09);
    print_bits("var_10", var_10);


    return 0;
}
