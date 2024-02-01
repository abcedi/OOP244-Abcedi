#define _CRT_SECURE_NO_WARNINGS
#include "Guest.h"
#include <cstring>
#include <iostream>
using namespace std;
using namespace seneca;

namespace seneca {
	// clears the input buffer
	void clearInputBuffer() {
		std::cin.ignore(10000, '\n');
	}

	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest& guest, const char* first, const char* last, int age) {
		if (first == nullptr || last == nullptr || strlen(first) == 0 || strlen(last) == 0) {
			guest.m_firstName = nullptr;
			guest.m_lastName = nullptr;
			return;
		}
		else {
			if (guest.m_firstName) {
				delete[] guest.m_firstName;
			}
			if (guest.m_lastName) {
				delete[] guest.m_lastName;
			}
			guest.m_firstName = new char[strlen(first) + 1];
			strcpy(guest.m_firstName, first);
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_lastName, last);
		}
		guest.m_adult = age >= 18;
	}
	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest& guest) {
		if (guest.m_firstName && guest.m_lastName) {
			cout << guest.m_firstName << " " << guest.m_lastName;
			if (!guest.m_adult) {
				cout << "(Child)";
			}
			cout << endl;
		}
		else {
			cout << "Vacated!" << endl;
		}
	}
	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest& guest) {
		char first[41], last[41];
		int age;

		cout << "Name: ";
		cin.getline(first, 40, '\n');

		cout << "Lastname: ";
		cin.getline(last, 40, '\n');

		cout << "Age: ";
		cin >> age;

		clearInputBuffer();

		set(guest, first, last, age);
	}
	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest) {
		delete[] guest.m_firstName;
		delete[] guest.m_lastName;
		guest.m_firstName = nullptr;
		guest.m_lastName = nullptr;
	}
}