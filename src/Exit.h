#ifndef __EXIT_H__
#define __EXIT_H__

class Exit: public Command {
  
  public:
  
    //constructor 
     Exit() {} 
     
     //if execute is called, exit 
     bool execute(int child, int parent){
         exit(0); 
     } 
  
};
#endif