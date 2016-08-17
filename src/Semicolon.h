#ifndef _SEMICOLON_H_
#define _SEMICOLON_H_

#include "Connector.h"
#include <iostream> 

class Semicolon: public Connector {
    public:
        //constructors 
        Semicolon() : Connector(){}
        Semicolon(Base* l, Base* r) : Connector(l, r) {}
            
        //executes both child, regardless of other 
        //returns true if right has been executed successfully 
        //otherwise returns false 
        virtual bool execute(int child, int parent) { 
            (left->execute(child, parent)); 
            
            if (right->execute(child, parent)) {
                return true; 
            }
            
            else {
                return false; 
            }
        }
}; 
#endif 