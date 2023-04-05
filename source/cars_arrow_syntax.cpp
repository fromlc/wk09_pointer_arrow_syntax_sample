//------------------------------------------------------------------------------
// cars_arrow_syntax.cpp 
//
// Demos pointer arrow syntax with 
//	- Car class
//	- Engine class aggregated by Car
//	- EngineSpecs class aggregated by Engine
// 
// Demos freeing dynamic (heap) memory with delete operator.
//	- Local (stack) instance variables are deleted automatically -
//	  the destructor gets invoked when they go out of scope.
//    If a class instance allocates heap memory, delete it in
//	  the destructor.
//  
//	- Every time you allocate memory with the new operator, 
//	  you should use the delete operator to free that memory.
// 
//	- Exception: when an app terminates, the OS (usually, *not always*)
//	  reclaims all heap memory the app allocated. Windows reclaims
//	  heap memory, Linux distros generally reclaim app memory, but
//	  you should not rely on the OS to prevent memory leaks! Use a
//	  small test driver to allocate a large amount of memory, then
//    run the driver alongside a system memory monitor like Windows
//	  Task Manager to make sure heap memory is reclaimed when the 
//	  driver terminates.
//	  
//	- Best practice: after you delete a pointer, set its value to nullptr.
//	  For example:
// 
//		Car* pCar = new Car;
//		// ... work with pCar data ...
//		delete pCar;
//		pCar = nullptr;
//------------------------------------------------------------------------------
#include "Car.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void demoLocalCar();
void displayCar(Car*);
void displayEngineSpecs(Car*);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// causes destructor invocation
	demoLocalCar();

	Car* pVette = new Car("Chevy", "Corvette", "427 Big Block");
	displayCar(pVette);

	// must manually invoke destructor for memory allocated with new operator
	cout << "freeing pVette memory with delete operator\n";
	delete pVette;
	pVette = nullptr;

	Car* pRx7 = new Car("Mazda", "Rx7", "1.3L Wankel Twin Turbo");
	displayCar(pRx7);
	displayEngineSpecs(pRx7);

	cout << "did NOT delete pRx7 memory - memory leak!\n";

	cout << "\nType any key to continue...";
	cin.get();

	return 0;
}

//------------------------------------------------------------------------------
// local Car instance automatically invokes destructor on going out of scope
//------------------------------------------------------------------------------
void demoLocalCar() {

	cout << "demoLocalCar():\n";

	Car vwGTI("Volkswagen", "Mk7 GTI", "2.0L TSI EA888 turbo");
	cout << "vwGTI is a local instance variable on the stack\n";
	cout << "vwGTI memory will be deleted when demoLocalCar() returns\n";

	// use dot syntax to access public instance data and functions
	cout << "Engine type is " << *vwGTI.getEngineType() << '\n';

	// pass address 
	displayCar(&vwGTI);

	cout << "demoLocalCar() returning to main()\n";
}

//------------------------------------------------------------------------------
// display a Car's make, model, and engine type
//------------------------------------------------------------------------------
void displayCar(Car* pCar) {

	cout << "\ndisplayCar(): " << *pCar->getMake() << ' '
		<< *pCar->getModel() << ' '
		<< *pCar->getEngineType() << '\n';
}

//------------------------------------------------------------------------------
// display a Car's Egine's redline RPMs and top speed
//------------------------------------------------------------------------------
void displayEngineSpecs(Car* pCar) {

	cout << "Top speed " << pCar->pEngine->pSpecs->topspeed << " MPH\n";
	cout << "Redlines at " << pCar->pEngine->pSpecs->redline << "RPM\n";
}

