#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H
#include "Car.h"

namespace seneca {
	class Customer {
		int m_id = 0;
		char* m_name;
		const Car* m_car;
	

	public:
		Customer();
		~Customer();
		bool isEmpty() const;
		void setEmpty();
		void deallocateMemory();
		void set(int customerId, const char* name, const Car* car);
		void display() const;
		const Car& car() const;
	};
}
#endif // !SENECA_CUSTOMER_H