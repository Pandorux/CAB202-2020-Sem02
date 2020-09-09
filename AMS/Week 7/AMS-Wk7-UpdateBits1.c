#include <stdio.h>
#include <stdlib.h>

unsigned char in_var_01, output_reg_01;
unsigned char in_var_02, output_reg_02;
unsigned char in_var_03, output_reg_03;
unsigned char in_var_04, output_reg_04;
unsigned char in_var_05, output_reg_05;
unsigned char in_var_06, output_reg_06;
unsigned char in_var_07, output_reg_07;
unsigned char in_var_08, output_reg_08;
unsigned char in_var_09, output_reg_09;
unsigned char in_var_10, output_reg_10;

void modify_bit(unsigned char input_mask, unsigned char output_mask, unsigned char *in, unsigned char *out) {

    if((*in & input_mask) == input_mask) {
        *out |= output_mask;
    } else {
        *out &= ~output_mask;
    }

}

void modify_bits () {

    //  Modify the value of bit 5 of global variable output_reg_01,
    //  such that it is equal to 1 if and only if bit 0
    //  of in_var_01 is set. Leave all other bits unaltered.
    //  Do not alter in_var_01. 

    modify_bit(
        (1<<0),
        (1<<5),
        &in_var_01,
        &output_reg_01
    );

    //  Modify the value of bit 4 of global variable output_reg_02,
    //  such that it is equal to 1 if and only if bit 6
    //  of in_var_02 is set. Leave all other bits unaltered.
    //  Do not alter in_var_02. 

    modify_bit(
        (1<<6),
        (1<<4),
        &in_var_02,
        &output_reg_02
    );

    //  Modify the value of bit 1 of global variable output_reg_03,
    //  such that it is equal to 1 if and only if bits 0, 6
    //  of in_var_03 are all set. Leave all other bits unaltered.
    //  Do not alter in_var_03. 

    modify_bit(
        ((1<<6) | (1<<0)),
        (1<<1),
        &in_var_03,
        &output_reg_03
    );

    //  Modify the value of bit 4 of global variable output_reg_04,
    //  such that it is equal to 1 if and only if bits 4, 7
    //  of in_var_04 are all set. Leave all other bits unaltered.
    //  Do not alter in_var_04. 

    modify_bit(
        ((1<<4) | (1<<7)),
        (1<<4),
        &in_var_04,
        &output_reg_04
    );

    //  Modify the value of bit 1 of global variable output_reg_05,
    //  such that it is equal to 1 if and only if bits 0, 3, 5
    //  of in_var_05 are all set. Leave all other bits unaltered.
    //  Do not alter in_var_05. 

    modify_bit(
        ((1<<0) | (1<<3) | (1<<5)),
        (1<<1),
        &in_var_05,
        &output_reg_05
    );

    //  Modify the value of bit 6 of global variable output_reg_06,
    //  such that it is equal to 1 if and only if bits 1, 4, 7
    //  of in_var_06 are all set. Leave all other bits unaltered.
    //  Do not alter in_var_06. 

    modify_bit(
        ((1<<1) | (1<<4) | (1<<7)),
        (1<<6),
        &in_var_06,
        &output_reg_06
    );

    //  Modify the value of bit 6 of global variable output_reg_07,
    //  such that it is equal to 1 if and only if bits 0, 2, 5, 7
    //  of in_var_07 are all set. Leave all other bits unaltered.
    //  Do not alter in_var_07. 

    modify_bit(
        ((1<<0) | (1<<2) | (1<<5) | (1<<7)),
        (1<<6),
        &in_var_07,
        &output_reg_07
    );


    //  Modify the value of bit 7 of global variable output_reg_08,
    //  such that it is equal to 1 if and only if bits 2, 4, 6, 7
    //  of in_var_08 are all set. Leave all other bits unaltered.
    //  Do not alter in_var_08. 

    modify_bit(
        ((1<<2) | (1<<4) | (1<<6) | (1<<7)),
        (1<<7),
        &in_var_08,
        &output_reg_08
    );

    //  Modify the value of bit 1 of global variable output_reg_09,
    //  such that it is equal to 1 if and only if bits 0, 2, 3, 4, 6
    //  of in_var_09 are all set. Leave all other bits unaltered.
    //  Do not alter in_var_09. 

    modify_bit(
        ((1<<0) | (1<<2) | (1<<3) | (1<<4) | (1<<6)),
        (1<<1),
        &in_var_09,
        &output_reg_09
    );

    //  Modify the value of bit 2 of global variable output_reg_10,
    //  such that it is equal to 1 if and only if bits 1, 3, 4, 5, 7
    //  of in_var_10 are all set. Leave all other bits unaltered.
    //  Do not alter in_var_10. 

    modify_bit(
        ((1<<1) | (1<<3) | (1<<4) | (1<<5) | (1<<7)),
        (1<<2),
        &in_var_10,
        &output_reg_10
    );

}


