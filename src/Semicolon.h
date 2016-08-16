#ifndef _SEMICOLON_H_
#define _SEMICOLON_H_

#include "Connector.h"

class Semicolon: public Connector {
    private:

    public:
        Semicolon {}
        Semicolon(Base l, Base* r) {
            left = l;
            right = r;
        }
        bool execute() {
            
        }
        void display() {
            cout << ";";
        }
}; 
#endif 
