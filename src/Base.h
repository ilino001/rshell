#ifndef _BASE_H_
#define _BASE_H_

class Base {
    // private:
        // std::list<Base*> tree; 
    public:
        Base() {} 
        virtual bool execute(int child, int parent) = 0;
        //virtual void display() = 0;
        // void add(Base* element) {
        //     tree.push_back(element);
        // }
        // void remove(Base* element) {  
        //     tree.remove(element);   
        // }    
};  
#endif 
             