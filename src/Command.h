#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Base.h"
#include <iostream> 
#include <string> 
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>

class Command: public Base {
    protected: 
        std::string command;
    public:
        //constructors 
        Command() {} 
        Command(std::string com) {
            command = com;
        }
        
        //uses fork in system calls 
        virtual bool execute(int child, int parent) {
            
            pid_t pid = fork();     //creating child process 
            
            //fork fails, output error 
            if (pid == -1) { 
                perror("ERROR: fork() failed, cannot continue\n"); 
                exit(1); 
            }
            
            //child process 
            else if (pid == 0){
                //uses dup2 for 
                if (dup2(child, 0) == -1){
                    perror("ERROR: dup2 failed, cannot continue\n"); 
                    return false;
                }
                
                if (dup2(parent, 1) == -1){
                    perror("ERROR: dup2 failed, cannot continue\n"); 
                    return false;
                }
                
                
            }
            
            //parent process 
            else if (pid > 0) {
                //waitpid 
                int verify;
                
              if (waitpid(pid, &verify, 0) == -1){
                  perror("Waiting...");
              }  
              if(WEXITSTATUS(verify) != 0){
                  return false;
              }
                
            }
            
            //fork fails, causes error 
            else {    
                perror("ERROR: cannot continue\n"); 
                exit(1); 
            }
            
            return false;
        }

}; 
#endif 