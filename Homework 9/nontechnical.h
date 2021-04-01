
// CSE240 Spring 2021 HW9
// Makenna Kidd
// Programming environment used: VS - Visual Studio

#ifndef _NONTECHNICAL_H
#define _NONTECHNICAL_H
// Q1a: Create Nontechnical class (5 points)
// Part 1: Create a child class of the Employee class named 'Nontechnical'
class Nontechnical : public Employee
{

// Part2: Declare constructor which accepts the same 3 parameters as the parent class Employee's constructor.
// Pass the 3 parameters to the super constructor of the Employee class.
public: 
	Nontechnical(string empName, double salary_input, empType employeeType) : Employee(empName, salary_input, employeeType)
	{
	}
// Part 3: Re-declare the method displayEmployee (virtual method found inside of parent class Employee)
	void displayEmployee();
};
#endif // _NONTECHNICAL_H#pragma once
