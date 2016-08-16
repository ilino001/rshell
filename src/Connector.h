#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_

#include "Base.h"

class Connector: public Base {
    protected:
        Base* left;
        Base* right;
    public:
        Connector() {};
        virtual bool execute() = 0;
        virtual void display() = 0;
}; 

#endif 
