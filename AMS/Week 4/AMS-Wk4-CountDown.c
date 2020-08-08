#include <stdio.h>

void count_down( void ) {
    //  Insert your solution here

    int i = 3857;
    while(i >= 100) {
        printf("%i\n", i);
        i -= 4;
    }
}

int main( void ) {
	count_down( );
	return 0;
}
