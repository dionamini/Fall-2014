/*
 * Dion Amini
 * dion@dionamini.com
 * COMP 280 - week3 - gdb-test.c
 *
 * A simple C program with different type definitions and function call.
 * For gdb practice.
 * 
 */

#include <stdio.h>   
#include <string.h>   

float mystery(int x, int y);

int main() { 

	int x, i, p;
	unsigned int y;
	unsigned char uch;
	float z;
	int array[10];      
	char ch;
	char s[64];

	x = y = ch = uch = z = 1;

	array[0] = x;
	strcpy(s, "Hello");

	for(i = 0; i < 10; i++) {
		array[i] = i*i;
	}

	// let's set a break point before this line
	x = 10;  
	p = 8;
	z = p/x;  
	printf("x = %d p = %d z = %3.2f\n", x, p, z);
	z = mystery(x, p);
	printf("x = %d p = %d z = %3.2f\n", x, p, z);


	return 0;
}

// a mystery function
float mystery(int a, int b) {

	int i;
	float c;

	c = b/2.0;
	for(i=0; i < a; i++) {
		c += i;
	}
	return c;
}
