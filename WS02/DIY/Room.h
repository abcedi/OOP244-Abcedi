#ifndef SENECA_ROOM_H
#define SENECA_ROOM_H
#include "Guest.h"
namespace seneca {
	struct Room {
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest* m_guests;
	};
	// sets the Room by allocating a dynamic array of guests and setting the room number
	// (no validation is done for room number)
	void set(Room& room, int numberOfGuests, const char* roomNumber);

	// Prints the room number and names of the guests in the following lines with four
	// spaces of indentaion
	// See correct_output.txt for the exact format
	void print(const Room& room);

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room);

	// vacates the room by dallocating all the memory used.
	void vacate(Room& room);
}
#endif // !SENECA_ROOM_H