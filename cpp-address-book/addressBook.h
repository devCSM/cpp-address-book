//	Writen by: Robin D. Budde
//	Date: Monday, November 26, 2018
/*Description:
*/

#ifndef H_addressBook
#define H_addressBook

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "arrayListType.h"
#include "extPersonType.h"

using namespace std;

// template <class elemType>
// class addressBook : public arrayListType<extPersonType>
class addressBook // : public vector<extPersonType> // New
{
public:
	
	/*
	const arrayListType<elemType>& operator=
		(const arrayListType<elemType>&)
		// overloads the assignment operator
	{
		if (this != &otherList)		// avoid self-assignment
		{
			delete[] list;
			maxSize = otherList.maxSize;
			length = otherList.length;

			list = new elemType[maxSize];	// create the array
			assert(list != NULL);	// if unable to allocate memory space, 
									// terminate the program
			for (int i = 0; i < length; i++)
				list[i] = otherList.list[i];
		}

		return *this;
	}
	*/
	void loadData(string fileName)
		// funtion to get data from a file
	{
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
			// cout << "firstName: " << first << ", lastName: " << last << "\n";

			getline(ss, streetAddress, ',');
			myPerson.setStreetAddress(streetAddress); // set street address
			// cout << "street address: " << streetAddress << "\n";
			
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
			
			list[i] = myPerson;
			i++;
			//insertEnd(myPerson);
		}
			
		myFileStream.close();
	}

	void print()
		// function to print the entire phone book
	{
		for (int i = 0; i < length; i++)
		{
			cout << "\n"; 
			cout << "First Name: " << list[i].getFirstName() << "\n";
			cout << "Last Name: " << list[i].getLastName() << "\n";
			cout << "Phone Number: " << list[i].getPhoneNumber() << "\n";
			cout << "Address: " << "\n";
			cout << list[i].getStreetAddress() << "\n";
			cout << list[i].getCity() << ", " << list[i].getState() << " " << list[i].getZipCode() << "\n";
			cout << "Birthday: " << list[i].getMonth() << "/" << list[i].getDay() << "/" << list[i].getYear() << "\n";
			cout << "Relationship: " << list[i].getRelationshipType() << "\n";
			cout << "\n";
		}

	}

	void printByLastName(string newLast)
		// function to search by a last anme
	{
		for (int i = 0; i < length; i++)
		{

			if (list[i].getLastName() == newLast)
			{
				cout << "\n"; 
				cout << "First Name: " << list[i].getFirstName() << "\n";
				cout << "Last Name: " << list[i].getLastName() << "\n";
				cout << "\n";
			}
		}
	}

	
	
	
	void printByPerson(string newLast)
		// function to print the address, phone number, and date of birth (if it exists) of a given person
	{
		for (int i = 0; i < length; i++)
		{
			
			if (list[i].getLastName() == newLast)
			{
				cout << "\n"; 
				cout << "First Name: " << list[i].getFirstName() << "\n";
				cout << "Last Name: " << list[i].getLastName() << "\n";
				cout << "Phone Number: " << list[i].getPhoneNumber() << "\n";
				cout << "Address: " << "\n";
				cout << list[i].getStreetAddress() << "\n";
				cout << list[i].getCity() << ", " << list[i].getState() << " " << list[i].getZipCode() << "\n";
				cout << "Birthday: " << list[i].getMonth() << "/" << list[i].getDay() << "/" << list[i].getYear() << "\n";
				cout << "\n";
			}			
		}

	}

	void printByDateRange(int firstMonth, int secondMonth)
		// function to print the people whose birthdays are in a given month or between two given dates
	{
		for (int i = 0; i < length; i++)
		{

			if (list[i].getMonth() >= firstMonth && list[i].getMonth() <= secondMonth)
			{
				
				cout << "\n";
				cout << "First Name: " << list[i].getFirstName() << "\n";
				cout << "Last Name: " << list[i].getLastName() << "\n";
				cout << "Birthday: " << list[i].getMonth() << "/" << list[i].getDay() << "/" << list[i].getYear() << "\n";
				cout << "\n";
			}
		}
	}

	void printByRelationshipStatus(string relationshipStatus)
		// function to print the people whose relationship status is the same
	{
		for (int i = 0; i < length; i++)
		{

			if (list[i].getRelationshipType() == relationshipStatus)
			{
				cout << "\n";
				cout << "First Name: " << list[i].getFirstName() << "\n";
				cout << "Last Name: " << list[i].getLastName() << "\n";
				cout << "Relationship: " << list[i].getRelationshipType() << "\n";
				cout << "\n";
			}
		}
	}

	void printBetweenTwoNames(string name1, string name2)
		// function to print the people whose name is between two names
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i].getLastName()[0] >= toupper(name1[0]) && list[i].getLastName()[0] <= toupper(name2[0]))
			{
				cout << "\n"; 
				cout << "First Name: " << list[i].getFirstName() << "\n";
				cout << "Last Name: " << list[i].getLastName() << "\n";
				cout << "\n";
			}
		}
	}

	
	
	addressBook(int size) //: vector<extPersonType>(size)
		// constructor
	{
		
		vector<extPersonType> list(size);

		
		/*{
			if (size < 0)
			{
				cerr << "The array size must be positive. Creating "
					<< "an array of size 500. " << endl;

				maxSize = 500;
			}
			else
				maxSize = size;

			length = 0;

			list = new elemType[maxSize];
			assert(list != NULL);
		}*/
	}

protected:
	
	string line;
	extPersonType myPerson;
	string first, last;
	string streetAddress, city, state;
	string strZip, strDay, strMonth, strYear, strPhone, newStrPhone;
	int zipCode, day, month, year;
	int size = 500;
	
	unsigned long long int phone;
	string relationshipType;

	// new
	int maxSize, length;
	vector<extPersonType> list;
	
};
#endif