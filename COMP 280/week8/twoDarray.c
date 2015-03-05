/*
 * This program shows examples of 3 different ways of declaring,
 * and accessing 2D arrays and of how they are laid out in memory
 *  (1) statically allocated: 
 *      row-major order, all elements contigous
 *  (2) dynamically allocated in a single malloc: 
 *      all elements contiguous 
 *  (3) dynamically allocated array of arrays: M+1 mallocs: 
 *      all elements NOT necessarily contiguous, only guaranteed
 *      to be contiguous within each malloc'ed row
 */

#include <stdio.h>
#include <stdlib.h>

#define N  4 
#define M  5 

// Functions to initialize the values of 3 types of 2D arrays
void init_static(int array[][M], int rows);
void init_dynamic(int *array, int rows, int cols) ;
void init_dynamic_N(int **larr, int rows, int cols);

// Function to print addresses of all elements in 3 types of 2D arrays
void print_static_addrs(int array[][M], int rows) ;
void print_dynamic_addrs(int *array, int rows, int cols) ;
void print_dynamic_N_addrs(int **array, int rows, int cols) ;

// Function to print values in a 2D array
void print_array(int *array, int rows, int cols) ;

int main() {

	int static_array[N][M];  // a statically allocated 2D array with N rows and M columns
	int *darr;       // a dynamically allocated "2D" array using 1 malloc
	int **larr;      // a dynamically allocated "2D" array using N+1 mallocs 

	// (1) statically declared: let's see how these are laid out in memory
	printf("\n");
	print_static_addrs(static_array, N); 

	// (2) a dynamically allocated 2D array as a single malloc
	darr = malloc(sizeof(int)*N*M);  // NxM int values
	if(!darr) {
		printf("malloc failed\n");
		exit(1);
	}
	// let's see how these are laid out in memory
	print_dynamic_addrs(darr, N, M); 

	// (3) a dynamically allocated 2D array as N+1 mallocs
	// first: malloc up 1 array of N int *'s, one for each row
	//  next: malloc up N arrays of M ints, one for each row of values 
	larr = malloc(sizeof(int *)*N);
	if(!larr) {
		printf("malloc larr failed\n");
		exit(1);
	}

	int i;
	for(i=0; i < N; i++) {
		// next: malloc up space for each row's set of int values
		larr[i] = malloc(sizeof(int)*M);
		if(!larr[i]) {
			printf("malloc larr failed\n");
			exit(1);
		}
	}
	// let's see how these are laid out in memory
	print_dynamic_N_addrs(larr, N, M);

	// let's initialize these arrays, we need separate functions 
	// for each type:
	init_static(static_array, N);
	init_dynamic(darr, N, M);
	init_dynamic_N(larr, N, M);

	printf("\ndarr values:\n");
	print_array(darr, N, M);
	printf("\nsarr values:\n");

	// we can use this same print_array function to print out elements
	// in static_array, we need to re-cast to get rid of a compiler warning
	// (the compiler really doesn't like our doing this, but we know we can)
	print_array((int *)static_array, N, M);

	// we cannot, however, use the print_array function to print the
	// larr (the dynamically allocated array of arrays) because unlike
	// static_array and darr, all of its elements are not contiguous in memory
	printf("\nlarr values:\n");
	for(i=0; i < N; i++) {
		int j;
		for(j=0; j < M; j++) {
			printf(" %3d", larr[i][j]);
		}
		printf("\n");
	}

	// free space for darr: in one call to free
	free(darr); 
	darr = 0;

	// free space for larr in N+1 calls to free: one for each row array
	// and one for the array of arrays
	for(i=0; i < N; i++) {
		free(larr[i]); 
	}
	free(larr);

	return 0;
}


/**
 * Print out the addresses of each element in the passed
 * statically declared array
 * @param array The array of ints
 * @param rows The number of rows in the passed array
 */
