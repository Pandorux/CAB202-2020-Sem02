#include <stdio.h>

void cel2far(void) {

    // (a) Declare local variable to hold input value.
    double input;
    double converted;
    
	// (b) Prompt user to enter value.
	printf("What is the temperature in Celsius degrees?\n");
    
    // (c) Read input value.
    scanf("%lf", &input);

	// (d) Compute output value.
    converted = (input * 1.8) + 32;

	// (e) Display the result.
    printf("A temperature of %0.5f degrees Celsius is equal to %0.5f degrees Fahrenheit.\n", input, converted);
}

int main(void) {
	cel2far();
	return 0;
}