#include <stdio.h>
#include <stdlib.h>

unsigned char input_var_01, output_var_01;
unsigned char input_var_02, output_var_02;
unsigned char input_var_03, output_var_03;
unsigned char input_var_04, output_var_04;
unsigned char input_var_05, output_var_05;
unsigned char input_var_06, output_var_06;
unsigned char input_var_07, output_var_07;
unsigned char input_var_08, output_var_08;
unsigned char input_var_09, output_var_09;
unsigned char input_var_10, output_var_10;

void modify_bit(unsigned char input_mask, unsigned char output_mask, unsigned char *in, unsigned char *out) {

    if((*in & input_mask) == input_mask) {
        *out |= output_mask;
    } else {
        *out &= ~output_mask;
    }

}

void update_bits () {

    modify_bit(
        (1<<0),
        (1<<1),
        &input_var_01,
        &output_var_01
    );

    modify_bit(
        (1<<2),
        (1<<0),
        &input_var_02,
        &output_var_02
    );

    modify_bit(
        ((1<<0) | (1<<2)),
        (1<<1),
        &input_var_03,
        &output_var_03
    );

    modify_bit(
        ((1<<5) | (1<<7)),
        (1<<2),
        &input_var_04,
        &output_var_04
    );

    modify_bit(
        ((1<<0) | (1<<2) | (1<<5)),
        (1<<1),
        &input_var_05,
        &output_var_05
    );

    modify_bit(
        ((1<<1) | (1<<2) | (1<<5)),
        (1<<0),
        &input_var_06,
        &output_var_06
    );

    modify_bit(
        ((1<<0) | (1<<1) | (1<<5) | (1<<6)),
        (1<<0),
        &input_var_07,
        &output_var_07
    );

    modify_bit(
        ((1<<1) | (1<<3) | (1<<4) | (1<<6)),
        (1<<2),
        &input_var_08,
        &output_var_08
    );

    modify_bit(
        ((1<<0) | (1<<2) | (1<<3) | (1<<4) | (1<<7)),
        (1<<4),
        &input_var_09,
        &output_var_09
    );

    modify_bit(
        ((1<<1) | (1<<3) | (1<<5) | (1<<6) | (1<<7)),
        (1<<3),
        &input_var_10,
        &output_var_10
    );

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
    unsigned char out_init = 0;
    
    if (argc > 1) init_val = atoi(argv[1]) & 255;
    if (argc > 2) out_init = atoi(argv[2]) & 255;

    input_var_01 = init_val;
    output_var_01 = out_init;

    input_var_02 = init_val;
    output_var_02 = out_init;

    input_var_03 = init_val;
    output_var_03 = out_init;

    input_var_04 = init_val;
    output_var_04 = out_init;

    input_var_05 = init_val;
    output_var_05 = out_init;

    input_var_06 = init_val;
    output_var_06 = out_init;

    input_var_07 = init_val;
    output_var_07 = out_init;

    input_var_08 = init_val;
    output_var_08 = out_init;

    input_var_09 = init_val;
    output_var_09 = out_init;

    input_var_10 = init_val;
    output_var_10 = out_init;

    update_bits();

    print_bits("Input Value         ", init_val);
    print_bits("Initial output Value", out_init);

    printf("\nSearch for bit 0.\n");
    printf("Set or clear bit 1:\n");
    print_bits("output_var_01", output_var_01);

    printf("\nSearch for bit 2.\n");
    printf("Set or clear bit 0:\n");
    print_bits("output_var_02", output_var_02);

    printf("\nSearch for bits 0, 2.\n");
    printf("Set or clear bit 1:\n");
    print_bits("output_var_03", output_var_03);

    printf("\nSearch for bits 5, 7.\n");
    printf("Set or clear bit 2:\n");
    print_bits("output_var_04", output_var_04);

    printf("\nSearch for bits 0, 2, 5.\n");
    printf("Set or clear bit 1:\n");
    print_bits("output_var_05", output_var_05);

    printf("\nSearch for bits 1, 2, 5.\n");
    printf("Set or clear bit 0:\n");
    print_bits("output_var_06", output_var_06);

    printf("\nSearch for bits 0, 1, 5, 6.\n");
    printf("Set or clear bit 0:\n");
    print_bits("output_var_07", output_var_07);

    printf("\nSearch for bits 1, 3, 4, 6.\n");
    printf("Set or clear bit 2:\n");
    print_bits("output_var_08", output_var_08);

    printf("\nSearch for bits 0, 2, 3, 4, 7.\n");
    printf("Set or clear bit 4:\n");
    print_bits("output_var_09", output_var_09);

    printf("\nSearch for bits 1, 3, 5, 6, 7.\n");
    printf("Set or clear bit 3:\n");
    print_bits("output_var_10", output_var_10);

    return 0;
}
