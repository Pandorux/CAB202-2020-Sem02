#include <stdio.h>

void far2cel(void) {

    // (a) Declare local variable to hold input value.
    double input;
    double converted;
    
	// (b) Prompt user to enter value.
	printf("What is the temperature in Fahrenheit degrees?\n");
    
    // (c) Read input value.
    scanf("%lf", &input);

	// (d) Compute output value.
    converted = (input -32.0) * 5.0 / 9.0;

	// (e) Display the result.
    printf("A temperature of %0.5f degrees Fahrenheit is equal to %0.5f degrees Celsius.\n", input, converted);
}

int main(void) {
	far2cel();
	return 0;
}