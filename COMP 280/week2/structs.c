/*
 * Dion Amini
 * dion@dionamini.com
 *
 * University of San Diego
 * CS280 - week2 - structs.c
 * Program to practice C structs
 */

#include <stdio.h>
#include <string.h>

// here are some good program constants 
#define MAXNAME  64
#define MAXADDR  256
#define MAX_STUDENTS  40 

// define a struct type to hold student data
struct Student {
  char  name[MAXNAME];
  int   age;
  int   grad_yr;
  float gpa;
  char  address[MAXADDR];
};

// Using typedef allows us to avoid typing in "struct Student" all the time.
// Instead, we can just shorten this to "Student" now.
typedef struct Student Student;

// function prototypes
void printStudent(Student student);

/***********************************************************/
int main() {
	struct Student student1;
	Student student2;
	Student comp280[MAX_STUDENTS];

	student1.age = 20;
	student1.grad_yr = 2016;
	strcpy(student1.name, "Grace Hopper");
	strcpy(student1.address, "Serra Hall, Room 163");
	student1.gpa = 3.9;
	


	student2 = student1;
	strcpy(student2.name, "Alan Turing");
	student2.address[15] = '6';

//	printStudent(student1);
//	printStudent(student2);
	

	// TODO: (2) use a for loop to initialize the first 5 buckets of
	//           the comp280 array.  Use some expression based on
	//           the loop counter variable to set the age, grad_yr
	//           and gpa fields to be different.  
	//           Every student can just be named "student" and 
	//           live at "5998 alcala park"
	//
	int i;
	for(i=0; i<5; i++) {
		comp280[i];
		strcpy(comp280[i].name, "Student");
		strcpy(comp280[i].address, "5998 Alcala Park");
		comp280[i].age = 20 + i;
		comp280[i].grad_yr = 2015 + i;
		comp280[i].gpa = 3.0 + 0.5*i;
	}
	
	// TODO: (3) add a for loop to print out the comp280 values (call your
	//           function from part 1)
	//
//	for(i=0; i<5; i++){
//		printStudent(comp280[i]);
//	}


	// TODO: (4) add some code to insert a new student into bucket 1 
	//           of the comp280 array (shifting over existing values
	//           to make a hole to insert it)
	for(i=5;i>=0;i--){
	//FIXXXXXXXXXX
	
	}
	strcpy(comp280[0].name, "StudentNEW");
	strcpy(comp280[0].address, "5998 Alcalo Pork");
	comp280[0].age = 20;
	comp280[0].grad_yr = 2015;
	comp280[0].gpa = 3.0;
	for(i=0;i<=6;i++){
		printStudent(comp280[i]);
	}

	// TODO: (5) add a for loop to print out the comp280 values (call your
	//           function from part 1)  
	//

	// TODO: (6) write a function to swap to bucket values and
	//           call it here
	//

	// TODO: (7) add a for loop to print out the comp280 values (call your
	//           function from part 1)  (This seems like it might
	//           be a good thing to turn into a function....)

	return 0;
}

/*
 * prints out the information about the passed student
 * @param: student: the student whose data to print
 */
void printStudent(struct Student student){	

	printf("Student: %s\n", student.name);
	printf("Age: %d\n", student.age);
	printf("Grad Year: %d\n", student.grad_yr);
	printf("GPA: %f\n", student.gpa);
	printf("Address: %s\n", student.address);
}
