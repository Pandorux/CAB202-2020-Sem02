#include <stdio.h>

//  Declare Global variables here.

double term[30];
int term_count;
double term_mean;
double term_min;
double term_max;

void arraystats() {

    //  Insert your solution here.

    term_count = 0;

    while(term_count < 30 && scanf(" %lf", &term[term_count]) == 1) {
        term_count++;
    }

    // No input means no calculation
    if(term_count == 0) {
        term_mean = 0;
        term_min = 0;
        term_max = 0;

        return;
    }

    term_min = term[0];
    term_max = term[0];
    double term_sum = 0;

    for(int i = 0; i < term_count; i++) {
        term_sum += term[i];
        term_min = term[i] < term_min ? term[i] : term_min;
        term_max = term[i] > term_max ? term[i] : term_max;
    }

    term_mean = term_sum / term_count;
}

#include <stdlib.h>
#include <time.h>

int main() {
    // AMS will do something a bit like this before it calls your solution.
    // Do not change any of this; instead, write your solution in such a way 
    //  that it works correctly even with this.
    srand( time( NULL ) );

    for ( int i = 0; i < 30; i++ ) {
        double randVal = ((double) rand()) / RAND_MAX; 
        term[i] = randVal;

        if (randVal != term[i]) {
            printf( "Incorrect numeric type appears to be in use.\n" );
            return 1;
        }
    }
    
    term_count = rand();
    term_mean = ((double) rand()) / RAND_MAX;
    term_min = ((double) rand()) / RAND_MAX;
    term_max = ((double) rand()) / RAND_MAX;

    // Call submitted code.
    arraystats();

    // Display contents of array term.
    for (int i = 0; i < term_count; i++) {
        printf("%f ", term[i]);
    }

    printf("\n");
    printf("Item count: %d\n", term_count);
    printf("Item mean : %f\n", term_mean);
    printf("Item min  : %f\n", term_min);
    printf("Item max  : %f\n", term_max);

    return 0;
}
