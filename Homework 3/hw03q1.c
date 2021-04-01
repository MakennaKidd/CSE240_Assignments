/*
Name: Makenna Kidd
Class Section: CSE240 Spring 2021 T+TH 1:30 - 2:45
Professor: Chen
IDE Used: Visual Studio
Assignment: Homework 3, HW03q1.c
				The aim of this assignment is to make sure that you understand and are familiar with the concepts
				covered in the lectures, including basic C syntax, using the strings, arrays, and multidimensional
				arrays. By the end of the assignment, you should have
				- understood the concepts of data, data declaration, forward declaration, and manipulation
					of values stored in the memory.
				- reviewed the array operations that you have learned in your previous programming classes;
				- written a program using multidimensional arrays in C. 
*/



#include <stdio.h>
#include <string.h>


#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Your job is to complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.

// Global Macro Values. They are used to define the size of 2D array of integers
#define NUM_ROWS 5
#define NUM_COLUMNS 5

#define NUM_STRINGS 5 
#define STRING_LENGTH 50

// Forward Declarations
void printMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void printScalarMultiple(int[NUM_ROWS][NUM_COLUMNS], int);
void squaredSumMatrices(int[NUM_ROWS][NUM_COLUMNS], int[NUM_ROWS][NUM_COLUMNS]);
void squaredTransposeMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void multiplyMatrix(int[NUM_ROWS][NUM_COLUMNS], int[NUM_ROWS][NUM_COLUMNS]);
int noOfOccurencesOfChar(char s[NUM_STRINGS * STRING_LENGTH], char);
void reverseStrings(char strings[NUM_STRINGS * STRING_LENGTH]);



// Problem 1: printMatrix (5 points)
// Traverse the 2D array of integers variable 'matrix' (input from main)
// and print the contents in the following format (actual contents may vary)
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
void printMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Enter code below

	/*
	Expected output
	1  2  3  4  5
	6  7  8  9  10
	11 12 13 14 15
	16 17 18 19 20
	21 22 23 24 25
	*/

	//Initiating variables
	int i, j;
	int matrixFunction;

	for (i = 0; i < NUM_ROWS; i++)  // for loop for rows
	{
		for (j = 0; j < NUM_COLUMNS; j++) // for loop for columns
		{
			matrixFunction = matrix[i][j]; //Function to calculate the result to plug into printing data
			printf(" %d", matrixFunction); //Plugging in matrixFunction calculation
		}
		printf("\n"); // printing a new line after each iteration
	}
}

// Problem 2: printScalarMultiple (5 points)
// Traverse the 2D array of integers 'matrix' and print scalar multiple of the matrix 
// e.g.
// 1 2 3	    2 4 6
// 4 5 6	=>  8 10 12
// 7 8 9        14 16 18
void printScalarMultiple(int matrix[NUM_ROWS][NUM_COLUMNS], int multiple)
{
	// Enter code below

	/*
	Expected output
	2  4  6  8  10
	12 14 16 18 20
	22 24 26 28 30
	32 34 36 38 40
	42 44 46 48 50
	*/

	//Initiating variables i and j
	int i, j;
	int matrixFunction;

	for (i = 0; i < NUM_ROWS; i++) // for loop for rows
	{
		for (j = 0; j < NUM_COLUMNS; j++) // for loop for columns
		{
			matrixFunction = (multiple * matrix[i][j]); //Function to calculate the result to plug into printing data
			printf(" %d", matrixFunction); //Plugging in matrixFunction calculation
		}
		printf("\n"); // printing a new line after each iteration
	}
}

// Problem 3: printSquaredDiagonal (5 points)
// Traverse the 2D array of integers 'matrix' and print each squared value on the diagonal from the 
// top left to bottom right position.
// e.g.
// 1 2 3		1 25 81
// 4 5 6	=>
// 7 8 9
void printSquaredDiagonal(int matrix[NUM_ROWS][NUM_COLUMNS])
{ 
	// Enter code below

	/*
	Expected output
	1 49 169 361 625
	*/

	//Initiating variables i and j
	int i, j;
	int matrixFunction;

	for (i = 0; i < NUM_ROWS; i++)  // for loop for rows
	{
		for (j = 0; j < NUM_COLUMNS; j++) // for loop for columns
		{
			if (i == j) // If i is the same number as j, then it will only print that int. 
			{
				matrixFunction = (matrix[i][j] * matrix[i][j]);//Function to calculate the result to plug into printing data
				printf(" %d", matrixFunction); //Plugging in matrixFunction calculation
			}
		}
	}
}


// Problem 4: squaredSumMatrices (5 points)
// Traverse the 2D array of integers 'matrices' and print the sum of each squared value.
// Consider both the arrays are of same size.
// e.g.
// 1 2 3   1 2 3        2 8 18
// 4 5 6   4 5 6	=> 32 50 72
// 7 8 9   7 8 9  	   98 128 162  

