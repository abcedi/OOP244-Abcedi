#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include "Assessment.h"

using namespace seneca;
using namespace std;

namespace seneca {
	// Reads one integer from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(int& value, FILE* fptr) { 
		int i = fscanf(fptr, "%d,", &value); // read the integer
		return i == 1; // return true if it was successful, otherwise, it will return false
	}
	
	// Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(double& value, FILE* fptr) {
		int i = fscanf(fptr, "%lf,", &value); // read the double
		return i == 1; // return true if it was successful, otherwise, it will return false
	}
	
	/*Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr and returns true if it was successful, otherwise, 
	it will return false

	Use the following format in the fscanf to accomplish this:
	",%60[^\n]\n"

	V1.1 correction
	(Changed the argument name in the following read function form asm to assess; asm is a C keyword and cannot be used as an variable name)*/
	bool read(char* cstr, FILE* fptr) {
		int i = fscanf(fptr, "%60[^\n]\n", cstr); // read the cstring
		return i == 1; // return true if it was successful, otherwise, it will return false
	}
	
	/*First, it will try to read a double value for the mark and a string for the title into a temporary local double variable and a 60 - character lone cString(+1 for null).

	If the read is successful, it will then allocate a dynamic double and a dynamic cString to the exact size of the read cstring from the file into the fields of the assess 
	structure(assess.m_mark and assess.m_title) and copies the values into them.
	In this case, the function will return true, otherwise, it will return false with no memory allocation.*/
	bool read(Assessment& assess, FILE* fptr) {
		double tempMark; 
		char tempTitle[61] = { 0 }; // initialize the array to 0

		if (fscanf(fptr, "%lf,%60[^\n]\n", &tempMark, tempTitle) == 2) { // read the mark and the title
			tempTitle[60] = '\0'; // set the last element to null
			assess.m_mark = new (nothrow) double(tempMark); // allocate memory for the dynamic double

			assess.m_title = new (nothrow) char[strlen(tempTitle) + 1]; // allocate memory for the dynamic cString
			if (!assess.m_mark || !assess.m_title) { // if it fails, return false
				delete assess.m_mark;
				delete[] assess.m_title;
				assess.m_mark = nullptr;
				assess.m_title = nullptr;
				return false;
			}
			strcpy(assess.m_title, tempTitle); // copy the title into the dynamic cString
			return true;
		}

		return false;
	}
	
	//This function will receive a reference of a dynamic Assessment array and its size.The function then will delete the dynamic Assessment array as follows :

	//The dynamic array will be deleted by first going through each element of the Assessment array in a loop, deleting the dynamic double and the dynamic cString of all 
	//Assessment elements and then it will delete the array itself.
	void freeMem(Assessment*& aptr, int size) {
		for (int i = 0; i < size; i++) { // delete the dynamic double and the dynamic cString of all Assessment elements
			delete aptr[i].m_mark;
			aptr[i].m_mark = nullptr;
			delete aptr[i].m_title;
			aptr[i].m_title = nullptr;
		}
		delete[] aptr; // delete the array itself
		aptr = nullptr; // set the pointer to nullptr
	}
	
	/*This read function receives a reference of an Assessment pointer(to hold a dynamic array) and a file pointer from which it will read the assessment records into a 
	newly allocated dynamic array.

	The function will first read one integer which is the number of upcoming records to read.

	Then it will allocate a dynamic array of Assessments in the aptr pointer reference.After allocating the memory, in a loop, it will read each record of the file into 
	the Assessment elements(use the proper read overload for this).This loop should stop either if the number of reads reaches the number of elements or if the read function fails.

	When the loop is done compare the number of reads to the number of elements of the array.If the number is not a match, free the Memory of the dynamic array(freeMem) 
	and return zero, otherwise, return the size of the array.*/
	int read(Assessment*& aptr, FILE* fptr) {
		int i = 0;
		int cnt = 0;
		int size = 0;
		if (!read(size, fptr)) { // read the number of records
			return 0; // if it fails, return 0
		}

		aptr = new (nothrow) Assessment[size]; // allocate memory for the array
		if (!aptr) { // if it fails, return 0
			return 0;
		}

		for (i = 0; i < size; i++) { // read the records
			if (read(aptr[i], fptr)) { // if it fails, return 0
				cnt++; // increment the counter
			}
			else {
				freeMem(aptr, i); // if it fails, free the memory and return 0
				return 0;
			}

		}

		if (cnt != size) { // if the number of records read is not equal to the number of records
			freeMem(aptr, size); // free the memory and return 0
			return 0; 
		}
		else {
			return size; // return the number of records
		}
	
	}
	
}