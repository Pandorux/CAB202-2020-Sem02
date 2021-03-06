#include <stdio.h>

void echo_char() {

    char input; 

    //  Prompt the user to enter a single character. 
    //
    //  Use the text "Please enter a char value:" followed by a single
    //  colon, and nothing else (either visible or invisible).
    //  The message should appear on a line by itself.
    //
    //  Hint: printf.

    printf("Please enter a char value:\n");

    //  Fetch a character code from standard input.
    //
    //  Hint: scanf(" %c", &some_var_of_type_char) will skip spaces and get the 
    //        first non-space character.
    //
    //        scanf("%c", &some_var_of_type_char) i.e. without the leading space 
    //        symbol in the format string, will fetch any character, including
    //        space, tab, form-feed, or line-feed symbols.
    //
    //        AMS will use the first form, to skip over spaces and newlines. 

    scanf(" %c", &input);

    //  Send the character entered by the user to the standard output 
    //  stream. Your message should take the form "You supplied the character 'X'. Thank you.",
    //  where X is replaced by the character read earlier. The message should 
    //  be followed by a single linefeed symbol, and nothing else (either 
    //  visible or invisible).
    //
    //  Hint: printf, %c.

    printf("You supplied the character '%c'. Thank you.\n", input);

    //  Send the character entered by the user to the standard output 
    //  stream, along with its character code. Your message should take the 
    //  form "Now you know that 'X' has code number Y.", where X is replaced by the 
    //  character read earlier, and Y is replaced by the integer value of the 
    //  character. The message should be followed by a single linefeed symbol, 
    //  and nothing else (either visible or invisible).
    //  
    //  Hint: printf, %c, %d.

    printf("Now you know that '%c' has code number %d.\n", input, input);
}


int main() {
	echo_char();
	return 0;
}
