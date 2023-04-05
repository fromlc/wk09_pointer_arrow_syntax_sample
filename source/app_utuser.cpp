//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Mileage Plan assignment key	   
//------------------------------------------------------------------------------
// app_utuser.h : user interaction utility functions
//------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "app_utuser.h"

//------------------------------------------------------------------------------
// getInput() : get app specific input from user
//------------------------------------------------------------------------------
void getInput(int& tripMiles, float& gasPrice)
{
    std::cout << "Enter trip length in miles: ";
    std::cin >> tripMiles;

    std::cout << "Enter fuel price in gallons: ";
    std::cin >> gasPrice;

    std::cout << std::endl;
}

//------------------------------------------------------------------------------
// userCommand()
//------------------------------------------------------------------------------
char userCommand()
{
    std::string input;
    getline(std::cin, input);

    // grab first char, ignore the rest
    char cmd = input.at(0);

    if (cmd < 'A' || cmd > 'Z')
        return CMD_QUIT;

    return toupper(cmd);
}