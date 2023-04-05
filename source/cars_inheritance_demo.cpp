//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Class inheritance demo	   
//------------------------------------------------------------------------------
// cars_inheritance_demo.cpp 
//
//	- Uses these classes:
//		Car, base class
//		ElectricCar, derived class
//------------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Car.h"
#include "ElectricCar.h"
#include "Vehicle.h"

// This app does not using namespace std;

//------------------------------------------------------------------------------
// main() : entry point
//------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	ElectricCar* pEC1 = new ElectricCar;
	ElectricCar* pEC2 = new ElectricCar("2022", "Toyota", "Prius");
	pEC2->setChargePct(10);

	// Class method redefinition demo
	// which method is called? Base class? Derived class?
	pEC2->setPoweredBy();

	// This won't work!
	//pEC2->mpg;
	// Access Car from ElectricCar definition code

	// Declare a local variable of type Car (an instance of the Car class)
	Car dreamCar;
	
	// Class method redefinition demo
	// which method is called? Base class? Derived class?
	dreamCar.setPoweredBy();

	std::string make, model, year, color;

	// Vehicle is our base class. 
	// You don't usually instantiate the base class, but you can.
	Vehicle foo;

	// Class method redefinition demo
	// which method is called? Base class? Derived class?
	foo.setPoweredBy();

	// this is a "polymorphic" vector..
	std::vector<Vehicle> vv;

	// .. because vector vv can have Vehicle, Car, and ElectricCar elements
	vv.push_back(foo);
	vv.push_back(dreamCar);
	vv.push_back(*pEC2);

	// Display app banner text with app .exe filename 
	std::cout << "App filename: " << argv[0] << "\n\n";

	// Get info for our Car class instance 
	std::cout << "What's your dream car?\n";
	std::cout << "Year: ";
	std::cin >> year;
	std::cout << "Make: ";
	std::cin >> make;
	std::cout << "Model: ";
	std::cin >> model;
	std::cout << "Color: ";
	std::cin >> color;
	std::cout << std::endl;

	// Set the member data of Car class instance 
	dreamCar.setMake(make);
	dreamCar.setModel(model);
	dreamCar.setYear(year);
	dreamCar.setColor(color);

	// Display the user's dream car
	std::cout << "A " << dreamCar.getColor() << " "
			<< dreamCar.getYear() << " "
			<< dreamCar.getMake() << " "
			<< dreamCar.getModel() << " would be awesome!";
	std::cout << std::endl;

	system("pause");

	return 0;
}