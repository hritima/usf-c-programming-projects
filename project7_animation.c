/*
 * Project7_animation.c
 * Name: Hritima Thapa Magar
 * netid: hritima
 * Program description: Reads animation movie data from a CSV file, searches for all animations
 * released in or after a user-entered year, and writes all matching records to an output
 * CSV files.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ANIMATIONS 500
#define MAX_TITLE_LEN 100
#define MAX_DESCRIPTION_LEN 500

#define INPUT_FILENAME "animation.csv"
#define OUTPUT_FILENAME "result.csv"

struct animation {
	char titile[MAX_TITLE_LEN + 1];
	int year;
	char description[MAX_DESCRIPTION_LEN + 1];
};

int search(struct animation *list, int len, int year, struct animation *result);

int main(void)
{
	struct animation list[MAX_ANIMATIONS];
	struct animation result[MAX_ANIMATIONS];
	int len = 0;
	int year;
	int matches;
	int i;
	FILE *input;
	FILE *output;
	
	input = fopen(INPUT_FILENAME, "r");
	if (input == NULL) {
		printf("Error opening input file '%s'\n", INPUT_FILENAME);
		exit(EXIT_FAILURE);
	}

	/* Skip the header line */
	fscanf(input, "%*[^\n]\n");
	
	/* Read the records, one animation per line */
	while (len < MAX_ANIMATIONS &&
		fscanf(input, "%100[^,},%d,%500[^\n]\n", list[len].title, 
			&list[len].year, list[len].description) == 3)
		len++;

	fclose(input);

	printf("Enyer release year: ");
	if (scanf("%d", &year) != 1) {
		printf("Invalid year\n");
		exit(EXIT_FAILURE);
	}
	
	matches = search(list, len, year, result);

	output = fopen(OUTPUT_FILENAME, "w");
	if (output == NULL) {
		printf("Error creating output file: %s\n", OUTPUT_FILENAME);
		exit(EXIT_FAILURE);
	}
	
	fprintf(output, "title,year,description\n");
	for (i = 0; i< matches; i++)
		fprintf(output, "%s,%d,%s\n", result[i].title, result[i].year, result[i].description);
	
	fclose(output);

	printf("Output filename: %s\n", OUTPUT_FILENAME);

	return 0;
}

/* 
 * search: copies every animation in list released in or after year into result, keeping their original order, 
 * and returns how many were copied.
 */

int search(struct animation *list, int len, int year, struct animation *result) 
{
	int count = 0;
	int i;
	
	for (i =0; i < len; i++) {
		if (list[i].year >= year) {
			result[count] = list[i];
			count++;
		}
	}

	return count;
}
