#ifndef _CONNECTOR_H
#define _CONNECTOR_H

#include "Base.h" 

class Connector : public Base {
    private: 
        Base *left; 
        Base *right; 
    public:
        //constructors, sets left and right to NULL  
        Connector() : Base() {
            left = NULL; 
            right = NULL; 
        }
        
        //constructors that take in parameters left and right 
        void Left(Base *l) {
            left = l;
        }
        
        void Right(Base *r) {
            right = r; 
        }
        
        //executes its children 
        int execute() {
            //executes left then right 
            int execution = left->execute(); 
            if (execution == 0) {
                execution = right->execute(); 
            }
            
            else {
                execution == right->execute(); 
            }
            return execution; 
            
        }
        
        // call destructor 
        ~Connector()
        {
            delete left;
            delete right;
        }
        
};
#endif 