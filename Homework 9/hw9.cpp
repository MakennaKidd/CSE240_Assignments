
// CSE240 Spring 2021 HW9
// Makenna Kidd
// Programming environment used: VS - Visual Studio


// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of employees.
// Each employee has name, salary and employee type (nontechnical or technical).
// This information is stored as an object of Employee class. Class defined in employee.h
// The classes Nontechnical and Technical are child classes of the Employee class.
// When adding a new employee, these child classes are used to make the employee node of the list.
// So each node in the list is actually an object of either Nontechnical or Technical class.

//
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// Do not modify given code.

// You can assume that all input is valid:
// Valid name:	String containing alphabetical letters
// Valid number: a positive integer

#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
#include "employee.h"
#include "technical.h"
#include "nontechnical.h"

using namespace std;

// functions already implemented:
void executeAction(char c);
Employee* searchEmployee(string name_input);


// functions that need implementation:
void addEmployee(string name_input, double salary_input, empType type);			// 7 points
void displayList();							// 4 points
void save(string fileName);					// 7 points
void load(string fileName);					// 7 points

Container* list = NULL;				// global list

int main()
{
	char c = 'i';				// initialized to a dummy value

  // During first execution, there will be no list.txt in source directory. list.txt is generated by save() while exiting the program.
	load("list.txt");
	do {
		cout << "\nCSE240 HW9\n";
		cout << "Please enter your selection:\n";
		cout << "\t a: add a new employee\n";
		cout << "\t d: display employee list\n";
		cout << "\t c: change salary of an employee\n";
		cout << "\t q: quit\n";
		cin >> c;
		cin.ignore();
		executeAction(c);
	} while (c != 'q');

	save("list.txt");

	list = NULL;

	return 0;
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	double salary_input;
	int type_input = 2;
	empType type;
	Employee* empResult = NULL;

	switch (c)
	{
	case 'a':	// add employee
				// input employee details from user
		cout << endl << "Enter employee name: ";
		getline(cin, name_input);
		cout << "Enter new salary: ";
		cin >> salary_input;
		cin.ignore();

		while (!(type_input == 0 || type_input == 1))
		{
			cout << "Enter employee type: " << endl;
			cout << "0. Nontechnical" << endl;
			cout << "1. Technical" << endl;
			cin >> type_input;
			cin.ignore();
		}
		type = (empType)type_input;

		// searchEmployee() will return the employee object if found, else returns NULL
		empResult = searchEmployee(name_input);
		if (empResult == NULL)
		{
			addEmployee(name_input, salary_input, type);
			cout << endl << "Employee added to list!" << endl << endl;
		}
		else
			cout << endl << "Employee already present in the list!" << endl << endl;

		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'c':		// change salary
		cout << endl << "Enter employee name: ";
		getline(cin, name_input);
		// searchEmployee() will return the employee node if found, else returns NULL
		empResult = searchEmployee(name_input);
		if (empResult == NULL)
		{
			cout << endl << "Employee not in list!" << endl << endl;
		}
		else
		{
			// if employee exists in the list, then ask user for new salary
			cout << endl << "Enter new salary: ";
			cin >> salary_input;
			cin.ignore();

			// Q3c Call changeSalary() here   (1 point)
			// 'empResult' contains the employee whose 'salary' is to be changed.
			// 'salary_input' contains the new salary of the employee.
			// Call the function with appropriate arguments.
			changeSalary(empResult, salary_input);

			cout << endl << "Salary changed!" << endl << endl;
		}
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// No implementation needed here, however it may be helpful to review this function
Employee* searchEmployee(string name_input)
{

	Container* tempList = list;			// work on a copy of 'list'

	while (tempList != NULL)			// parse till end of list
	{
		if (tempList->emp->getName() == name_input)
		{
			return tempList->emp;	// return the employee if found
		}

		tempList = tempList->next;		// parse the list
	}

	return NULL;						// return NULL if employee not found in list
}

// Q3b: Define Friend Function changeSalary()  (3 points)
// Define the function changeSalary()that is declared in employee.h file.
// This function sets the new 'salary' of the employee. The employee object and new salary is to be passed as function arguments.
// Use 'd' display option after using 'c' option to verify.
// You will need to implement add() and displayList() before you test this function.

void changeSalary(Employee* employee, double salary_input)
{
	//This function sets the new salary of the employee from user input
	employee->salary = salary_input;
}

// Q4: addEmployee  (7 points)
// This function is used to add a new employee to the global linked list 'list'. You may add the new employee to head or tail of the list. (Sample solution adds to tail)
// empType 'type' can be Nontechnical or technical. You will need to use the function argument �type� to determine which constructor to use to create new employee node.
// For example, if the user enters type as 'technical', then you need to use Technical class and constructor to create new employee node and add it to the list.
// NOTE: In executeAction(), searchEmployee() is called before this function. Therefore no need to check here if the employee exists in the list.
// See how this fucntion is called in case 'a' of executeAction()

void addEmployee(string name_input, double salary_input, empType type)
{
	Container* tempList = list;				// work on a copy of 'list'
	Container* newListType = new Container();

	//If the type == nontechnical, it will add the employee as a nontechnical type along with the information given. 
	if (type == nontechnical)
	{
		newListType->emp = new Nontechnical(name_input, salary_input, type);
	//Else if the type == technical, it will add the employee as a technical type along with the information given. 
	} else {
		newListType->emp = new Technical(name_input, salary_input, type);
	}

	//Initializaing the list type as NULL. 
	newListType->next = NULL;

	//If the type == NULL, it will add the employee type along with the information given.
	if (list == NULL)
	{
		list = newListType;
		return;
	} //While it != NULL, it will go on with the list and add the employee. 
	while (tempList->next != NULL)
	{
		tempList = tempList->next;
	}
	tempList->next = newListType;
}

// Q5: displayList	(4 points)
// This function displays the list of employee and their details (name, salary, employee type)
// Parse the list and use the class member function to display the employee info.
// See expected output in the question file.
void displayList()
{
	Container* tempList = list;			// work on a copy of 'list'

	//If the list == NULL, a message will prompt stating that the list is empty. 
	if (list == NULL)
	{ 
		cout << endl << "List is empty!" << endl << endl;
	}

	//While loop for if the list != NULL, the list will then go through and add and display the employee information.
	while (tempList != NULL)
	{
		tempList->emp->displayEmployee();
		tempList = tempList->next;
	}
}

// Q6: save  (7 points)
// Save the linked list of employees to a file list.txt using ofstream.
// You will need to save the number of employees in linked list. That will help in load() when reading the file.
// One format to store is:
// <no. of employees>
// <Employee1 name>
// <Employee1 salary>
// <Employee1 type>
// <Employee2 name>
// <Employee2 salary>
// <Employee2 type>
// and so on..
// You may store the list in another format if you wish. You need to read the file in load () the same way that it is saved in save().
// This function is called when exiting the program (end of main() ).
// Hint: You may want to cast the enum �empType� to an int before writing it to the file.


void save(string fileName)
{
	//Initializing variables
	Container* tempList = list;
	int count = 0;
	
	//While loop to count the number of containers within the list
	while (tempList != NULL) 
	{
		tempList = tempList->next;
		count++;
	}

	//ofstream to open file and read it
	ofstream employeeFile;
	employeeFile.open(fileName);

	//If the file is open, then the list will be ran through and displayed. 
	if (employeeFile.is_open())
	{
		tempList = list;
		employeeFile << count;

		//While loop for if the list != NULL, then the employee will be added and displayed with the information below. 
		while (tempList != NULL)
		{
			employeeFile << tempList->emp->getName() << endl;
			employeeFile << tempList->emp->getSalary() << endl;
			employeeFile << (int)tempList->emp->getEmpType() << endl;
			tempList = tempList->next;
		}
		employeeFile.close(); //Close the file.
	}
}

// Q7: load (7 points)
// Load the linked list of employees from the file using ifstream.
// You will need to create the linked list in the same order that is was saved to the file in save().
// First, read the number of employees saved in the file.
// Then, for every employee you will need to create a new Employee node depending on employee type. You may add the employee to head or tail of the list. 
// Hint: If you casted the enum 'empType' to an int, you will need to cast it back to 'empType' when making the employee node.
// This function is called at the beginning of main().

void load(string fileName)
{
	//Initializing variables
	ifstream employeeFile;
	employeeFile.open(fileName);

	//If the file is open, then the 
	if (employeeFile.is_open())
	{
		//Initializing variables
		int type_int = 0, count = 0;
		string name_read, temp;
		double salary_read = 0;
		empType type_read;
		Container* listType = list;
		employeeFile >> count;

		//For loop for getting and displaying employeee info in the file
		for (int i = 0; i < count; i++)
		{
			Container* newListType = new Container();
			std::getline(employeeFile, name_read);
			std::getline(employeeFile, temp);
			salary_read = stod(temp);
			std::getline(employeeFile, temp);
			type_int = stoi(temp);
			type_read = (empType)type_int;

			//If statement for creating new node for employee on employee type 
			if (type_read == nontechnical)
			{
				newListType->emp = new Nontechnical(name_read, salary_read, type_read);
			} else {
				newListType->emp = new Technical(name_read, salary_read, type_read);
			}

			//Initalizing the list memeber as null
			newListType->next = NULL;

			//If the list == NULL, the list will be added to the head of the list
			if (list == NULL)
			{
				newListType->next = list;
				list = newListType;
			//Else is the list will be parsed through and add the list type member employee added to the tail of the list
			} else {
				listType = list;
				while (listType->next != NULL)
				{
					listType = listType->next;
				}
				listType->next = newListType;
			}
		}
		employeeFile.close(); //Close the file
	}
}
//End of program