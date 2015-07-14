#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedqueue.h"

int main()
{
    // Init
    std::ifstream fin("tobe.txt");
    std::string strDash = "-", strLine, strWord;
    LinkedQueue<std::string> strQueue;
    // Main loop to prase the file
    while(getline(fin, strLine)){           // Get a new line
        std::istringstream strIn(strLine);
        while(strIn >> strWord){            // Get a new word
            if(strWord != strDash)
                strQueue.enqueue(strWord);
            else if(!strQueue.isEmpty())
                std::cout << strQueue.dequeue() << ' ';
        }
    }
    
    std::cout << " ( " << strQueue.size() << " left in the queue )\n";
    return 0;
}
