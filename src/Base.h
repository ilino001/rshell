#ifndef BASE_H
#define BASE_H

class Base {
    public: 
        Base() {}; 
        
        //execute specific function 
        virtual int execute() = 0; 
        
        //only connector uses left and right 
        virtual void Left(Base *left) = 0; 
        virtual void Right(Base *right) = 0;
        virtual ~Base() {};
}; 
#endif 