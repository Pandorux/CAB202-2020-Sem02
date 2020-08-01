#include <stdio.h>
#include <math.h>

void vol_cyl(void) {
    
	// (a) Declare local variable to hold input value.
    double radius;
    double height;
    double volume;

	// (b) Prompt user to enter value.
    printf("What is the radius of the cylinder?\n");

	// (c) Read input value.
    scanf("%lf", &radius);

    // (d) Prompt user to enter value.
    printf("What is the height of the cylinder?\n");

	// (e) Read input value.
    scanf("%lf", &height);

	// (f) Compute output value.
    volume = M_PI * (radius * radius) * height;

	// (g) Display the result.
    printf("A radius of %lf and a height of %lf correspond to a volume of %lf.\n", radius, height, volume);
}

int main(void) {
	vol_cyl();
	return 0;
}
