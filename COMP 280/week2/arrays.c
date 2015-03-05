/*
 * Dion Amini
 * dion@dionamini.com
 *
 * University of San Diego
 * CS280 - week2 - arrays.c
 *
 */
#include <stdio.h>
#include <stdlib.h> // needed for rand() function

// constant definitions (N is a synonym for 10)
#define N  10

// forward declarations of functions we'll use inside of the main function
// these need to be declared before being used in main
void printArray(int arr[], int size);
void swap(int a[], int ind1, int ind2);

int main() {
	// Create an int array of size N and fill it in with random numbers
	// between 0 and 99
	int size = N;
	int array[N]; // create array of size N (constant defined above)

	int i;
	for (i=0; i < N; i++) {
		array[i] = rand() % 100;
	}

	// Call the mysterious foo function, printing out the array before and
	// after calling foo.
	printArray(array,size);
	swap(array, 3, 5);   
	printArray(array,size);

	return 0;
}

/*
 * Prints the array given as a paramter (arr), which has a size that is given
 * by another parameter (size).
 * Why do we need to specify the size of the array? - shows how much to print
 */
void printArray(int arr[], int size) {
	printf("%d elements:\n", size);

	int i;
	for(i=0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}

/*
 * What does this function do? - swap function
 * TODO: Rename it to something more appropriate.
 */
void swap(int a[], int ind1, int ind2){
	int temp;

	temp = a[ind1];
	a[ind1] = a[ind2];
	a[ind2] = temp;
}
