#include <stdio.h>
#include <ctype.h>

//  HERE: Declare a global array of char called input with capacity to hold 128 elements.
//  AMS will insert data into this array prior to calling your function.

char input[128];

//  HERE: Declare a global array of int called input_count with capacity to hold 3 elements.
//  AMS will read results from this array after calling your function.
//  The contents of this array will be overwritten by AMS before calling your
//  function, so you should not make any assumptions about it.

int input_count[3];

void string_char_count() {

    //  Assign all elements of input_count to zero.

    input_count[0] = 0;
    input_count[1] = 0;
    input_count[2] = 0;

    //  Traverse input with a counted loop which visits each valid char in
    //  succession, stopping when it reaches the end of the string. 

    for(int i = 0; i < 128; i++) {

        if(input[i] == '\0') {
            break;
        }

        //  Get current character from input and convert it to lower case.
        //  If the current character is between 'x' and 'z' inclusive, increment 
        //  the element of input_count which corresponds to the character. 
        //  Otherwise, ignore the current character.

        char cur = tolower(input[i]);

        switch (cur)
        {
            case 'x':
                input_count[0]++;
                break;

            case 'y':
                input_count[1]++;
                break;

            case 'z':
                input_count[2]++;
                break;
            
            default:
                break;
        }

    }


    //  End loop
}

#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // AMS will do something a bit like this before it calls your solution.
    // Do not change any of this; instead, write your solution in such a way 
    //  that it works correctly even with this.
    srand( time( NULL ) );

    for ( int i = 0; i < 3; i++ ) {
        input_count[i] = rand();
    }

    //  Read as much data from stdin as we can, and append each char to the
    //  buffer.
    int chars_read = 0;

    for (chars_read = 0; chars_read < (128-1); chars_read ++) {
        int scanf_result = scanf( "%c", &input[chars_read] );
        
        if ( 1 != scanf_result ) break;
    }

    //  Terminate the string in the buffer.
    input[chars_read] = 0;

    // Pad remainder of string with garbage to help with debugging.
    for ( int i = chars_read + 1; i < (128); i++ ) {
        input[i] = 'x' + rand() % (1 + 'z' - 'x');
    }

    // Call submitted code.
    string_char_count();

    // Display contents of string, and number of occurrences of each symbol.
    printf("Input string        = '%s'\n", input);
    printf("Input string length = %zu\n", strlen(input));
    printf("Array capacity      = %d\n", 128);
    printf("Symbol frequencies:\n");
    
    for ( int i = 0; i < 3; i++ ) {
        printf("%c\t%d\n", 'x'+i, input_count[i]);
    }

    return 0;
}
