#include <stdio.h>

void sunny(void) {

    char input;

    printf("How does the humidity feel?\n1 - high\n2 - normal\n");
    scanf(" %c", &input);

    if(input == '1') {
        printf("It is just too hot and sticky for tennis.\n");
    }
    else if(input == '2') {
        printf("This is a good day for tennis.\n");
    }
    else {
        printf("Invalid choice for humidity: '%c'\nValid options are '1', and '2'.\n", input);
    }

}

void overcast(void) {

    char input;

    printf("What is the wind level?\n1 - windy\n2 - calm\n");
    scanf(" %c", &input);

    if(input == '1') {
        printf("It is just too wild and windy for tennis.\n");
    }
    else if(input == '2') {
        printf("This is a good day for tennis.\n");
    }
    else {
        printf("Invalid choice for wind: '%c'\nValid options are '1', and '2'.\n", input);
    }

}

void tennis_dialog( void ) {
    // Insert your solution here

    char input;

    printf("How does the weather look?\n1 - sunny\n2 - overcast\n3 - rainy\n");
    scanf(" %c", &input);

    if(input == '1') {
        sunny();
    }
    else if(input == '2') {
        printf("This is a good day for tennis.\n");
    }
    else if(input == '3') {
        overcast();
    }
    else {
        printf("Invalid choice for outlook: '%c'\nValid options are '1', '2', and '3'.\n", input);
    }
}



int main(void) {
	tennis_dialog();
	return 0;
}
