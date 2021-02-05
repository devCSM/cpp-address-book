//	Writen by: Robin D. Budde
//	Date: Monday, November 26, 2018
/*Description: 
*/

#ifndef addressType_H
#define addressType_H

#include <iostream>
#include <string>

using namespace std;

class addressType 
{
public:

	void printAddress() const
		// Function to print the address
	{
		cout << streetAddress << ", " << city << ", " << state << " " << zipCode << "\n";
	}
	
	void setStreetAddress(string newAddress)
		// Fucntion to set the street address
	{
		streetAddress = newAddress;
	}

	void setCity(string newCity)
		// Function to set the city
	{
		city = newCity;
	}

	void setState(string newState)
		// Function to set the state
	{
		state = newState;
	}

	void setZip(int newZip)
		// Function to set the zip code
	{
		zipCode = newZip;
	}

	string getStreetAddress() const
		// Function to return the street address
	{
		return streetAddress;
	}

	string getCity() const
		// Function to return city
	{
		return city;
	}

	string getState() const
		// Function to return  the state
	{
		return state;
	}

	int getZipCode() const
		// Function to return the zip code
	{
		return zipCode;
	}

	addressType()
		// Default constructor
	{
		streetAddress = "1234 Mulberry Street";
		city = "Gotham";
		state = "TX";
		zipCode = 54321;
	}

	addressType(string newStreetAddress, string newCity, char newState, int newZipCode)
		// Constructor with paramaters
	{
		streetAddress = newStreetAddress;
		city = newCity;
		state = newState;
		zipCode = newZipCode;
	}

protected:
	// declare variables
	string streetAddress;
	string city;
	string state;
	int zipCode;
};

#endif
