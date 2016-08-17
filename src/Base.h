#ifndef _BASE_H_
#define _BASE_H_

class Base {
    public:
        Base() {} 
        virtual bool execute(int child, int parent) = 0;
};  
#endif 
             