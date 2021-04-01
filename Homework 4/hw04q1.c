//CSE240 Spring 2021 HW4

// Makenna Kidd
// State the IDE that you use: Visual Studio 

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.
// You can use only the strlen() of strings.h library to check string length. Do not use any other string functions 
// because you are supposed to use pointers for this homework. 
// **** DO NOT use arrays to store or to index the characters in the string ****

// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
void toUppercase(char[STRING_LENGTH]);
void toLowercase(char[STRING_LENGTH]);
void changeAllToUpperOrLower(char[NUM_STRINGS][STRING_LENGTH], char);
void wordMatch(char strings[NUM_STRINGS][STRING_LENGTH], char input[STRING_LENGTH]);
void concatStr(char[NUM_STRINGS][STRING_LENGTH], char[NUM_STRINGS * STRING_LENGTH]);


// Problem 1: initializeStrings (5 points)
// Use pointer 'p' to traverse the 2D array of characters variable 'strings' (input from user in main() ) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* p = &strings[0][0];
	// enter code here

	//Initialized Variables
	int i, j;

	for (i = 0; i < NUM_STRINGS; i++) //For loop for i iteration - Num Strings
	{
		for (j = 0; j < STRING_LENGTH; j++) //For loop for j iteration - String Length
		{
			*(p++) = '\0'; // Pointer to transverse null terminator, which is used to denote the end of a string. 
		}
	}
}

// Problem 2: printStrings (5 points)
// Use pointer 'p' to traverse the 2D character array 'strings' and print each string.
// See the example outputs provided in the word document. Each string should be printed on a new line.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* p = &strings[0][0];
	// enter code here

	//Initialized Variables
	int i, j;

	for (i = 0; i < NUM_STRINGS; i++) //For loop for i iteration - Num Strings
	{
		for (j = 0; j < STRING_LENGTH; j++) //For loop for j iteration - String Length
		{
			printf("%c", *p++); // Printing the char to print the string. 
		}
		printf("\n"); // Each string is being printed on a new line. 
	}

}

// Problem 3: toUppercase() and toLowercase() (15 points)
// Problem 3-1: toUppercase 
// Convert the string in the array 's' to an uppercase string.
// Traverse the input using pointer 'p' and covert the character to an uppercase letter if it is lowercase.
// You need to write down the code to check whether or not the character is lowercase.
// HINT: Use a pointer to change the ASCII value of a character.
//       The ASCII value of 'a'= 97 and the ASCII value of 'A' = 65 so the difference between them is 32.
void toUppercase(char s[STRING_LENGTH])
{
	char* p = &s[0];
	// enter code here

	//Initialized Variables
	int i;

	for (i = 0; i < STRING_LENGTH; i++) //For loop for i iteration - Num Strings
	{
		if (*p >= 'a' && *p <= 'z') // If char is lowercase, pointer will change the ASCII value to uppercase. 
		{
			*p -= 32; //The difference between the ASCII values of lower case and uppercase letters
		}
		p++; //Incrementing p
	}
}

// Problem 3-2: toLowercase 
// HINT : This should be very similar to toUppercase().
// Convert the string in the array 's' to an lowercase string.
// Traverse the input using pointer 'p' and covert the character to a lowercase letter if it is uppercase.
// You need to write down the code to check whether or not the character is uppercase.
// HINT: Use a pointer to change the ASCII value of a character.
//       The ASCII value of 'a'= 97 and the ASCII value of 'A' = 65 so the difference between them is 32.
void toLowercase(char s[STRING_LENGTH])
{
	char* p = &s[0];
	// enter code here

	//Initialized Variables
	int i;

	for (i = 0; i < STRING_LENGTH; i++) //For loop for i iteration - Num Strings
	{
		if (*p >= 'A' && *p <= 'Z') // If char is uppercase, pointer will change the ASCII value to lowercase. 
		{
			*p += 32; //The difference between the ASCII values of lower case and uppercase letters
		}
		p++; //Incrementing p
	}
}


// Problem 4: changeAllToUpperOrLower (5 points)
// Change all words in the array 'strings' to uppercase or lowercase based on the value of char variable 'set'.
// If the value of char 'set' is 'u' or 'U', change all words to uppercase strings.
// If the value of char 'set' is 'l' or 'L', change all words to lowercase strings.
// No change, otherwise.
// You may use toUppercase() and toLowercase() here.
void changeAllToUpperOrLower(char strings[NUM_STRINGS][STRING_LENGTH], char set)
{
	char* ptr = &strings[0][0];
	// enter code here

	//Initialized Variables
	int i;

	if (set == 'u' || set == 'U') // If the value of char 'set' is 'u' or 'U', change all words to uppercase strings.
	{
		for (i = 0; i < NUM_STRINGS; i++) //For loop for i iteration - Num Strings
		{
			toUppercase(strings[i]);
		}
	}
	else if (set == 'l' || set == 'L') // If the value of char 'set' is 'l' or 'L', change all words to lowercase strings.
	{
		for (i = 0; i < NUM_STRINGS; i++) //For loop for i iteration - Num Strings
		{
			toLowercase(strings[i]);
		}
	}


}

