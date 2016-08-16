#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Base.h"
#include <iostream> 
#include <string> 

class Command: public Base {
    private:
        std::string comm;
        
    public:
        Command(std::string c) {
            comm = c;
        }
        
        bool execute() {

            return false;
        }
        void display() {
            std::cout << comm;
        }
}; 
#endif 
