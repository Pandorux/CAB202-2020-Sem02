#include <stdio.h>



void flag_multiples( void ) {

    //  Enter a counter controlled loop which starts at 86 and
    //  advances by increments of 1 up to and including 3202

        for(int i = 86; i <= 3202; i++) {

            //  Send the current value of the counter to standard output as a 
            //  decimal formatted integer.
            
            printf("%i", i);

            //  If the current value of the counter is divisible by 7 then 
            //  highlight the current line by sending the pattern " <===" to 
            //  standard output.
            if(i % 7 == 0) {
                printf(" <===");
            } 

            //  Send a linefeed to standard output.
            printf("\n");  
        }

    //  End loop.
}

int main( void ) {
	flag_multiples( );
	return 0;
}
