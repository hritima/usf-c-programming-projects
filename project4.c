/* 
 * Project4.c: Pairing array elements with pointer
 * Name: Hritima Thapa Magar
 * netid: hritima
 * Program description: program that reads an integer array 
 * and pairs the first element with last, second with second
 * last one and so on and creates a new array that stores 
 * the sum of each pair. If the array has an odd number of
 * elements, the middle element is stored unchanged in
 * the output array
 *
 */

#include <stdio.h>

/* Declaring function for paring and adding array elements. */
void pair_sums(int *input, int n, int *output);

int main(void)
{
	int n, i;

	printf("Enter the length of the array: ");
	scanf("%d", &n);
	

	/*Creates array for input values and output sums. */
	int input[n];
	int output[(n + 1) / 2];

	printf("Enter the elements of the array: ");
	for (i = 0; i < n; i++){
		scanf("%d", &input[i]); /* Reads the elements. */
	}


	/* Calculate the paired sum and store them in output. */
	pair_sums(input, n, output);

	printf("Output:");
	for (i = 0; i < (n + 1) / 2; i++){
		printf(" %d", output[i]);
	}
	printf("\n");
	
	return 0;
}	
	
/* Adding elements from opposite ends of the input by using array and stores sum in output array. */


void pair_sums(int *input, int n, int *output)
{ 
	/* Settin pointers. */
	int *front = input;
	int *back = input + n - 1;
	int *out = output;
	
	/* Adding elements from opposite ends until the pointers meet. */
	while (front < back){
		*out = *front + *back;

		/* Move the pointer toward the middle. */
		out++;
		front++;
		back--;
	}

/* If the input element is odd, copy the middle element. */
	if (front == back){
		*out = *front;
	}
}
