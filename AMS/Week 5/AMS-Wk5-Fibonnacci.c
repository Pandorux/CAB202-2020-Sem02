#include <stdio.h>
#include <stdlib.h>

//  Here: Declare a global array called seq with capacity to hold 31 elements
//  of the default signed integer type.

int seq[31];

void compute_fib( void ) {

    //  Here: Insert code to populate the array with a generalised Fibonacci 
    //  sequence here.

    scanf(" %d %d", &seq[0], &seq[1]);

    for(int i = 2; i < 31; i++) {
        seq[i] = seq[i-1] + seq[i-2];
    }
}

int main(void) {
    //  Fill array with distinctive data pattern to help identify bugs. If you 
    //  see the number 13283842 in your output there must a bug in your code.
    for ( int i = 0; i < 31; i++ ) {
        seq[i] = 0xCAB202;
    }

    //  Run your code.
    compute_fib();

    //  Display contents of array seq.
    for (int i = 0; i < 31; i++) {
        printf("%d\n", seq[i]);
    }

    return 0;
}
