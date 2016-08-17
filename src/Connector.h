#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_

#include "Base.h"

class Connector: public Base {
    protected:
        Base* left;
        Base* right;
    public:
        Connector() {
            left = NULL;
            right = NULL; 
        }
        Connector(Base *l, Base *r) {
            left = l; 
            right = l; 
        }
        virtual bool execute() = 0;
}; 
#endif 