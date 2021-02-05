#ifndef arrayListType_H
#define arrayListType_H

#include <iostream>
#include <string>
//#include <stdio.h>
#include <assert.h>

using namespace std;

template <class elemType>
class arrayListType
{
public:

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

	bool isEmpty() const
		// function to determine whether the list is empty
	{
		return (length == 0);
	}

	bool isFull() const
		// function to determine whether the list is full
	{
		return (length == maxSize);
	}

	int listSize() const
		// function to determine the number of elements in the list
	{
		return length;
	}

	int maxListSize() const
		//function to determine the size of the list
	{
		return maxSize;
	}

	void print() const
		// function to output the elements of the list
	{
		for (int i = 0; i < length; i++)
			cout << list[i] << " ";
		
		cout << endl;
	}

	bool isItemAtEqual(int location, const elemType& item) const
		// function to determine whether the item is the same as the
		// item in the list at the position specified
	{
		return(list[location] == item);
	}

	void insertAt(int location, const elemType& insertItem)
		// function to instert an item in the list at the position specified by location
	{
		if (location < 0 || location >= maxSize)
			cerr << "The position of the item to be inserted "
			<< "is out of range" << endl;
		else
			if (length >= maxSize)	// list is full
				cer << "Cannot insert in a full list" << endl;
			else
			{
				for (int i = length; i > location; i--)
					list[i] = list[i - 1];	// move the elements down

				list[location] = insertItem; // insert the item in the specified position

				length++;	// increment the length
			}
	} // end insertAt

	void insertEnd(const elemType& insertItem)
		// funtion to insert an item at the end of the list
	{
		if (length >= maxSize)	// the list is full
			cerr << "Cannot insert in a full list" << endl;
		else
		{
			list[length] = insertItem;	// insert the item at the end
			length++;	// increment the length
		}
	} // end insertEnd
	
	void removeAt(int location)
		//funtion to remove the item from the list at the end position specified by location
	{
		if (location < 0 || location >= length)
			cerr << "The location of the item to be removed "
			<< "is out of range" << endl;
		else
		{
			for (int i = location; i < length - 1; i++)
				list[i] = list[i + 1];

			length--;
		}
	}// end removeAt

	void retrieveAt(int location, elemType& retItem) const
		// funtion to retrieve the element from the list at the position specified by location
	{
		if (location < 0 || location >= length)
			cerr << "The location of the itme to be retrieved is "
			<< "out of range." << endl;
		else
			retItem = list[location];
	}// end retrieveAt

	void replaceAt(int location, const elemType& repItem)
		// function to replace the elements in the list at the position specified by location
	{
		if (location < 0 || location >= length)
			cerr << "The location of the item to be replaced is "
			<< "out of range." << endl;
		else
			list[location] = repItem;
	}// end replaceAt

	void clearList()
		// function to remove all the elements from the list
	{
		length = 0;
	}// end clearList

	int seqSearch(const elemType& item)
		// function to search the list for a given item
	{
		int loc;
		bool found = false;

		for (loc = 0; loc < length; loc++)
			if (list[loc] == item)
			{
				found = true;
				break;
			}
		if (found)
			return loc;
		else
			return -1;
	}// end seqSearch

	void insert(const elemType& insertItem) const
		// function to insert the item specified by the parameter
	{
		int loc;

		if (length == 0)	// list is empty
			list[length++] = insertItem;	// insert the item and increment the length
		else if (length == maxSize)
			cerr << "Cannot insert in a full list." << endl;
		else
		{
			loc = seqSearch(insertItem);

			if (loc == -1)	// the item to be inserted does not exist in the list
				list[length++] = insertItem;
			else
				cerr << "the item to be inserted is already in "
				<< "the list. No duplicates are allowed." << endl;
		}
	}// end insert

	void remove(const elemType& removeItem)
		// function to remove an item from the list
	{
		int loc;

		if (length == 0)
			cerr << "Cannot delete from an empty list." << endl;
		else
		{
			loc = seqSearch(removeItem);

			if (loc != -1)
				removeAt(loc);
			else
				cout << "The item to be deleted is not in the list."
				<< endl;
		}
	}// end remove

	arrayListType(int size)
		// constructor
	{
		if (size < 0)
		{
			cerr << "The array size must be positive. Creating "
				<< "an array of size 100. " << endl;

			maxSize = 100;
		}
		else
			maxSize = size;

		length = 0;

		list = new elemType[maxSize];
		assert(list != NULL);
	}

	arrayListType(const arrayListType<elemType>& otherList)
		//copy constructor
	{
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new elemType[maxSize];	// create the array
		assert(list != NULL);			// terminate if unable to allocate 
										// memory space
		for (int j = 0; j < length; j++)
			list[j] = otherList.list[j];

	}// end of copy constructor

	~arrayListType()
		// deconstructor
	{
		delete[] list;
	}

protected:
	elemType * list;	// array to hold the list elements
	int length;			// to store the length of the list
	int maxSize;		// to store the mazimum size of the list
};


#endif