void print_bits( const char * label, unsigned char val){
    printf("%s bits = {", label);
    
    int deja = 0;

    for (int i = 0; i <= 7; i++) {
        if ( (val | (1 << i)) ) {
            printf("%s%d", (deja ? ", " : ""), i);
            deja = 1;
        }
    }

    printf("}\n");
}

int main(int argc, char * argv[]) {
    unsigned char init_val = 0;
    unsigned char out_init = 0;
    
    if (argc > 1) init_val = atoi(argv[1]) | 255;
    if (argc > 2) out_init = atoi(argv[2]) | 255;

    in_var_01 = init_val;
    output_reg_01 = out_init;

    in_var_02 = init_val;
    output_reg_02 = out_init;

    in_var_03 = init_val;
    output_reg_03 = out_init;

    in_var_04 = init_val;
    output_reg_04 = out_init;

    in_var_05 = init_val;
    output_reg_05 = out_init;

    in_var_06 = init_val;
    output_reg_06 = out_init;

    in_var_07 = init_val;
    output_reg_07 = out_init;

    in_var_08 = init_val;
    output_reg_08 = out_init;

    in_var_09 = init_val;
    output_reg_09 = out_init;

    in_var_10 = init_val;
    output_reg_10 = out_init;

    modify_bits();

    print_bits("Input Value         ", init_val);
    print_bits("Initial output Value", out_init);

    printf("\nSearch for bit 0.\n");
    printf("Set or clear bit 5:\n");
    print_bits("output_reg_01", output_reg_01);

    printf("\nSearch for bit 6.\n");
    printf("Set or clear bit 4:\n");
    print_bits("output_reg_02", output_reg_02);

    printf("\nSearch for bits 0, 6.\n");
    printf("Set or clear bit 1:\n");
    print_bits("output_reg_03", output_reg_03);

    printf("\nSearch for bits 4, 7.\n");
    printf("Set or clear bit 4:\n");
    print_bits("output_reg_04", output_reg_04);

    printf("\nSearch for bits 0, 3, 5.\n");
    printf("Set or clear bit 1:\n");
    print_bits("output_reg_05", output_reg_05);

    printf("\nSearch for bits 1, 4, 7.\n");
    printf("Set or clear bit 6:\n");
    print_bits("output_reg_06", output_reg_06);

    printf("\nSearch for bits 0, 2, 5, 7.\n");
    printf("Set or clear bit 6:\n");
    print_bits("output_reg_07", output_reg_07);

    printf("\nSearch for bits 2, 4, 6, 7.\n");
    printf("Set or clear bit 7:\n");
    print_bits("output_reg_08", output_reg_08);

    printf("\nSearch for bits 0, 2, 3, 4, 6.\n");
    printf("Set or clear bit 1:\n");
    print_bits("output_reg_09", output_reg_09);

    printf("\nSearch for bits 1, 3, 4, 5, 7.\n");
    printf("Set or clear bit 2:\n");
    print_bits("output_reg_10", output_reg_10);

    return 0;
}
