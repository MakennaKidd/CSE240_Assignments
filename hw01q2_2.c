/*
* Makenna Kidd
* CSE 240
* Professor Chen
* T+TH 1:30pm - 2:45pm
* Due Jan 23th by 11:59pm
*
* This program hw01q2_2 was rewritten from the provided homework problem into a for loop format to contain 
* break statements, fix syntax/semantic errors, change numbers to floating point, and allow user input to enter an operation. 
*
*/

#include <stdio.h>

void main()
{
	char ch = ' ';
	double a = 10, b = 20;
	double f;
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		printf(" Enter a math operation: ");
		ch = getchar(); // Reading char that user entered. 
		printf(" ch = %c \n", ch); //Printing char entered. 
		switch (ch)
		{
		// case statements below changed to floating numbers instead of decimals. 
		case '+': f = a + b; printf(" f = %g\n", f); break;
		case '-': f = a - b; printf(" f = %g\n", f); break;
		case '*': f = a * b; printf(" f = %g\n", f); break;
		case '/': f = a / b; printf(" f = %g\n", f); break;
		default: printf(" Invalid operator\n"); break;
		}
		ch = getchar();
	}
	ch = getchar(); // Restarting the loop to get another char and keeping the console window open. 
}
