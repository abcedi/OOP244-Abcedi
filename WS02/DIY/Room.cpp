#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Room.h"
#include "Guest.h"

using namespace std;
using namespace seneca;
namespace seneca {
	// sets the Room by allocating a dynamic array of guests and setting the room number
	// (no validation is done for room number)
	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		int i;
		room.m_noOfGuests = numberOfGuests;
		strcpy(room.m_roomNumber, roomNumber);
		room.m_guests = new Guest[room.m_noOfGuests];
		for (i = 0; i < room.m_noOfGuests; i++) {
			room.m_guests[i].m_firstName = nullptr;
			room.m_guests[i].m_lastName = nullptr;
		}
	}

	// Prints the room number and names of the guests in the following lines with four
	// spaces of indentaion
	// See correct_output.txt for the exact format
	void print(const Room& room) {
		if (room.m_noOfGuests == 0) {
			cout << "Empty Room!" << endl;
		}
		else {
			cout << "Room Number: " << room.m_roomNumber << endl;
			for (int i = 0; i < room.m_noOfGuests; i++) {
				cout << "    ";
				seneca::print(room.m_guests[i]);
			}
		}
	}

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room) {
		cout << "Room number: ";
		cin >> room.m_roomNumber;
		cout << "Number of guests: ";
		cin >> room.m_noOfGuests;

		clearInputBuffer();

		delete[] room.m_guests;
		room.m_guests = new Guest[room.m_noOfGuests];
		for (int i = 0; i < room.m_noOfGuests; i++) {
			cout << i + 1 << ":" << endl;
			room.m_guests[i].m_firstName = nullptr;
			room.m_guests[i].m_lastName = nullptr;
			seneca::book(room.m_guests[i]);
		}
	}

	// vacates the room by dallocating all the memory used.
	void vacate(Room& room) {
		for (int i = 0; i < room.m_noOfGuests; i++) {
			seneca::vacate(room.m_guests[i]);
		}
		delete[] room.m_guests;
		room.m_guests = nullptr;
		room.m_noOfGuests = 0;
		room.m_roomNumber[0] = '\0';
	}
}