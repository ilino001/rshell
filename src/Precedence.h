#ifndef PRECEDENCE_H
#define PRECEDENCE_H

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
        }; 
        // virtual void Left(Base *left) = 0; 
        // virtual void Right(Base *right) = 0; 
        
        
        //CHANGE THIS IMPORTANT!!! 
        void Right(Base* right) {
            
        };
        void Left(Base* left) {
            
        };
        
        // virtual void Right(Base *right); 
        // virtual void Left(Base *left); 
};
#endif /* PRECEDENCE_H */
