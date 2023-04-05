//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Mileage Plan assignment key	   
//------------------------------------------------------------------------------
// app_utfile.h : file utilities
//------------------------------------------------------------------------------
#pragma once
#ifndef APP_UTFILE_H
#define APP_UTFILE_H

#include <string>
#include <vector>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------

// data file column delimiter
constexpr char CHAR_DELIMITER = ',';

// file error codes
constexpr int FILE_OPEN_ERROR  = 1;
constexpr int FILE_IO_ERROR    = 2;
constexpr int BAD_FORMAT_ERROR = 3;

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

int getFileData(std::ifstream& f, std::vector<Car>& vCarData);
std::ifstream openFile(const std::string& fileName);
void errorExit(const std::string& str, int errorCode);

#endif // !APP_UTFILE_H
