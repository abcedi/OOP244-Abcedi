#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace seneca;

namespace seneca {
	
	Car::Car(){ // default constructor
		setEmpty();
	}

	Car::~Car(){ // destructor
		deallocateMemory();
	}

	bool Car::isEmpty() const{ // returns true if the object is in a safe empty state
		return m_makeModel == nullptr || m_serviceDesc == nullptr || strlen(m_makeModel) == 0 || strlen(m_serviceDesc) == 0;
	}

	void Car::setEmpty(){ // sets the object to a safe empty state
		m_licensePlate[0] = '\0';
		m_makeModel = nullptr;
		m_serviceDesc = nullptr;
		m_cost = 0;
	}

	void Car::deallocateMemory(){ // deallocates memory that was dynamically allocated
		delete[] m_makeModel;
		delete[] m_serviceDesc;
		setEmpty();
	}

	void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost){ // sets the object to a safe empty state, then sets the object to the values of the parameters
		deallocateMemory();
		if (plateNo != nullptr && strlen(plateNo) > 0 && carMakeModel != nullptr && strlen(carMakeModel) > 0 && serviceDesc != nullptr && strlen(serviceDesc) > 0){
			strncpy(m_licensePlate, plateNo, 8);
			m_licensePlate[8] = '\0';
			m_makeModel = new char[strlen(carMakeModel) + 1];
			strcpy(m_makeModel, carMakeModel);
			m_serviceDesc = new char[strlen(serviceDesc) + 1];
			strcpy(m_serviceDesc, serviceDesc);
			m_cost = serviceCost;
		}
		else{
			setEmpty();
		}
	}

	void Car::display() const { // displays the object
		
		if (!isEmpty()) {
			int dollars = int(m_cost);
			int cents = int((m_cost - dollars) * 100 + 0.5);
			cout << setw(15) << left << "License Plate: " << setw(20) << right << (isEmpty() ? "" : m_licensePlate) << endl;
			cout << setw(15) << left << "Model: " << setw(20) << right << (isEmpty() ? "" : m_makeModel) << endl;
			cout << setw(15) << left << "Service Name: " << setw(20) << right << (isEmpty() ? "" : m_serviceDesc) << endl;
			cout << setw(15) << left << "Service Cost: " << setw(17) << right << dollars << '.' << (cents < 10 ? "0" : "") << cents << endl;
		}
	}
	
}