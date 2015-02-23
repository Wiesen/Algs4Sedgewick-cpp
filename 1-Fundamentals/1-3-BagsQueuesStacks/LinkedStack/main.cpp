#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedstack.h"

//!!!1 First: write the API and test code
int main()
{
    //!!!2 Remember how to open input file in C++
    std::ifstream fin("hamlet.txt");
    std::string strDash = "-", strLine, strWord;
    LinkedStack<std::string> strStack;
    //!!!3 Get a line from the input file
    while(getline(fin, strLine)){
        //!!!4 Object stringstream is bound to a string
        std::istringstream strIn(strLine);
        while(strIn >> strWord){
            if(strWord != strDash)
                strStack.push(strWord);
            else if(!strStack.isEmpty())
                std::cout << strStack.pop() << ' ';
        }

    }
    std::cout << "( " << strStack.size() << " left in the stack )\n";

    fin.close();
}
