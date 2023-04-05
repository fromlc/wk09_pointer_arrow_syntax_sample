//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Mileage Plan assignment key	   
//------------------------------------------------------------------------------
// app_utfile.cpp : file utility functions
//
// References: 
//      http://www.cplusplus.com/doc/tutorial/files/
//      http://www.cplusplus.com/reference/istream/istream/get/
//
//------------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Car.h" 
#include "app_utfile.h" 

//-----------------------------------------------------------
// local function prototypes
//-----------------------------------------------------------

int getColumnCount(std::string& str);


//-----------------------------------------------------------
// openFile()
// 
// returns valid input file stream reference or exits app
//-----------------------------------------------------------
std::ifstream openFile(const std::string& fileName)
{
    try
    {
        // allocate new ifstream instance, open file with char* name
        return std::ifstream(fileName.c_str());
    }
    // File may not exist in the folder or another problem 
    catch (std::ifstream::failure& e)
    {
        std::cout << "Could not open file " << fileName << ".\n";
        std::cout << "Error message: " << e.what() << std::endl;
        exit(FILE_OPEN_ERROR);
    }
}


//-----------------------------------------------------------
// getFileData() : fill-in passed vector 
// 
// returns number of lines read from .csv file
//-----------------------------------------------------------
int getFileData(std::ifstream& f, std::vector<Car>& vCarData)
{
    int lineCount = 0;
    std::string str("");

    // first line is header row, not counted
    getline(f, str);

    // check for empty file
    if (!str.size())
        return 0;

    // set up inner for loop
    int colCount = getColumnCount(str);
    int delimPos = 0;

    // line by line
    while (!f.fail() && !f.eof())
    {
        getline(f, str);
        lineCount++;

        // set up data read loop
        int startPos = 0;
        std::string s("");
        std::vector<std::string> v;

        // read data column strings into vector
        for (int i = 0; i < colCount; i++)
        {
            delimPos = str.find(CHAR_DELIMITER, delimPos);

            if (delimPos > 0)
                s = str.substr(startPos, delimPos - startPos);
            else if (delimPos < 0)
                s = str.substr(startPos, str.size() - startPos);

            v.push_back(s);

            delimPos++;
            startPos = delimPos;
        }

        // set data fields for caller's next vector element (one per line)
        Car carLine;
        carLine.setYear(v[0]);
        carLine.setMake(v[1]);
        carLine.setModel(v[2]);
        try
        {
            carLine.setMpg(stof(v[3]));
        }
        catch (...)
        {
            carLine.setMpg(1);
        }

        // add this Car instance to caller's vector 
        vCarData.push_back(carLine);
    }

    return lineCount;
}

//-----------------------------------------------------------
// getColumnCount()
// 
// calc number of delimited columns
//-----------------------------------------------------------
int getColumnCount(std::string& str)
{
    int count = 0;
    std::size_t pos = 0;

    do 
    {
        pos = str.find(CHAR_DELIMITER, pos);
        count++;
    // advance pos past this delimiter after comparison
    } while (pos++ != std::string::npos);

    return count;
}

//-----------------------------------------------------------
// errorExit() : display error message and exits app
//-----------------------------------------------------------
void errorExit(const std::string& str, int errorCode)
{
    std::cerr << "Error " << errorCode 
        << " with file " << str << ".\n";

    std::cerr << "Exiting app." << str << '\n';
    //system("pause");

    exit(errorCode);
}