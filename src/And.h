#ifndef _AND_H_
#define _AND_H_

#include "Connector.h"

class And: public Connector {
    private:

    public:
        And() {}; 
        
        And(Base* l, Base* r) {
            left = l;
            right = r;
        }
        
        virtual bool execute() {
           
        }
        
        void display() {
            cout << "&&";
        }
}; 
#endif 
