#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void word_count() {

    int charCount = 0;
    int lineCount = 0;
    int wordCount = 0;

    char cur = ' ';
    char prev;

    while(TRUE) {

        // 1. Get New Char
        prev = cur;
        int return_scanf = scanf("%c", &cur);

        // 2. End Program if EOF
        if(return_scanf == EOF) {
            break;
        }

        // 3. Determine if a new word has started
        if(isspace(prev) && !isspace(cur)) {
            wordCount++;
        } 

        // 4. If not a new word, check if it is a new line 
        else if(cur == '\n') {
            lineCount++;
        }

        charCount++;
    }

    printf("The document contains %i lines, %i words, and %i characters.\n", lineCount, wordCount, charCount);
}


int main() {
	word_count();
	return 0;
}