void print_static_addrs(int array[][M], int rows) {

	int i,j;

	printf("Statically Declared 2D Array addresses:\n");
	printf("(note all contigous addresses in row-major order)\n");
	printf("-------------------------------------------------\n");
	for(i=0; i < rows; i++) {
		for(j=0; j < M; j++) {
			printf("[%d][%d]:%p  ", i, j, &array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


/**
 * print out the addresses of each element in the passed
 * dynamically declared 2D array
 * @param array The array of ints
 * @param rows The number of rows in the passed array
 * @param cols The number of rows in the passed array
 */
void print_dynamic_addrs(int *array, int rows, int cols) {

	int i,j;

	printf("Dynamically allocated 2D array (single malloc version) addresses:\n");
	printf("(note all contigous addresses in row-major order)\n");
	printf("-----------------------------------------------------------------\n");
	for(i=0; i < N; i++) {
		for(j=0; j < M; j++) {
			// note the difference in how we are accessing array elements 
			// in static (print_static_addrs) vs. this dynamically declared 
			// 2D array 
			printf("[%d][%d]:%p  ", i, j, &array[i*M + j]);
		}
		printf("\n");
	}
	printf("\n");
}


/**
 * Print out the addresses of each element in the passed
 * dynamically declared 2D array (the array of arrays version)
 * @param array The array of ints
 * @param rows The number of rows in the passed array
 * @param cols The number of rows in the passed array
 */
void print_dynamic_N_addrs(int **array, int rows, int cols) {

	int i,j;

	printf("Dynamically allocateed 2D array (as array of arrays) addresses:\n");
	printf("(note addresses NOT all contigous (only within each row)\n");
	printf("---------------------------------------------------------------\n");
	for(i=0; i < N; i++) {
		for(j=0; j < M; j++) {
			// note: the difference in how we are accessing array elements 
			// in this versionf from the other dynmaically allocated
			// 2D array (as one big malloc) in print_dynamic_addrs
			printf("[%d][%d]:%p  ", i, j, &array[i][j]);
		}
		printf("\n");
	}
}


/**
 * intialize a statically declared array
 * @param array The array to init, M is the column dimension
 *          the row dimension does not need to be specified here.
 * @param rows The number of rows in this array.
 *
 * @remark We need to specify the column index to the array parameter
 * so that the compiler can generate code that will compute where 
 * the start of each row is in memory.
 * Passing in rows as a second parameter just makes this more
 * generic than specifying both the exact row and column dimentions
 * in the parameter.
 */
void init_static(int array[][M], int rows) {

	int i, j;
	for(i=0; i < rows; i++) {
		for(j=0; j < M; j++) {
			array[i][j] = i+j;
		}
	}
}


/**
 * intialize a dynamically declared array 2D array
 * (the single malloc of an NxM contiguous chunk of ints kind)
 * @param array the array to init
 * @param rows the number of rows
 * @param cols the number of cols
 *
 * @remark We CANNOT use [i][j] syntax in here to access elements because
 *   the compiler cannot generate the right code to find the start
 *   of the next row (it depends on the col dimension).  As a result
 *   we will do the calculation in this code to get the rigth values.
 */
void init_dynamic(int *array, int rows, int cols) {
	int i, j;
	for(i=0; i < rows; i++) {
		for(j=0; j < cols; j++) {
			array[i*cols + j] = i+j;
		}
	}
}


/**
 * intialize a dynamically declared array 2D array 
 * (the N+1 mallocs, dynamically allocated array of arrays, kind)
 * @param array the array to init
 * @param rows the number of rows
 * @param cols the number of cols
 *
 * @remark  We CAN use [i][j] syntax here: i indexes into the top-level
 *   array, and j into the array element i points to
 */
void init_dynamic_N(int **array, int rows, int cols) {
	int i, j;
	for(i=0; i < rows; i++) {
		for(j=0; j < cols; j++) {
			array[i][j] = i+j;
		}
	}
}


/**
 * prints out the array values, one row per line
 * @param array the array to init
 * @param rows the number of rows
 * @param cols the number of cols
 */
void print_array(int *array, int rows, int cols) {
	int i, j;
	for(i=0; i < rows; i++) {
		for(j=0; j < cols; j++) {
			printf(" %3d", array[i*cols + j]);
		}
		printf("\n");
	}
}
