#ifndef PARSECMD_H
#define PARSECMD_H

#include <iostream>
#include <sstream> 
#include <vector> 
#include <string> 

using namespace std; 

//uses all files 
#include "Base.h"
#include "Command.h" 
#include "Connector.h"
#include "Precedence.h"

class Parse { 
    private: 
    public: 
        //constructor 
        Parse() {};
        Base* parse(std::stringstream &input, Base* v = 0) {
            std::vector<string> list; 
        }
        
};
#endif 