// Problem 5: wordMatch (10 points)
// This function must be working as follows:
// 1. Compare the strings in the 2D array with input string
// 2. If one of them matches with input string, print "Match found"
// 3. Else print "Match not found"
// Example: strings array -> ["Hi", "Sun", "Devils"], input -> "Sun"  => print "Match found"
// Example: strings array -> ["Hi", "Sun", "Devils"], input -> "Hello"  => print "Match not found"
void wordMatch(char strings[NUM_STRINGS][STRING_LENGTH], char input[STRING_LENGTH])
{
	char* p = &strings[0][0];
	char* ip = input;
	int flag = 0;
	// enter code here
	 
	//Initialize variables
	int i, j;

	for (int i = 0; i < NUM_STRINGS; i++) //For loop for i iteration - Num Strings
	{
		flag = 0;
		while (*(p + (i * STRING_LENGTH) + flag) == *(ip + flag))  //While loop for i iteration - STRING_LENGTH
		{
			if (*(p + (i * STRING_LENGTH) + flag) == '\0' || *(ip + flag) == '\0') // Statment to compare input until null terminator is reached
			{
				break;
			}
			flag++; // Increment flag
		}
		if (*(p + (i * STRING_LENGTH) + flag) == '\0' && *(ip + flag) == '\0') //While loop for i iteration - STRING_LENGTH , // Statment to compare input until null terminator is reached
		{
			printf("Match found\n"); // If flag is found or equals 1, print out "Match found" //If flag = 0  equals string is found, statement can break/end. 
			return;
		}
	}
	printf("Match not found\n"); // If flag is NOT found or equals 0, print out "Match not found"
	return;
}


// Problem 6: concatStr (10 points)
// This function must be working as follows:
// 1. Concatenate the string in the array 'strings' together in a sentence.
// 2. Store the string to the array 'result'.
// 3. Print the string in the array 'result'.
// The sample output is shown in document
// NOTE: This is the function partially containing what you have implemented so far.
// Initialize the array 'result' first before you store a string to it.
// You may declare and use more pointers if needed.
void concatStr(char strings[NUM_STRINGS][STRING_LENGTH], char result[NUM_STRINGS * STRING_LENGTH]) 
{
	char* p_result = result;
	char* p_input = &strings[0][0];
	// enter code here

	//Initialize variables
	int i, j;
    int flag = 0;

	for (int i = 0; i < NUM_STRINGS; i++)  //For loop for i iteration - Num Strings
	{
		for (int j = 0; j < STRING_LENGTH; j++)  //For loop for i iteration - STRING_LENGTH
		{
			*(p_result + flag) = *(p_input + (i * STRING_LENGTH) + j); // iterating through string length
			flag++; // increment flag
		}
		*(p_result + flag) = ' '; // print spaces between strings
		flag++; // increment flag
	}
	for (int i = 0; i < (NUM_STRINGS * STRING_LENGTH); i++) // for loop for iterating through num strings and string length
	{
		printf("%c", *(p_result + i)); // printing strings
	}
}

// You should study and understand how main() works.
// *** DO NOT modify it in any way ***
int main()
{
	char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
	int i, key;
	char input[STRING_LENGTH];
	char result[NUM_STRINGS * STRING_LENGTH];

	printf("CSE240 HW4: Pointers\n\n");
	initializeStrings(strings);

	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter a string: ");				// prompt for string
		fgets(input, sizeof(input), stdin);		// store input string
		input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input);				// copy input to 2D strings array
	}

	printf("\nEnter a string to find a match: ");	// prompt for string
	fgets(input, sizeof(input), stdin);			// store input string
	input[strlen(input) - 1] = '\0';			// convert trailing '\n' char to '\0' (null terminator)

	// Word match function call
	wordMatch(strings, input);

	// Concate all strings in array string to a sentence
	printf("\n\nThe concatenated string is: \n");
	concatStr(strings, result);

	// Convert all strings in array string to a particular case
	printf("\n\nChange strings to a particular case: \n");
	changeAllToUpperOrLower(strings, 'l');
	printStrings(strings);
	getchar();									// flush out newline '\n' char



	getchar();									// keep VS console open
	return 0;
}