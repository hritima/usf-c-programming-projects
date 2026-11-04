/*
 * Project2.c: ASCII Stream Transformer Project
 *Name: Hritima Thapa Magar
 *NetID: hritima
 *Program Description: Reads characters one at a time by using getchar(), classifies them based on
 *                     ASCII value and converts them
 *
 */

#include <stdio.h>

int main(void){

	int c;			/* Holds the character from getchar() */
	int converted;		  /* Holds the converted character */
	int isTerminated;	/*Flag if the user enters '@' and set to 1 */
	int firstPrompt;	/*Flag: 1 until the first prompt has been printed */

	isTerminated = 0;
	firstPrompt = 1;


	/*
	 * Outer loop: keeps prompting and read a full line of input until the user enters the
	 * sentinel charcater '@'.
         */
	
	do{
		if (!firstPrompt){
			printf("\n");
		}
		firstPrompt = 0;

 		printf("Enter 1 or more characters then ENTER:\n");
		printf("(NOTE: a character @ will exit the program):\n");
		
	        /*
        	 * Inner loop: reads and processes characters one at a time until it encounters 
        	 * '@'or '\n'
        	 */

		while ((c = getchar()) != '\n' && c != '@'){
                	printf("\n");
		        /* Print the character with ASCII code */
			printf("You typed: '%c' (ASCII %d)\n", c, c);
		
			/* Classify and convert the character */
			if (c >= 65 && c <= 90){

				printf("Class: Uppercase Letter\n");
				converted = c + 32; /* convert to lowercase */
				printf("Converted to: '%c'\n", converted);

			} else if (c >= 97 && c <= 122){

                                printf("Class: Lowercase Letter\n");
                                converted = c -	32;	/* convert to uppercase */
                                printf("Converted to: '%c'\n", converted);

                       } else if (c >= 48 && c <= 57){

                                printf("Class: Digit\n");
                                converted = 48 + (57 - c); /* convert to its 9's complement */
                                printf("Converted to: '%c'\n", converted);

                        } else if (c >=32 && c <= 126){
				/* classify as symbol if the character is printable but a not a,
				   letter or digit */
				
                                printf("Class: Printable Symbol\n");
                                printf("No conversion done\n");

                        } else {
				/* Anything outside 32-126 range is non-printable */
                                printf("Class: Non-printable or extended ASCII\n");
	                        printf("No conversion done\n");
			}
		}
		

		/* If the inner loop stopped incase because of @, flag the program to end */
		if (c == '@'){
			isTerminated = 1;
		}
	} while (!isTerminated);

	return 0;
}

