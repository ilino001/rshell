#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Base.h"
#include <iostream>
#include <string>
#include <cstdlib> //exit
#include <cstring> //strcmp 
#include <sys/stat.h> //struct stat 
#include <sys/types.h> //S_IFDIR 
#include <unistd.h> //fork() and execvp() 
#include <sys/wait.h>
#include <stdio.h> //wait 

class Command : public Base {
    private: 
        //instead of the main taking in the argument value, 
            //the command file takes it in instead 
        char** argv; 
    public: 
        //constructors 
        Command() : Base() {} 
        
        //constructor that takes in the arguments 
        Command(char** argvs) {
            this->argv = argvs; 
        }
    
      
    
        int execute() {
            //initalizing begin to equal first argument value 
            std::string begin = argv[0]; 
            std::string flag = argv[1]; 
        
            //if user calls exit, exit immediately 
            if (begin == "exit") { 
                exit(0); 
            }
            
            //if it's test, the next argument value will have the following flags: 
                //-e, -f, -d 
            else if (begin == "test" || begin == "[") {
                int flag_num = 0; 
                int counter = 1;
                
                //if flag matches either flags, increment counter 
                    //and update file num 
                if (flag == "-e"){
                    ++counter; 
                }
                
                else if (flag == "-f"){
                    flag_num = 1; 
                    ++counter; 
                }
                
                else if (flag == "-d"){
                    flag_num = 2; 
                    ++counter; 
                }
                struct stat buffer;
                
                //if it is not a file 
                if (stat(argv[counter], &buffer) != 0) {
                    std::cout << "(False)\n"; 
                    return 0; 
                }
                //if statement checks if the directory exists 
                else if (buffer.st_mode & S_IFDIR) {
        
                    //if it's the flags -e or -d 
                    if (flag == "-e" || flag == "-d") {
                        std::cout << "(True)\n"; 
                        return 0; 
                    }
                    
                    else {
                        std::cout << "(False)\n"; 
                        return 1; 
                    }
                }
            
                else {
                    if (flag == "-f" || flag == "-e") {
                        std::cout << "(True)\n"; 
                        return 0; 
                    }

                    else {
                        std::cout << "(False)\n"; 
                        return 1; 
                    }
                }
                return 0; 
                
            }
            int pid, execution;  
            pid = fork(); 
            
            if (pid == 0) {
                //int exiting =  execvp(argv[0], argv); 
                int exiting =  execvp(argv[0], this->argv); 
                exit(exiting); 
            }
            
            else {
                std::cout << "fork() failed, cannot continue\n"; 
                exit(1); 
            }
            wait(&execution);
            return execution; 
        
        }; 
        virtual void Left(Base *left); 
        virtual void Right(Base *right); 
};
#endif 