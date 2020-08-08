#include <stdio.h>

#define TRUE 1
#define FALSE 0

void count_chars() {

    //  Declare an integer variable which will be used to count characters.
    //  Initialise the variable to zero.

    int charCount = 0;

    //  Enter a loop which continues indefinitely.

    while(TRUE) {

        // Try to read a single character code from standard input.

        char c;
        int scanf_return = scanf("%c", &c);

        // If you have reached end of input, break out of the loop.

        if(scanf_return == EOF) {
            break;
        }

        // Increment the counter by 1.

        charCount++;
    }

    // End the body of the loop.

    // Display the number of characters processed.

    printf("The document contains %i characters.\n", charCount);
}


int main() {
	count_chars();
	return 0;
}
