/*
* Makenna Kidd
* CSE 240
* Professor Chen
* T+TH 1:30pm - 2:45pm
* Due Jan 23th by 11:59pm
*
* This program hw01q2 was rewritten from the provided homework problem to contain break statements and fixed syntax/semantic errors as well as change the integers to floating numbers.
*
*/

#include <stdio.h>

void main() 
{
	// Case statement for operation "+"
	char ch = '+';
	double a = 10, b = 20;
	double f;
	printf(" ch = %c\n", ch);
	switch (ch) 
	{
	case '+': f = a + b; printf(" f = %g\n", f); break;
	case '-': f = a - b; printf(" f = %g\n", f); break;
	case '*': f = a * b; printf(" f = %g\n", f); break;
	case '/': f = a / b; printf(" f = %g\n", f); break;
	default: printf(" Invalid operator\n"); break;
	}
	// Case statement for operation "-"
	ch = '-';
	printf(" ch = %c\n", ch);
	switch (ch) 
	{
	case '+': f = a + b; printf(" f = %g\n", f); break;
	case '-': f = a - b; printf(" f = %g\n", f); break;
	case '*': f = a * b; printf(" f = %g\n", f); break;
	case '/': f = a / b; printf(" f = %g\n", f); break;
	default: printf(" Invalid operator\n"); break;
	}
	// Case statement for operation "*"
	ch = '*';
	printf(" ch = %c\n", ch);
	switch (ch) 
	{
	case '+': f = a + b; printf(" f = %g\n", f); break;
	case '-': f = a - b; printf(" f = %g\n", f); break;
	case '*': f = a * b; printf(" f = %g\n", f); break;
	case '/': f = a / b; printf(" f = %g\n", f); break;
	default: printf(" Invalid operator\n"); break;
	} 
	// Case statement for operation "/"
	ch = '/';
	printf(" ch = %c\n", ch);
	switch (ch) 
	{
	case '+': f = a + b; printf(" f = %g\n", f); break;
	case '-': f = a - b; printf(" f = %g\n", f); break;
	case '*': f = a * b; printf(" f = %g\n", f); break;
	case '/': f = a / b; printf(" f = %g\n", f); break;
	default: printf(" Invalid operator\n"); break;
	} 
	// Case statement for operation "%" which is the invalid operation. 
	ch = '%';
	printf(" ch = %c\n", ch);
	switch (ch) 
	{
	case '+': f = a + b; printf(" f = %g\n", f); break;
	case '-': f = a - b; printf(" f = %g\n", f); break;
	case '*': f = a * b; printf(" f = %g\n", f); break;
	case '/': f = a / b; printf(" f = %g\n", f); break;
	default: printf(" Invalid operator\n"); break;
	}
}