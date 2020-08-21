#include <stdio.h>
#include <ctype.h>

//  HERE: Declare a global array of char called item with capacity to hold 
//  124 elements. AMS will insert data into this array prior to calling your function.

char item[124];

//  HERE: Declare a global array of int called val_count with capacity to hold 
//  one element for each symbol in the designated character range.
//  AMS will read results from this array after calling your function.
//  The contents of this array will be overwritten by AMS before calling your
//  function, so you should not make any assumptions about it.

#define ASCHII_a 97
#define ASCHII_z 122

int val_count[26];

void string_char_count_2() {

    //  Assign all elements of input_count to zero.

    for(int i = 0; i < 26; i++) {
        val_count[i] = 0;
    }

    //  Traverse input with a counted loop which visits each valid char in
    //  succession, stopping when it reaches the end of the string. 

    for(int i = 0; i < 124; i++) {

        if(item[i] == '\0') {
            break;
        }

        //  If the current character is between 'z' and 'z' inclusive, increment 
        //  the element of input_count which corresponds to the character. 
        //  Otherwise, ignore the current character.

        int index = (item[i] - ASCHII_z + 26) - 1;

        if(index > -1 && index < 26) {
            val_count[index]++;
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

    #define CHAR_SET_SIZE (1 + 'z' - 'a')

    for ( int i = 0; i < CHAR_SET_SIZE; i++ ) {
        val_count[i] = rand();
    }

    //  Read as much data from stdin as we can, and append each char to the
    //  buffer.
    int chars_read = 0;

    for ( chars_read = 0; chars_read < (124 - 1); chars_read++ ) {
        int scanf_result = scanf( "%c", &item[chars_read] );

        if ( 1 != scanf_result ) break;
    }

    //  Terminate the string in the buffer.
    item[chars_read] = 0;

    // Pad remainder of string with garbage to help with debugging.
    for ( int i = chars_read + 1; i < (124); i++ ) {
        item[i] = 'a' + rand() % CHAR_SET_SIZE;
    }

    // Call submitted code.
    string_char_count_2();

    // Display contents of string, and number of occurrences of each symbol.
    printf( "Input string        = '%s'\n", item );
    printf( "Input string length = %zu\n", strlen( item ) );
    printf( "Array capacity      = %d\n", 124 );
    printf( "Symbol frequencies:\n" );

    for ( int i = 0; i < CHAR_SET_SIZE; i++ ) {
        printf( "%c\t%d\n", 'a' + i, val_count[i] );
    }

    return 0;
}
