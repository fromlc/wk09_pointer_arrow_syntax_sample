//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Class inheritance demo	   
//------------------------------------------------------------------------------
// ElectricCar.h : class declaration/definition file
//------------------------------------------------------------------------------
#pragma once
#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car
{
private:
   int chargePct;
   friend class Car;

public:
   ElectricCar() { this->chargePct = 0; }

   ElectricCar(std::string year, std::string make, std::string model)
   {
       this->year = year;
       this->make = make;
       this->model = model;
       this->color = "unpainted";
       this->chargePct = 0;
   }

   // setters
   void setChargePct(int chg) { chargePct = chg; }
   
   // derived class redefinition of base class method
   void setPoweredBy()
   {
       this->power = "Electric battery";
   }

   // getters
   int getChargePct() const { return chargePct; }
};

#endif