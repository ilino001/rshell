#ifndef _BASE_H_
#define _BASE_H_
#include <vector>

class Base {
    private:
        std::list<Base*> tree; 
    public:
        Base() : tree(NULL); 
        virtual bool execute() = 0;
        virtual void display() = 0;
        void add(Base* element) {
            tree.push_back(element);
        }
        void remove(Base* element) {  
            tree.remove(element);   
        }    
};  
#endif 
             
