#ifndef PARSECMD_H
#define PARSECMD_H

#include <iostream>
#include <sstream> 
#include <vector> 
#include <string> 
#include <cstring> 

using namespace std; 

//uses all files 
#include "Base.h"
#include "Command.h" 
#include "Connector.h"
#include "Precedence.h"


class Parse_Cmd { 
    public: 
        //constructor 
        Parse_Cmd() {};
        
        //constructor that passes in stringstream 
            //to input each char that is being passed in 
        Base* parse(std::stringstream &input, Base* v = 0) {
            
            //iterates 
            string line; 
            std::vector<string> command_list; 
            int curr_status = -1; 
            Base* pre_counter = 0; 
            
            while (input >> line) {
                if (line.at(0) == '(') {
                    line = line.substr(1); 
                    int num_predence = 1; 
                    char c; 
                    bool inside_quotes = false; 
                    
                    while ( (num_predence > 0)) {
                        if (!(input.get(c))) {
                            cout << "--> "; 
                            string temp; 
                            string space = " "; 
                            getline (cin, temp); 
                            temp = space + temp; 
                            input.str(temp); 
                            input.clear();
                            c = input.get(); 
                        }
                        
                        if (c == '"') {
                            inside_quotes = true; 
                        }
                        
                        else if (c == '(' && !inside_quotes) {
                            ++num_predence; 
                        }
                        
                        else if (c == ')' && !inside_quotes) { 
                            --num_predence; 
                        }
                        line += c; 
                        
                    }
                    line = line.substr(0, line.size() - 1); 
                    stringstream output(line); 
                }
                else {
                    bool is_comment = false; 
                    for (unsigned i = 0; i < line.size(); ++i) {
                        if(line.at(i) == '#') {
                            line = line.substr(0, i); 
                            is_comment = true; 
                        }
                    }
                    if (is_comment) {
                        break; 
                    }
                }
                
                if (line.at(line.size() - 1) == ';') {

                    curr_status = another; 
                    command_list.push_back(line.substr(0, line.size() - 1)); 
                    break; 
                }
                
                // look for || in string line
                else if (strcmp(line.c_str(), "||") == 0) {
                    
                    curr_status = fails; 
                    break; 
                }
                
                // look for && in string line
                else if (strcmp(line.c_str(), "&&") == 0) {
                    
                    curr_status = works; 
                    break; 
                }
                
                command_list.push_back(line);
            }
            
            char** argvs = new char*[command_list.size() + 1]; 
            for (unsigned int i = 0; i < line.size(); ++ i) {
                argvs[i] = new char[command_list.at(i).size() + 1]; 
                strcpy(argvs[i], command_list.at(i).c_str()); 
            }
            argvs[line.size()] = 0; 
            
            Base* temp; 
            if (pre_counter == 0) {
                temp = new Command(argvs); 
            }
            else {
                temp = pre_counter; 
            }
           
            if (v == 0) {
                v = temp; 
            }
            
            // else {
            //     v->Right(temp); 
            // }
            
            // if (curr_status == -1) {
            //     return v; 
            // }
            
            // else {
            //     Base* new_connector = new Connector((Status)curr_status); 
            //     new_connector->Left(v); 
            //     v = new_connector; 
            //     return parse(input, v); 
            // }
            
        }
};
#endif 