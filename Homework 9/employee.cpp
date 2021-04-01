
// CSE240 Spring 2021 HW9
// Makenna Kidd
// Programming environment used: VS - Visual Studio

#include "employee.h"

// definitions of Employee member functions
Employee::Employee(string empName, double salary_input, empType employeeType)
{
	name = empName;
	salary = salary_input;
	et = employeeType;
}

string Employee::getName()
{
	return name;
}

double Employee::getSalary()
{
	return salary;
}

empType Employee::getEmpType()
{
	return et;
}