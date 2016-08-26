#ifndef _PRECEDENCE_H_
#define _PRECEDENCE_H_

#include "Base.h"

class Precedence : public Base {
    private: 
        Base *p; 
    
    public: 
        //constructor 
        Precedence() : Base() {}; 
        
        //constructor that takes in command as a parameter 
        Precedence(Base *command) {
            p = command; 
        }; 
        
        //takes Base p and runs the command 
        int execute() {
            return p->execute(); 
        } 
        // virtual void Left(Base *left) = 0; 
        // virtual void Right(Base *right) = 0; 
};
#endif 