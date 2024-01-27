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
		int i = fscanf(fptr, "%d,", &value);
		return i == 1;
	}
	
	// Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(double& value, FILE* fptr) {
		int i = fscanf(fptr, "%lf,", &value);
		return i == 1;
	}
	
	/*Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr and returns true if it was successful, otherwise, it will return false

	Use the following format in the fscanf to accomplish this:
	",%60[^\n]\n"

	V1.1 correction
	(Changed the argument name in the following read function form asm to assess; asm is a C keyword and cannot be used as an variable name)*/
	bool read(char* cstr, FILE* fptr) {
		int i = fscanf(fptr, "%60[^\n]\n", cstr);
		return i == 1;
	}
	
	/*First, it will try to read a double value for the mark and a string for the title into a temporary local double variable and a 60 - character lone cString(+1 for null).

	If the read is successful, it will then allocate a dynamic double and a dynamic cString to the exact size of the read cstring from the file into the fields of the assess structure(assess.m_mark and assess.m_title) and copies the values into them.
	In this case, the function will return true, otherwise, it will return false with no memory allocation.*/
	bool read(Assessment& assess, FILE* fptr) {

	}
	
	//This function will receive a reference of a dynamic Assessment array and its size.The function then will delete the dynamic Assessment array as follows :

	//The dynamic array will be deleted by first going through each element of the Assessment array in a loop, deleting the dynamic double and the dynamic cString of all Assessment elements and then it will delete the array itself.
	void freeMem(Assessment*& aptr, int size) {
		for (int i = 0; i < size; i++) {
			delete aptr[i].m_mark;
			delete aptr[i].m_title;
		}
		delete[] aptr;
	
	}
	
	/*This read function receives a reference of an Assessment pointer(to hold a dynamic array) and a file pointer from which it will read the assessment records into a newly allocated dynamic array.

	The function will first read one integer which is the number of upcoming records to read.

	Then it will allocate a dynamic array of Assessments in the aptr pointer reference.After allocating the memory, in a loop, it will read each record of the file into the Assessment elements(use the proper read overload for this).This loop should stop either if the number of reads reaches the number of elements or if the read function fails.

	When the loop is done compare the number of reads to the number of elements of the array.If the number is not a match, free the Memory of the dynamic array(freeMem) and return zero, otherwise, return the size of the array.*/
	int read(Assessment*& aptr, FILE* fptr) {
		int i = 0;
		int size = 0;
		int cnt = 0;
		read(size, fptr);
		aptr = new Assessment[size];
		for (i = 0; i < size; i++) {
			if (read(aptr[i], fptr)) {
				cnt++;
			}
		}
		if (cnt != size) {
			freeMem(aptr, size);
			return 0;
		}
		else {
			return size;
		}
	
	}
	
}