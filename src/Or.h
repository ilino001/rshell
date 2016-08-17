#ifndef _OR_H_
#define _OR_H_

#include "Connector.h"

class Or: public Connector {
   public:
        //constructors 
        Or() : Connector() {} 
        Or(Base* l, Base* r) : Connector(l, r) {}
        
        // executes right if left cannot 
        //returns true if both have been executed successfully 
        //otherwise returns true 
        virtual bool execute(int child, int parent) {
           if (!left->execute(child, parent)) {
               if (right->execute(child, parent)) {
                   return true; 
               }
               
               else {
                   return false; 
               }
               return true; 
           }
        }
}; 
#endif 