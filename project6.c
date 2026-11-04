/*
 *project6.c
 *
 *name: Hritima Thapa Magar
 *netid: hritima
 *program description: Reads a text file and splits it into multiple smaller text files
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE_FILENAME 64
#define READ_CHUNK_SIZE 128

#define EXIT_USAGE 1
#define EXIT_BAD_SIZE 2
#define EXIT_INPUT_ERROR 3
#define EXIT_OUTPUT_ERROR 4


/* Function declaration */
int is_positive_integer(const char *str, long *value);
FILE *open_chunk(int chunk_number, FILE *input);

int main(int argc, char *argv[])
{
	long max_lines;
	int chunk_number = 0;
	long lines_written = 0;
	char buffer[READ_CHUNK_SIZE];
	FILE *input;
	FILE *output = NULL;

	/* Check if 2 arguments are provided */
	if (argc != 3) {
		printf("Usage: ./a.out <input filename> <output file size>\n");
		return EXIT_USAGE;
	}
	
	/* Check if the output file size is a positive integer */
	if(!is_positive_integer(argv[2], &max_lines)) {
		printf("Error: 2nd argument must be a positive integer.\n");
		return EXIT_BAD_SIZE;
	}

	/* Open the input file for reading */
	input = fopen(argv[1], "r");
	if (input == NULL) {
		printf("Error opening input file '%s'\n", argv[1]);
		return EXIT_INPUT_ERROR;
	}

	/* Read the input file one line at a time */
	while (fgets(buffer, READ_CHUNK_SIZE, input) != NULL) {
	
		/* Create the next output file only if there is a line to write */
		if (output == NULL) {
			chunk_number++;
			output = open_chunk(chunk_number, input);
			lines_written = 0;
		}

		/* Write the current line to the output file */
		fputs(buffer, output);
		lines_written++;
		
		/* Close the current chunk after it is full */
		if (lines_written == max_lines) {
			fclose(output);
			output = NULL;
		}
	}
	
	/* Close any open output file */
	if (output != NULL)
		fclose(output);
	/* Close the input file */
	fclose(input);

	return 0;
}


int is_positive_integer(const char *str, long *value)
{
	const char *p = str;
	
	if (*p == '\0')
		return 0;
	
	while (*p != '\0') {
		if (!isdigit((unsigned char) *p))
			return 0;
		p++;
	}
	
	*value = strtol(str, NULL, 10);

	return *value > 0;
}

/* open_chunk: opens the output file chunk <chunk_number>.txt for writing. */
 


FILE *open_chunk(int chunk_number, FILE *input)
{
	char filename[MAX_SIZE_FILENAME];
	FILE *output;

	snprintf(filename, MAX_SIZE_FILENAME, "chunk_%d.txt", chunk_number);
	
	output = fopen(filename, "w");
	if (output == NULL) {
		printf("Error creating output file: %s\n", filename);
		fclose(input);
		exit(EXIT_OUTPUT_ERROR);
	}
	
	return output;
}
