/**
 *  @file   main.cpp
 *  @author Wiesen Yang
 *  @date   25 Feb 2015
 *  @remark This code is for the implementation and test client for ArrayStack in C++ template
 *  @note
***/

#include <iostream>
//! Class ifstream is in "fstream" header file
#include <fstream>
#include <sstream>
#include <string>
#include "arraystack.h"

int main()
{
    std::ifstream fin("hamlet.txt");
    const std::string strDash = "-";
    std::string strLine, strWord;

    ArrayStack<std::string> arrStack;
    while(getline(fin, strLine)){
        std::istringstream sin(strLine);
        while(sin >> strWord){
            if(strWord != strDash)
                arrStack.push(strWord);
            else if(!arrStack.isEmpty())
                std::cout << arrStack.pop() << ' ';
            // Print to observe the change of the size and capacity
            //std::cout << "size: " << arrStack.size()
            //          << "  cap:" << arrStack.capacity()
            //          << std::endl;
        }
    }
    std::cout << "( " << arrStack.size() << " left on stack )\n";
    return 0;
}
