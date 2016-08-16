#ifndef _OR_H_
#define _OR_H_

#include "Connector.h"

class Or: public Connector {
    private:

    public:
        Or {}; 
        Or(Base* l, Base* r) {
            left = l;
            right = r;
        }
        bool execute() {
            
        }
        void display() {
            cout << "||";
        }
}; 
#endif 
