//------------------------------------------------------------------------------
// Car.h : class declaration file
//------------------------------------------------------------------------------
#pragma once

#include <string>
using std::string;

class Engine {
public:
    string eType;

    // constructor
    Engine(string _eType) : eType(_eType) { }
};

class Car {
public:
    string make;
    string model;
    Engine* pEngine;

    // constructors
    Car();
    Car(string _make, string _model, string _etype);

    // destructor
    ~Car();

    string* getMake();
    string* getModel();
    string* getEngineType();
};
