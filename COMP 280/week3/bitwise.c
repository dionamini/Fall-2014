/*
 * Dion Amini
 * dion@dionamini.com
 * COMP 280 - week3 - bitwise.c
 *
 */
#include<stdio.h>

void printBinaryRep(int dec);

int main(){
	unsigned int deci;
	printf("Enter the decimal number to be converted: ");
	scanf("%d", &deci);
	printBinaryRep(deci); 
	return 0;
}

void printBinaryRep(unsigned int dec){
	int i;
	for(i=32;i>=0;i--){
		printf("%d",(x >> i)&1);
	}

	printf("Number you entered: %d\n", dec);
	printf("Binary Number: %d\n", x);
}


