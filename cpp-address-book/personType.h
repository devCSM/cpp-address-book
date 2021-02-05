//	Writen by: Robin D. Budde
//	Date: Monday, November 26, 2018
/*Description: 
*/

#ifndef personType_H
#define personType_H

#include <iostream>
#include <string>

using namespace std;

class personType
{
public:
	void print() const
		// Function to output the first and last name
	{
		cout << firstName << " " << lastName;
	}

	void setName(string first, string last)
		// Function to set the firstName and lastName
	{
		firstName = first;
		lastName = last;
	}

	string getFirstName() const
		// Function to return the first name
	{
		return firstName;
	}

	string getLastName() const
		// Function to return the last name
	{
		return lastName;
	}

	personType()
		// default constructor
	{
		firstName = "Turk";
		lastName = "Turkleton";
	}

	personType(string first, string last)
		// constructor with parameters;
	{
		firstName = first;
		lastName = last;
	}

protected:
	string firstName;
	string lastName;
};


#endif