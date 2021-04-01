// CSE240 Spring 2021 HW8
// Makenna Kidd
// Write the compiler used: Visual Studio

// READ BEFORE YOU START:
// You are given a partially completed program which consist of a class 'Book' defined in book.h
// The definitions of class member functions are to be filled in book.cpp (this file).
// hw08q1.c creates an array of objects 'b[]' and uses a menu driven program to add a book, display book info, 
// sort the book list and to find the book with the longest title among the books whose bookType contain a specific substring.
// You should start completing the program from from Q1. Question numbers are given around line 24.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.

// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****

#include "book.h"
#include <iostream>
#include <string.h>

using namespace std;

// Q1 Book (2 points)
// Book() constructor assigns the following default values to class data members
// title: The Alchemist
// ID: 0
// aisle: 101
// BookType: Fiction
Book::Book()
{
	// enter code here

	title: "The Alchemist";
	ID: "0";
	aisle: "101";
	BookType: "Fiction";

}

// Q2 (18 points)
// 2 points for each function

// Define all the class member functions.
// While defining member functions, note that these functions will be called using 
// a 'Book' object which will represent one book.
// Eg-  Book b[10]; creates 10 Book objects
//		b[2].setAisle(202); will set 3rd book's aisle number to 202.

// setTitle assigns 'title_input' to class data member 'title'
void Book::setTitle(string title_input) 
{
	// enter code here

	title = title_input;

}

// setID assigns id_input to class data member 'ID'
void Book::setID(int id_input) 
{
	// enter code here

	ID = id_input;

}

// setAisle assigns aisle_input to class data member 'aisle'
void Book::setAisle(int aisle_input) 
{
	// enter code here

	aisle = aisle_input;

}

// setBookType assigns bookType_input to class data member 'bookType'
void Book::setBookType(string bookType_input) 
{
	// enter code here

	bookType = bookType_input;

}

// displayBook displays the title, ID, aisle and bookType of the book
// See expected output in question file.
void Book::displayBook()
{
	// enter code here
	
	//Print out book details of book
	cout << " Title: " << title << endl;
	cout << " ID: " << ID << endl;
	cout << " Aisle: " << aisle << endl;
	cout << " Book Type: " << bookType << endl;

}

// getTitle returns the class data member 'title'.
string Book::getTitle() 
{
	// enter code here

	return title;

}

// getID returns the class data member 'ID'.
int Book::getID() 
{
	// enter code here

	return ID;

}

// getAisle returns the class data member 'aisle'.
int Book::getAisle() 
{
	// enter code here

	return aisle;

}

// getBookType returns the class data member 'bookType'.
string Book::getBookType() 
{
	// enter code here

	return bookType;

}