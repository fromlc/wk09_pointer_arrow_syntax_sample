//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Mileage Plan assignment key	   
//------------------------------------------------------------------------------
// Vehicle.cpp : class definition file
//------------------------------------------------------------------------------

#include "Vehicle.h"

//------------------------------------------------------------------------------
// constructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Vehicle() : default constructor
//------------------------------------------------------------------------------
Vehicle::Vehicle() {  }

//------------------------------------------------------------------------------
// setter methods
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// setYear() : sets value of member variable year to passed string
//------------------------------------------------------------------------------
void Vehicle::setYear(std::string year)
{
    // the "this pointer" points to this class instance
    this->year = year;
}

//------------------------------------------------------------------------------
// setMake() : copies passed string to member variable maker
//------------------------------------------------------------------------------
void Vehicle::setMake(std::string make)
{
    // the "this pointer" points to this class instance
    this->make = make;
}

//------------------------------------------------------------------------------
// setModel() : copies passed string to member variable model
//------------------------------------------------------------------------------
void Vehicle::setModel(std::string model)
{
    // the "this pointer" points to this class instance
    this->model = model;
}

//------------------------------------------------------------------------------
// setColor() : sets value of member variable color to passed string
//------------------------------------------------------------------------------
void Vehicle::setColor(std::string color)
{
    // the "this pointer" points to this class instance
    this->color = color;
}

//------------------------------------------------------------------------------
// setPoweredBy() : sets the value of member variable power
//------------------------------------------------------------------------------
void Vehicle::setPoweredBy()
{
    this->power = "Unknown";
}

//------------------------------------------------------------------------------
// getter methods
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// getYear() : returns a copy of the value of the member variable year
//------------------------------------------------------------------------------
std::string Vehicle::getYear() const
{
    return year;
}

//------------------------------------------------------------------------------
// getMaker() : returns a copy of the value of the member variable maker
//------------------------------------------------------------------------------
std::string Vehicle::getMake() const
{
    return make;
}

//------------------------------------------------------------------------------
// getModel() : returns a copy of the value of the member variable model
//------------------------------------------------------------------------------
std::string Vehicle::getModel() const
{
    return model;
}

//------------------------------------------------------------------------------
// getColor() : returns a copy of the value of the member variable color
//------------------------------------------------------------------------------
std::string Vehicle::getColor() const
{
    return color;
}

//------------------------------------------------------------------------------
// getPoweredBy() : returns a copy of the value of the member variable power
//------------------------------------------------------------------------------
std::string Vehicle::getPoweredBy() const
{
    return power;
}
