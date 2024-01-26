#include <iostream>
using namespace std;
void line(char fill = '-', size_t len = 75);
/*
ints:
char
short
int
long
long long

real:
float
double
long double
*/
int main()
{
	bool ok{ }; // {} is default which is 0 or = false
	if (ok) {
		cout << "This will no happen!" << endl;

	}
	ok = true;
	if (ok) {
		cout << "This will happen!" << endl;

	}
	ok = 234;
	cout << ok << endl;

	line('+', 40);
	line('=');
	line( );

	return 0;
}

void line(char fill, size_t len) {
	for (size_t i = 0; i < len; i++) {
		cout << fill;
	}
	cout << endl;
}