void squaredSumMatrices(int matrix1[NUM_ROWS][NUM_COLUMNS], int matrix2[NUM_ROWS][NUM_COLUMNS])
{
	// Enter code below

	/*
	Expected output
	2 8 18 32 50
	72 98 128 162 200
	242 288 338 392 450
	512 578 648 722 800
	882 968 1058 1152 1250
	*/

	//Initiating variables i and j
	int i, j;
	int matrixFunction;

	for (i = 0; i < NUM_ROWS; i++)  // for loop for rows
	{
		for (j = 0; j < NUM_COLUMNS; j++) // for loop for columns
		{
			matrixFunction = (matrix1[i][j] * matrix1[i][j] + matrix2[i][j] * matrix2[i][j]);//Function to calculate the result to plug into printing data
			printf(" %d", matrixFunction); //Plugging in matrixFunction calculation
		}
		printf("\n"); // printing a new line after each iteration
	}
}

// Problem 5: squaredTransposeMatrix (10 points)
// Take the 2D array of integers 'matrix' and print the squared tranpose matrix.
// You may assume that row and column counts are equal.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3	    1 16 49
// 4 5 6	=>  4 25 64
// 7 8 9        9 36 81
void squaredTransposeMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	int matrix2[NUM_ROWS][NUM_COLUMNS]; 
	// Enter code below

	/*
	Expected output
	1 36 121 256 441
	4 49 144 289 484
	9 64 169 324 529
	16 81 196 361 576
	25 100 225 400 625
	*/

	//Initiating variables i and j
	int i, j;

	//Looping column data first because it's now wanting the original column data to be in a row. Then doing the row data in a column. 
	for (j = 0; j < NUM_COLUMNS; j++) // for loop for columns
	{
		for (i = 0; i < NUM_ROWS; i++)  // for loop for rows
		{
			matrix2[j][i] = (matrix[i][j] * matrix[i][j]); // Matrix 2 = matrix * matrix to get the squared data
			printf(" %d", matrix2[j][i]); // Fetching matrix2 function 
		}
		printf("\n"); // printing a new line after each iteration
	}


}

// Problem 6: multiplyMatrix (10 points)
// Take two 2D arrays of integers 'matrix1' and 'matrix2' and print the 
// resulting matrix gained by multiplying the entries in each corresponding location.
// You can assume the two matrices will have the same dimensions.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3	1 2 3      1 4 9
// 4 5 6	4 5 6  =>  16 25 36
// 7 8 9    7 8 9      49 64 81
void multiplyMatrix(int matrix1[NUM_ROWS][NUM_COLUMNS], int matrix2[NUM_ROWS][NUM_COLUMNS])
{
	int matrixResult[NUM_ROWS][NUM_COLUMNS]; 
	// Enter code below
	
	/*
	Expected output
	1 4 9 16 25
	36 49 64 81 100
	121 144 169 196 225
	256 289 324 361 400
	441 484 529 576 625
	*/

	//Initiating variables i and j
	int i, j;

	for (i = 0; i < NUM_ROWS; i++)  // for loop for rows
	{
		for (j = 0; j < NUM_COLUMNS; j++) // for loop for columns
		{
			matrixResult[i][j] = (matrix1[i][j] * matrix2[i][j]); // Matrix Result = matrix1 * matrix2 to get the data
			printf(" %d", matrixResult[i][j]); //Fetching matrixResult function
		}
		printf("\n"); // printing a new line after each iteration
	}
	
}

// Problem 7: reverseString (5 points)
// Reverse each word in strings[]. 
// Consider one string at a time and reverse the characters. For instance, "hi hello" should reverse to "olleh ih".
void reverseStrings(char strings[NUM_STRINGS * STRING_LENGTH])
{
	// Enter code below



}

// Problem 8: noOfOccurencesOfChar (5 points)
// Count all occurrences of the specified character 'filter' from s[]. 
int noOfOccurencesOfChar(char s[NUM_STRINGS * STRING_LENGTH], char filter)
{
	// Enter code below



}

// You should study and understand how this main() works.
// *** DO NOT modify it in any way ***
int main()
{
	printf("CSE240 HW3: 2D Integer Arrays\n\n");

	int matrix[NUM_ROWS][NUM_COLUMNS] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};
	int multiple = 2;

	printMatrix(matrix);
	printf("\n\n");
	printScalarMultiple(matrix, multiple);
	printf("\n\n");
	printSquaredDiagonal(matrix);
	printf("\n\n");
	squaredSumMatrices(matrix, matrix);
	printf("\n\n");
	squaredTransposeMatrix(matrix);
	printf("\n\n");
	multiplyMatrix(matrix, matrix);

	printf("\nCSE240 HW3: 2D Character Arrays\n\n");

	char words[NUM_STRINGS * STRING_LENGTH];
	printf("\nEnter sentence with max 5 words: ");
	fgets(words, sizeof(words), stdin);
	reverseStrings(words);
	printf("\nReveresed string: %s", words);
	printf("\nNo of occurences of a: %d", noOfOccurencesOfChar(words, 'a'));
	int i = getchar();
	i = getchar(); // Keep console open
	return 0;
}
