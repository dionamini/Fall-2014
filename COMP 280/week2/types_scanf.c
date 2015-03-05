/*
 * Dion Amini
 * dion@dionamini.com
 *
 * University of San Diego
 * CS280 - week2 - types_scanf.c
 * A prorgam to demonstrate the different types available in
 * as well as input/output and if statements.
 *
 */
#include <stdio.h>
#include <stdlib.h>

// define some constant values
#define MAXNAME 128
#define CURRYEAR 2014

int main() {

	int birthYear, feet, inches, height, woman;
	float compare, avgMale = 69.4, avgFemale = 63.8;
	char *name = malloc(MAXNAME*sizeof(char));

	printf("Enter your first name: ");
	scanf("%s", name);
	printf("Hello %s\n", name);

	printf("Enter the year you were born: ");
	scanf("%d", &birthYear);
	printf("You must be about %d years old\n", CURRYEAR-birthYear);

	printf("Enter your height in feet and inches (e.g. 5 10): ");
	scanf("%d%d", &feet, &inches);
	height = 12 * feet + inches;
	printf("Do you identify as a woman (1:y or 0:n): ");
	scanf("%d", &woman);

	if (woman) {
		printf("For a woman, ");
		compare = (height/avgFemale)*100;
	}
	else {
		printf("For a man, ");
		compare = (height/avgMale)*100;
	}

	if (compare < 100) {
		printf("you are %.2f %% shorter than average\n", (100-compare));
	}
	else {
		printf("you are %.2f %% taller than average\n", (compare-100));
	}

	free(name);
	name = NULL;

	return 0;
}
