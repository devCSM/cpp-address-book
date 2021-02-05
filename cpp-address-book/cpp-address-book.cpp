//	Writen by: Robin D. Budde
//	Date: Monday, November 26, 2018
/*  Description: implementation of address book with address book changed to a vector
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "addressType.h"
#include "personType.h"
#include "dateType.h"
#include "extPersonType.h"

using namespace std;

vector<extPersonType> addressBook(500);
int maxSize, length;

int userMenu()
{
	int choice;

	cout << "**********************************************" << "\n";
	cout << "1. Print full address book." << "\n";
	cout << "2. Search for person by last name." << "\n";
	cout << "3. Show address, ph#, DOB of a given person." << "\n";
	cout << "4. Search by birthday month." << "\n";
	cout << "5. Search between two last names." << "\n";
	cout << "6. Search by relationship type. " << "\n";
	cout << "7. Quit program." << "\n";
	cout << "**********************************************" << "\n";
	cout << ">> Choose an item from the menu > ";
	cin >> choice;
	cout << "\n";

	return choice;
}

void loadData(string fileName)
// funtion to get data from a file
{

	string line;
	extPersonType myPerson;
	string first, last;
	string streetAddress, city, state;
	string strZip, strDay, strMonth, strYear, strPhone, newStrPhone;
	int zipCode, day, month, year;

	unsigned long long int phone;
	string relationshipType;

	ifstream myFileStream(fileName);
	if (!myFileStream.is_open())
	{
		cerr << "File failed to open." << endl;
	}

	int i = 0;
	int areaCode = 0, exchange = 0, number = 0;

	while (getline(myFileStream, line))
	{
		stringstream ss(line);
		getline(ss, first, ',');
		getline(ss, last, ',');
		myPerson.setName(first, last); //set first and last name

		getline(ss, streetAddress, ',');
		myPerson.setStreetAddress(streetAddress); // set street address

		getline(ss, city, ',');
		myPerson.setCity(city); // set city

		getline(ss, state, ',');
		myPerson.setState(state);	// set the state

		getline(ss, strZip, ',');
		zipCode = stoi(strZip);
		myPerson.setZip(zipCode);	// set the zipcode

		getline(ss, strPhone, ',');
		phone = stoull(strPhone);
		number = phone % 10000;
		exchange = (phone / 10000) % 1000;
		areaCode = (phone - ((exchange * 10000) + number)) / 10000000;
		newStrPhone = "(" + to_string(areaCode) + ") " + to_string(exchange) + "-" + to_string(number);
		myPerson.setPhoneNumber(newStrPhone);	// set the phone number

		getline(ss, strYear, ',');
		year = stoi(strYear);
		getline(ss, strMonth, ',');
		month = stoi(strMonth);
		getline(ss, strDay, ',');
		day = stoi(strDay);
		myPerson.setDate(month, day, year); // set the birthday

		getline(ss, relationshipType);
		myPerson.setRelationship(relationshipType); // set the relationship type

		// print();
		addressBook[i] = myPerson;
		i++;
		
		length = i;
	}

	myFileStream.close();
}

void print()
// function to print the entire phone book
{
	for (int i = 0; i < length; i++)
	{
		cout << "\n";
		cout << "First Name: " << addressBook[i].getFirstName() << "\n";
		cout << "Last Name: " << addressBook[i].getLastName() << "\n";
		cout << "Phone Number: " << addressBook[i].getPhoneNumber() << "\n";
		cout << "Address: " << "\n";
		cout << addressBook[i].getStreetAddress() << "\n";
		cout << addressBook[i].getCity() << ", " << addressBook[i].getState() << " " << addressBook[i].getZipCode() << "\n";
		cout << "Birthday: " << addressBook[i].getMonth() << "/" << addressBook[i].getDay() << "/" << addressBook[i].getYear() << "\n";
		cout << "Relationship: " << addressBook[i].getRelationshipType() << "\n";
		cout << "\n";
	}

}

void printByLastName(string newLast)
// function to search by a last anme
{
	for (int i = 0; i < length; i++)
	{

		if (addressBook[i].getLastName() == newLast)
		{
			cout << "\n";
			cout << "First Name: " << addressBook[i].getFirstName() << "\n";
			cout << "Last Name: " << addressBook[i].getLastName() << "\n";
			cout << "\n";
		}
	}
}

void printByPerson(string newLast)
// function to print the address, phone number, and date of birth (if it exists) of a given person
{
	for (int i = 0; i < length; i++)
	{

		if (addressBook[i].getLastName() == newLast)
		{
			cout << "\n";
			cout << "First Name: " << addressBook[i].getFirstName() << "\n";
			cout << "Last Name: " << addressBook[i].getLastName() << "\n";
			cout << "Phone Number: " << addressBook[i].getPhoneNumber() << "\n";
			cout << "Address: " << "\n";
			cout << addressBook[i].getStreetAddress() << "\n";
			cout << addressBook[i].getCity() << ", " << addressBook[i].getState() << " " << addressBook[i].getZipCode() << "\n";
			cout << "Birthday: " << addressBook[i].getMonth() << "/" << addressBook[i].getDay() << "/" << addressBook[i].getYear() << "\n";
			cout << "\n";
		}
	}

}

void printByDateRange(int firstMonth, int secondMonth)
// function to print the people whose birthdays are in a given month or between two given dates
{
	for (int i = 0; i < length; i++)
	{

		if (addressBook[i].getMonth() >= firstMonth && addressBook[i].getMonth() <= secondMonth)
		{

			cout << "\n";
			cout << "First Name: " << addressBook[i].getFirstName() << "\n";
			cout << "Last Name: " << addressBook[i].getLastName() << "\n";
			cout << "Birthday: " << addressBook[i].getMonth() << "/" << addressBook[i].getDay() << "/" << addressBook[i].getYear() << "\n";
			cout << "\n";
		}
	}
}

void printByRelationshipStatus(string relationshipStatus)
// function to print the people whose relationship status is the same
{
	for (int i = 0; i < length; i++)
	{

		if (addressBook[i].getRelationshipType() == relationshipStatus)
		{
			cout << "\n";
			cout << "First Name: " << addressBook[i].getFirstName() << "\n";
			cout << "Last Name: " << addressBook[i].getLastName() << "\n";
			cout << "Relationship: " << addressBook[i].getRelationshipType() << "\n";
			cout << "\n";
		}
	}
}

void printBetweenTwoNames(string name1, string name2)
// function to print the people whose name is between two names
{
	for (int i = 0; i < length; i++)
	{
		if (addressBook[i].getLastName()[0] >= toupper(name1[0]) && addressBook[i].getLastName()[0] <= toupper(name2[0]))
		{
			cout << "\n";
			cout << "First Name: " << addressBook[i].getFirstName() << "\n";
			cout << "Last Name: " << addressBook[i].getLastName() << "\n";
			cout << "\n";
		}
	}
}

int main()
{
	loadData("addressBook.csv");

	int choice = 0;
	choice = userMenu();
	string lastName, name1, name2, relationship;
	int firstMonth, lastMonth;

	while (choice != 7)
	{
		switch (choice)
		{
		case 1: print();
			break;
		case 2:
		{
			cout << "Enter a last name to search for: ";
			cin >> lastName;
			printByLastName(lastName);
		}
			break;
		case 3: 
		{
			cout << "Enter a last name to search for: ";
			cin >> lastName;
			printByPerson(lastName);
		}
		break;
		case 4:
		{
			cout << "Enter two months to search between (e.g., 3 5): ";
			cin >> firstMonth >> lastMonth;
			printByDateRange(firstMonth, lastMonth);
		}
			break;
		case 5:
		{
			cout << "Enter two last names to compare (e.g., Anderson Smith) : ";
			cin >> name1 >> name2;
			printBetweenTwoNames(name1, name2);

		}
		break;
		case 6:
		{
			cout << "Enter a relationship to search by (e.g., family, friend, coworker) : ";
			cin >> relationship;
			printByRelationshipStatus(relationship);
		} 
		break;

		case 7:
		default:
			break;
		}

		choice = userMenu();
	}

	return 0;

}