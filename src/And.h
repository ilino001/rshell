#ifndef _AND_H_
#define _AND_H_

#include "Connector.h"

class And: public Connector {
    public:
        //constructors 
        And() : Connector() {}; 
        And(Base* l, Base* r) : Connector(l, r) {} 
        
        //executes right child once left child is completed 
        //returns true if both children have been executed 
        //returns false if otherwise 
        virtual bool execute(int child, int parent) {
            if (left->execute(child, parent)) {
                if (right->execute(child, parent)) {
                    return true; 
                }
                
                else {
                    return false; 
                }
            }
            
            else {
                return false; 
            }
        } 
}; 
#endif 