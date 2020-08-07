#include <stdio.h>

void point_3d( void ) {
    // Insert your solution here.

    double x;
    double y;
    double z;

    printf("Please provide values for X and Y:\n");
    scanf(" %lf %lf", &x, &y);

    if (x >= 0 && y >= 0) {
        z = (x * 2.26451) + (y * 7.42923);
    }
    else if (x >= 0 && y <= 0) {
        z = (x * 2.26451) + (y * y);
    }
    else if (x <= 0 && y >= 0) {
        z = (x * x) + (y * 7.42923);
    }
    else {
         z = (x * x) + (y * y);
    }

    printf("(%0.5lf, %0.5lf) -> %0.5lf.\n", x, y, z);
}


int main() {
	point_3d();
	return 0;
}
