/*
*
* Makenna Kidd
* CSE 240
* Professor Chen
* T+TH 1:30pm - 2:45pm
* Due Jan 23th by 11:59pm
* This program hw01q3answer is fixing errors in the program provided via homework assignment 1 on Canvas 
* and stating what kind of erros are presented whether it be contextual, syntactically, or sementically. 
*
*/

#include <stdio.h>
#pragma warning(disable : 4996) // needed if using Visual Studio - I used Visual Studio for this assignment. 

// CSE 240 Spring 2021 Homework 1 Question 3 (20 points)
// Before starting this assignment, please compile and run this program. 
// You will first notice that the program will not compile. Fix the errors and define the error types.
// Next, you will notice that the program is printing incorrect information. Fix the errors and define those error types.

int main() {


	// Problem 1: (4 points)
	// The statement below should cause the program to not compile. Correct the error(s). (2 points).

	double p = 20.18; //variable type was written as int instead of double. 

	printf(" p is equal to %f\n", p);

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf(" Error Type: ___Contextual___ \n\n");


	// Problem 2: (4 points)
	// Half of 50 is 25, why is the program printing that half of 50 is 0? Correct the error(s) (2 points).

	int q = 50;

	printf(" Half of %d is %d\n", q, (q / 2)); //The previous program was written improperly as q* (1/2) when that's not a proper function in programming. 

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf(" Error Type: ___Semantic____ \n\n");


	//Problem 3    (2 points)
	//Integer variable y is initialized to 100 and its value needs to be printed. Correct the error(s).(1 point)
	
	int y = 100;

	printf(" y is %d\n", y);

	// Your answer should be either Syntactic, Semantic, or Contextual. (1 point)
	printf(" Error Type: __Semantic__ \n\n");

	//Give your explanation here:
	printf(" ____The statement provided has a char operation instead of a number operation____ \n\n");


	// Problem 4: (2 points)
	// Float variable f has been initialized to 3.14, why does the program seem to think otherwise? Correct the error(s) (2 points).

	float f = 3.14;

	if (f == 10) //improper use of equal in programming. It was previously written as (if = 10).
		printf("f is equal to 10.\n");
	if (f > 10)
		printf("f is greater than 10.\n");
	if (f < 10)
		printf("f is less than 10.\n");

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: ___Semantic___ \n\n");


	// Problem 5: (4 points)
	// Surely, 60 is an even number. Why is the program printing that 60 is an odd number? Correct the error(s) ( points).

	q = 60;

	if (q % 2 == 0) // Was previously using dividing sign when it should've been using modulo sign. 
		printf("%d is an even number.\n", q);
	if (q % 2 != 0) // Was previously using dividing sign when it should've been using modulo sign. 
		printf("%d is an odd number.\n", q);

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: ___Semantic____ \n\n");


	// Problem 6: (4 points)
	// This bit of code is meant to print "Hello World!". Correct the error(s) (2 points).

	printf("Hello %s\n", "World!");

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: ____Contextual_____ \n\n");

	return 0;
}
