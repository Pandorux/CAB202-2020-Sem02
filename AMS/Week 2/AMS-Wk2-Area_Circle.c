#include <stdio.h>
#include <math.h>

void area_circ(void) {

    // (a) Declare local variable to hold input value.
    double radius;
    double area;

	// (b) Prompt user to enter value.
    printf("What is the radius of the circle?\n");

	// (c) Read input value.
    scanf("%lf", &radius);

	// (d) Compute output value.
    area = M_PI * (radius * radius);

	// (e) Display the result.
    printf("A radius of %lf corresponds to an area of %lf.\n", radius, area);
}

int main(void) {
	area_circ();
	return 0;
}
