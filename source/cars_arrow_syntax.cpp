//------------------------------------------------------------------------------
// cars_arrow_syntax.cpp 
//
// Demos pointer arrow syntax with 
//	- Car class
//	- Engine class aggregated by Car
//------------------------------------------------------------------------------
#include "Car.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void displayCar(Car*);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	Car* pVette = new Car("Chevy", "Corvette", "427 Big Block");
	displayCar(pVette);

	// must manually invoke destructor for memory allocated with new operator
	delete pVette;

	Car vwGTI("Volkswagen", "Mk7 GTI", "2.0L TSI EA888 turbo");
	displayCar(&vwGTI);

	cout << "\nType any key to continue...";
	cin.get();

	return 0;
}

//------------------------------------------------------------------------------
// display a Car's make, model, and engine type
//------------------------------------------------------------------------------
void displayCar(Car* pCar) {

	cout << '\n' << *pCar->getMake() << ' '
		<< *pCar->getModel() << ' '
		<< *pCar->getEngineType() << '\n';
}