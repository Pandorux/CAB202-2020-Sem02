#include <stdio.h>

void list_integers( void ) {
    // Display the title message.

    printf("The integer sub-range from 20 to 400...\n");

    //  Enter a counter-controlled loop which will start at 20 and
    //  continues up to and including 400, advancing by increments of 1. 

    for(int i = 20; i <= 400; i++) {

        //  Print the current value of the counter variable.
        printf("%i\n", i);
    }          

    // End the loop.
}

int main( void ) {
	list_integers( );
	return 0;
}
