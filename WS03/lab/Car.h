#ifndef SENECA_CAR_H
#define SENECA_CAR_H
namespace seneca {
	class Car {
		char m_licensePlate[8]; // Ontarios license plate is 7 characters long plus the null terminator
		char* m_makeModel;
		char* m_serviceDesc;
		double m_cost;
	

	public:
		Car();
		~Car();
		bool isEmpty() const;
		void setEmpty();
		void deallocateMemory();
		void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
		void display() const;
	};
}
#endif // !SENECA_CAR_H