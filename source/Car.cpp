//------------------------------------------------------------------------------
// Car.cpp : class definition file
//------------------------------------------------------------------------------
#include "Car.h"

#define DEBUG       // comment to disable verbose mode

#ifdef DEBUG
#include <iostream>
using std::cout;
#endif

using std::string;

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
Car::Car() : Car("make", "model", "etype") { }

//------------------------------------------------------------------------------
// overload constructor copies string data
//------------------------------------------------------------------------------
Car::Car(string _make, string _model, string _etype) : 
make(_make), model(_model) { 

    this->pEngine = new Engine(_etype);
}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
Car::~Car() { 

#ifdef DEBUG
    cout << "destructor: " << this->model << '\n';
#endif

    delete pEngine; 
}

//------------------------------------------------------------------------------
// return reference to make string
//------------------------------------------------------------------------------
string* Car::getMake() { return &(this->make); }

//------------------------------------------------------------------------------
// return reference to model string
//------------------------------------------------------------------------------
string* Car::getModel() { return &(this->model); }

//------------------------------------------------------------------------------
// return reference to Engine etype string
//------------------------------------------------------------------------------
string* Car::getEngineType() { return &(this->pEngine->eType); }
