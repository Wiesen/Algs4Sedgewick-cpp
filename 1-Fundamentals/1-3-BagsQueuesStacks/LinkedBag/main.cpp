/**
 *  @file   main.cpp
 *  @author Wiesen Yang
 *  @date   14 July 2015
 *  @remark This code is for the implementation and test client for LinkedBag in C++ template. 
            It read a file containing several numbers whose type is double, and then count the sum of them.
 *  @note
***/

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include "linkedbag.h"

int main()
{
    // Init
    std::ifstream fin("number.txt");
    LinkedBag<double> numberBag;
    std::string strLine;
    // Main loop
    while(getline(fin, strLine)){
        double number;
        std::istringstream strIn(strLine);
        while(strIn >> number)
            numberBag.add(number);
    }
    // Calculate
    int num = numberBag.size();
    double sum = 0.0;
    for(double x: numberBag)
        sum += x;
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}

// Correct output
/****************/
// Sum: 10.6
