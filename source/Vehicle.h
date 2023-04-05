//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Class inheritance demo	   
//------------------------------------------------------------------------------
// Vehicle.h : class declaration file
//------------------------------------------------------------------------------
#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle
{
protected:
    std::string year;
    std::string make;
    std::string model;
    std::string color;
    std::string power;

public:
    Vehicle();

    // copy passed strings
    void setYear(std::string year);
    void setMake(std::string make);
    void setModel(std::string model);
    void setColor(std::string color);

    // return a copy of string member data
    std::string getYear() const;
    std::string getMake() const;
    std::string getModel() const;
    std::string getColor() const;
    std::string getPoweredBy() const;

    // base class method
    virtual void setPoweredBy();
};

#endif