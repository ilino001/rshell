#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_

#include "Base.h"

class Connector: public Base {
    protected:
        //left and right child 
        Base* left;
        Base* right;
    public:
        //sets left and right default to NULl 
        Connector() {
            left = NULL;
            right = NULL; 
        }
        //sets parameters to left and right children 
        Connector(Base *l, Base *r) {
            left = l; 
            right = l; 
        }
        virtual bool execute(int child, int parent) = 0;
}; 
#endif 