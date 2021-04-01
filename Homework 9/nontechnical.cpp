
// CSE240 Spring 2021 HW9
// Makenna Kidd
// Programming environment used: VS - Visual Studio

// Q2a: Define displayEmployee() for Nontechnical class (5 points)
// Define the function displayEmployee() that you declared within the Nontechnical class in the header file
// See expected output in question file.

// (displayList() function in hw9.cpp should call this function.)
// Include necessary header files

#include <iostream>
#include "employee.h"
#include "Nontechnical.h"

void Nontechnical :: displayEmployee()
{
	cout << endl << " Employee Name: " << getName() << endl;
	cout << " Salary: " << getSalary() << endl;
	cout << " Employee Type: Nontechnical" << endl << endl; //There is no need to call a function as this is the class for the Nontechnical type.
} 
