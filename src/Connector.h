#ifndef _CONNECTOR_H
#define _CONNECTOR_H

#include "Base.h" 

//enum works similar to a boolean type 
enum Status {works, fails, another}; 

class Connector : public Base {
    private: 
        Base *left; 
        Base *right; 
        Status s; 
    public:
    
        //constructors, sets left and right to NULL  
        Connector() : Base() {
            left = NULL; 
            right = NULL; 
        }
        
        //takes in a type status 
        Connector(Status st) {
            s = st; 
        }
        
        //constructor, takes in base left, right, and status 
        Connector(Base *l, Base* r, Status st) {
            left = l; 
            right = r; 
            s = st; 
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
            //left will always execute 
                //therefore right will execute thereafter     
            int execution = left->execute(); 
            if (execution == 0 && s == works) {
                execution = right->execute(); 
            }
        
            else {
                execution = right->execute(); 
            }
            return execution; 
            
        }
  
        
};
#endif 