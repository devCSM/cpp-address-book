//	Writen by: Robin D. Budde
//	Date: Monday, November 26, 2018
/*Description: 
*/

#ifndef extPersonType_H
#define extPersonType_H

#include <iostream>
#include <string>

#include "personType.h"
#include "dateType.h"
#include "addressType.h"

using namespace std;

class extPersonType: public personType, public addressType, public dateType
{
public:
	void print() const
	{
		cout << lastName << ", " << firstName << " " << streetAddress << " " << city
			<< " " << state << " " << zipCode << phoneNumber << " " << relationshipType << "\n";
	}

	void setRelationship(bool newIsFamily, bool newIsFriend, bool newIsCoWorker)
		// data member to classify the person as a family member, friend, or business associate
	{
		isFamilyMember = newIsFamily;
		isFriend = newIsFriend;
		isBusinessAssociate = newIsCoWorker;

		if (isFamilyMember == true) relationshipType = "family member";
		else if (isFriend == true) relationshipType = "friend";
		else if (isBusinessAssociate == true) relationshipType = "business associate";
		else relationshipType = "it's complicated";
	}
	void setRelationship(string newRelationShipType)
		// overload
	{
		relationshipType = newRelationShipType;
	}

	void setPhoneNumber(string newPhone)
		// data member to store the phone number
	{
		//cout << "newPhone: " << newPhone << "\n";
		phoneNumber = newPhone;
		//cout << "phoneNumber: " << phoneNumber << " " << "\n";
	}

	string getRelationshipType() const
		// function to return the relationship type
	{
		return relationshipType;
	}

	string getPhoneNumber() const
	{
		//cout << "return phone number: " << phoneNumber;
		return phoneNumber;
	}

	extPersonType()
		// default constructor
	{
		isFamilyMember = 0;
		isFriend = 0;
		isBusinessAssociate = 0;
		relationshipType = "it's complicated";
		phoneNumber = "1234567890";
	}

	extPersonType(bool newIsFamilyMember, bool newIsFriend, bool newIsBusinessAssociate,
		string newRelationshipType, string newPhoneNumber)
		//constructor with parameters
	{
		isFamilyMember = newIsFamilyMember;
		isFriend = newIsFriend;
		isBusinessAssociate = newIsBusinessAssociate;
		relationshipType = newRelationshipType;
		phoneNumber = newPhoneNumber;
	}

protected:
	bool isFamilyMember;
	bool isFriend;
	bool isBusinessAssociate;
	string relationshipType;
	string phoneNumber;
};


#endif