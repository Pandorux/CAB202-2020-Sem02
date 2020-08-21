#include <stdio.h>
#include <stdlib.h>

//  Declare an array called rolled_vals with capacity for 64 elements
//  of the default signed integer type.
//
//  Note well:
//  *   Make sure the array is declared as a global variable, that is, outside 
//      all the functions.
//  *   Do not use the "static" keyword.
//  *   Do not assume that any initial values you place in this, or any other 
//      global variable, will be as you imagine when the roll_dice function is 
//      called. The function may be called multiple times, in which case the 
//      values of any global variable will probably change after each run.

#define TOTAL_ROLLS 64

int rolled_vals[TOTAL_ROLLS];
int const max_num = 5;
int const min_num = 1;

void roll_dice( void ) {

    //  Seed the random number generator with the value 500633.

    srand(500633);

    //  Generate 64 random values between 1 and 5 inclusive. To do 
    //  this, use a counter-controlled loop which will visit every element of 
    //  rolled_vals. The counter should start at zero, and the loop should continue 
    //  while the counter is less than 64.

    for(int i = 0; i < TOTAL_ROLLS; i++) {

        //  Generate a random value between 1 and 5 inclusive. Store this 
        //  value in the current element of rolled_vals - that is, the element 
        //  indexed by the loop counter.

        rolled_vals[i] = rand() % (max_num + 1 - min_num) + min_num;

    }

    //  End the loop.
}

int main( void ) {
    //  Fill array with distinctive data pattern to help identify bugs. If you 
    //  see the number 13283842 in your output there must a bug in your code.
    for ( int i = 0; i < 64; i++ ) {
        rolled_vals[i] = 0xCAB202;
    }

    //  Call your code.
    roll_dice();

    //  Display contents of array rolled_vals.
    for ( int i = 0; i < 64; i++ ) {
        if ( i > 0 ) {
            printf( "," );
        }
        printf( "%d", rolled_vals[i] );
    }

    printf( "\n" );

    return 0;
}
