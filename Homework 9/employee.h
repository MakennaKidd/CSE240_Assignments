
// CSE240 Spring 2021 HW9
// Makenna Kidd
// Programming environment used: VS - Visual Studio

#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
using namespace std;

enum empType { nontechnical = 0, technical };	// definition of empType

class Employee {
private:
	string name; // private data members
	double salary;
	empType et;

public:
	Employee(string empName, double salary, empType employeeType); // constructor

	// accessor methods
	string getName();
	double getSalary();
	empType getEmpType();

	virtual void displayEmployee()
	{}

	// Q3a: Declare Friend Function changeSalary()  (1 point)
	// Declare a friend function named changeSalary() which has 2 parameters and no return value.
	// The first parameter is a pointer to Employee class, and the second is a double which is the new salary.
	// You need to define this function in hw9.cpp and call this function in case 'c' of executeAction() in hw9.cpp file

	//Declared friend function that has two parameters and no return
	friend void changeSalary(Employee *employee, double salary_input);

};

#endif // _EMPLOYEE_H_#pragma once

