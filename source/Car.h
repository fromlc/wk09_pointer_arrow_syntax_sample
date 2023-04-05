//------------------------------------------------------------------------------
// Car.h : class declaration and definition file
//------------------------------------------------------------------------------
#pragma once

#define DEBUG       // comment to disable verbose mode

#ifdef DEBUG
#include <iostream>
using std::cout;
#endif

#include <string>
using std::string;

//------------------------------------------------------------------------------
// EngineSpecs
//------------------------------------------------------------------------------
class EngineSpecs {
public:
    int redline;
    int topspeed;

    EngineSpecs() : redline(8000), topspeed(180) { }
};

//------------------------------------------------------------------------------
// Engine
//------------------------------------------------------------------------------
class Engine {
public:
    string eType;
    EngineSpecs* pSpecs;

    // constructor
    Engine(string _eType) { 

        this->eType = _eType;
        pSpecs = new EngineSpecs;
    }

    // destructor
    ~Engine() {

#ifdef DEBUG
        cout << "Engine destructor: " << this->eType << '\n';
#endif

        delete pSpecs;
    }
};

class Car {
public:
    string make;
    string model;
    Engine* pEngine;

    //--------------------------------------------------------------------------
    // constructor
    //--------------------------------------------------------------------------
    Car() : Car("make", "model", "etype") { }

    //--------------------------------------------------------------------------
    // overload constructor copies string data
    //--------------------------------------------------------------------------
    Car(string _make, string _model, string _etype) :
        make(_make), model(_model) {

        this->pEngine = new Engine(_etype);
    }

    //--------------------------------------------------------------------------
    // destructor
    //--------------------------------------------------------------------------
    ~Car() {

#ifdef DEBUG
        cout << "Car destructor: " << this->model << '\n';
#endif

        delete pEngine;
    }

    //--------------------------------------------------------------------------
    // return pointer to make string
    //--------------------------------------------------------------------------
    string* getMake() { return &(this->make); }

    //--------------------------------------------------------------------------
    // return pointer to model string
    //--------------------------------------------------------------------------
    string* getModel() { return &(this->model); }

    //--------------------------------------------------------------------------
    // return pointer to Engine's etype string
    //--------------------------------------------------------------------------
    string* getEngineType() { return &(this->pEngine->eType); }
};
