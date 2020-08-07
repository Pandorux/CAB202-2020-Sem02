#include <stdio.h>

void is_leap( void ) {
    
    int year;

    printf("What year shall I process?\n");
    scanf(" %i", &year);
    
    if(year % 4 == 0
        && (!(year % 100 == 0) || year % 400 == 0)) {
        printf("The year you asked about (%i) is a leap year.\n", year);
    }
    else {
        printf("The year you asked about (%i) is not a leap year.\n", year);
    }

}


int main() {
	is_leap();
	return 0;
}
