#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace seneca;

namespace seneca {
	Customer::Customer() { // default constructor
		setEmpty();
	}

	Customer::~Customer() { // destructor
		deallocateMemory();
	}

	bool Customer::isEmpty() const{ // check if the object is empty
		return m_name == nullptr || m_car == nullptr || strlen(m_name) == 0;
	}

	void Customer::setEmpty() { // set the object to empty state
		m_id = 0;
		m_name = nullptr;
		m_car = nullptr;
	}

	void Customer::deallocateMemory() { // deallocate memory
		delete[] m_name;
		m_name = nullptr;
	}

	void Customer::set(int customerId, const char* name, const Car* car){ // set the object to the values
		deallocateMemory();
		if (name != nullptr && strlen(name) > 0 && car != nullptr) {
			m_id = customerId;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_car = car;
		}
		else {
			setEmpty();
		}
	}

	void Customer::display() const { // displays the object
		if (!isEmpty()) {
			cout << setw(15) << left << "Customer ID: " << setw(20) << right << m_id << endl;
			cout << setw(15) << left << "First Name: " << setw(20) << right << m_name << endl;
			m_car->display();
		}
		else {
			cout << "Customer information is missing." << endl;
			
		}
	}

	const Car& Customer::car() const { // returns the car object
		return *m_car;
	}

}