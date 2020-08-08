#include <stdio.h>
#include <string.h>

void cab_202( void ) {
    // Insert your solution here.

    for(int i = 86; i <= 3202; i++) {
        
        char str[10] = "";

        if(i % 7 == 0) {
            strcat(str, "CAB");
        } 

        if(i % 19 == 0) {
            strcat(str, "202");
        }

        if(strlen(str) > 0) {
            printf("%s\n", str);
        } else {
            printf("%i\n", i);  
        }
    }
}

int main( void ) {
	cab_202( );
	return 0;
}
