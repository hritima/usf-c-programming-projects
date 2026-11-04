/*
 * project1_transportation.c
 * 09/08/2026
 * Name: Hritima Thapa Magar
 * NetID: hritima
 * Description: This program calculates total transportation charge depending on the selected vehicle,
 *		 number of passengers and travel distance.
 */


#include <stdio.h>

#define BASE_DISTANCE 10

int main(void) {
	/* Declaring variables for user input */
	int selection, passengers; /* vehicle type and no. of passengers */
	double distance, charge; /* total travel distance and total charge */
	

	/* Vehicle index starts from 1-4 so leaving index 0 unused so that the array index matches the selection */
	
	int maxPassengers[5] = {0, 3, 4, 8, 12}; /*maxPassengers[i]=max passenger capacity for vehicle i*/
	double baseFee[5] = {0, 15.00, 25.00, 35.00, 60.00}; /* booking fee for vehicle[i] */
	double perMileRate[5] = {0, 2.00, 2.50, 3.00, 4.00}; /* additional charge per mile rate exceeding 10 miles for vehicle[i] */

	/* Getting vehicle selection */
	printf("Please select from four vehicle types: 1, 2, 3, and 4\n");
	printf("Enter selection: ");
	scanf("%d", &selection);

	/* Making sure the selection is between 1 and 4 otherwise exit */
	if (selection < 1 || selection > 4) {
		printf("Invalid selection. Select from 1 to 4.\n");
		return 0;
	}


	/* Getting the number of passengers */
	printf("Enter passengers: ");
	scanf("%d", &passengers);
	
	/* Making sure the passenger count is atleast 1  */
	if (passengers < 1) {
		printf("Invalid passenger count.\n");
		return 0;
	}
	
	/* Making sure the passenger count is within the vehicle's capacity */
	if (passengers > maxPassengers[selection]) {
		printf("Too many passengers for selected vehicle.\n");
		return 0;
	}

	
	/* Getting the travel distance */
	printf("Enter distance: ");
	scanf("%lf", &distance);  /* lf because distance is a double */
	
	/* Distance must be non-negative */
	if (distance < 0) {
		printf("Invalid distance.\n");
		return 0;
	}


	/* Calculating the transportation charge */
	charge = baseFee[selection]; /*fee for the first 10 miles */

	/* if the distance is more than 10 miles, add per-mile charge for each extra mile */
 	if (distance > BASE_DISTANCE) {
		charge += (distance - BASE_DISTANCE) * perMileRate[selection];
	}

	
	/* Displaying the final result */	
	printf("Charge: $%.2f\n", charge); /* Displaying the charge with dollar sign and  two decimals */
	return 0;

}
